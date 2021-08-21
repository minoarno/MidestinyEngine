#include "MiniginPCH.h"
#pragma once
#include "InputManager.h"
#include "Commands.h"
#include "UIManager.h"
#include "Log.h"
#include "SceneManager.h"
#include "Scene.h"

dae::InputManager::~InputManager()
{
	for (auto& controllerCommands : m_ControllerCommands)
	{
		for (std::pair<const ControllerButton, dae::InputStruct>& c : controllerCommands.second)
		{
			delete c.second.pOnHold;
			c.second.pOnHold = nullptr;

			delete c.second.pOnPressDown;
			c.second.pOnPressDown = nullptr;

			delete c.second.pOnRelease;
			c.second.pOnRelease = nullptr;

		}
		controllerCommands.second.clear();
	}
	m_ControllerCommands.clear();

	for (auto& keyboardCommands : m_KeyboardCommands)
	{
		for (std::pair<const SDL_Scancode, dae::InputStruct>& c : keyboardCommands.second)
		{
			delete c.second.pOnHold;
			c.second.pOnHold = nullptr;

			delete c.second.pOnPressDown;
			c.second.pOnPressDown = nullptr;

			delete c.second.pOnRelease;
			c.second.pOnRelease = nullptr;
		}
		keyboardCommands.second.clear();
	}
}


bool dae::InputManager::ProcessInput()
{
	dae::Scene* pActiveScene = SceneManager::GetInstance().GetActiveScene().get();

	//DWORD state;
	SecureZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	if (!IsPressed(ControllerButton(m_CurrentState.Gamepad.wButtons)))
	{
		for (auto& c : m_ControllerCommands[pActiveScene])
		{
			if (c.second.wasPressedDownPreviousFrame == true)
			{
				c.second.wasPressedDownPreviousFrame = false;
				if (c.second.pOnRelease != nullptr)
				{
					c.second.pOnRelease->Execute();
				}
			}
		}
	}

	m_DidInputGet = false;
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			return false;
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (m_KeyboardCommands[pActiveScene].find(e.key.keysym.scancode) != m_KeyboardCommands[pActiveScene].end())
			{
				if (m_KeyboardCommands[pActiveScene][e.key.keysym.scancode].pOnPressDown != nullptr)
				{
					m_KeyboardCommands[pActiveScene][e.key.keysym.scancode].pOnPressDown->Execute();
				}
			}
		}
		if (e.type == SDL_KEYUP)
		{
			if (m_KeyboardCommands[pActiveScene].find(e.key.keysym.scancode) != m_KeyboardCommands[pActiveScene].end())
			{
				if (m_KeyboardCommands[pActiveScene][e.key.keysym.scancode].pOnRelease != nullptr)
				{
					m_KeyboardCommands[pActiveScene][e.key.keysym.scancode].pOnRelease->Execute();
				}
			}
		}
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			Uint32 mouseState = SDL_GetMouseState(&x, &y);
			if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) //left mouse button
			{
				UIManager::GetInstance().OnMouseDown(x, y);
			}
		}
		if (e.type == SDL_MOUSEBUTTONUP)
		{

		}
		for (auto& key : m_KeyboardCommands[pActiveScene])
		{
			if (key.first == e.key.keysym.scancode)
			{
				if (key.second.pOnHold != nullptr)
				{
					key.second.pOnHold->Execute();
				}
			}
		}

		if (m_KeyboardCommands[pActiveScene].find(e.key.keysym.scancode) != m_KeyboardCommands[pActiveScene].end())
		{

			m_KeyboardCommands[pActiveScene].at(e.key.keysym.scancode).pOnHold->Execute();

			if (m_KeyboardCommands[pActiveScene][e.key.keysym.scancode].pOnHold != nullptr)
			{
				m_KeyboardCommands[pActiveScene][e.key.keysym.scancode].pOnHold->Execute();
			}
		}
	}

	return true;
}

bool dae::InputManager::IsPressed(ControllerButton button)
{
	dae::Scene* pActiveScene = SceneManager::GetInstance().GetActiveScene().get();

	if (m_ControllerCommands[pActiveScene].find(button) != m_ControllerCommands[pActiveScene].end())
	{
		const bool previousState = m_ControllerCommands[pActiveScene].at(button).wasPressedDownPreviousFrame;
		if (previousState == false)
		{
			m_ControllerCommands[pActiveScene][button].wasPressedDownPreviousFrame = true;
			if (m_ControllerCommands[pActiveScene][button].pOnPressDown != nullptr)
			{
				m_ControllerCommands[pActiveScene][button].pOnPressDown->Execute();
			}
		}
		else
		{
			if (m_ControllerCommands[pActiveScene][button].pOnHold != nullptr)
			{
				m_ControllerCommands[pActiveScene].at(button).pOnHold->Execute();
			}
		}
		return true;
	}
	return false;
}

SDL_Event dae::InputManager::GetEvent()
{
	SDL_Event temp = m_Event;
	m_Event = SDL_Event{};
	return temp;
}

#pragma warning(push)
#pragma warning(disable : 26812)

void dae::InputManager::AddOnPressDown(ControllerButton controllerButton, Command* command, const Scene* pScene)
{
	if (m_ControllerCommands.find(pScene) == m_ControllerCommands.end())
	{
		std::map<dae::ControllerButton, dae::InputStruct> newMap = std::map<dae::ControllerButton, dae::InputStruct>();
		m_ControllerCommands.emplace(pScene, newMap);
	}

	if (m_ControllerCommands[pScene].find(controllerButton) == m_ControllerCommands[pScene].end())
	{
		InputStruct inputStruct{};
		inputStruct.pOnPressDown = command;
		m_ControllerCommands[pScene].emplace(controllerButton, inputStruct);
	}
	else
	{
		m_ControllerCommands[pScene][controllerButton].pOnPressDown = command;
	}
}

void dae::InputManager::AddOnPressDown(SDL_Scancode scanCode, Command* command, const Scene* pScene)
{
	if (m_KeyboardCommands.find(pScene) == m_KeyboardCommands.end())
	{
		std::map<SDL_Scancode, dae::InputStruct> newMap = std::map<SDL_Scancode, dae::InputStruct>();
		m_KeyboardCommands.emplace(pScene, newMap);
	}

	if (m_KeyboardCommands[pScene].find(scanCode) == m_KeyboardCommands[pScene].end())
	{
		InputStruct inputStruct{};
		inputStruct.pOnPressDown = command;
		m_KeyboardCommands[pScene].emplace(scanCode, inputStruct);
	}
	else
	{
		m_KeyboardCommands[pScene][scanCode].pOnPressDown = command;
	}
}

void dae::InputManager::AddOnHold(ControllerButton controllerButton, Command* command, const Scene* pScene)
{
	if (m_ControllerCommands.find(pScene) == m_ControllerCommands.end())
	{
		std::map<dae::ControllerButton, dae::InputStruct> newMap = std::map<dae::ControllerButton, dae::InputStruct>();
		m_ControllerCommands.emplace(pScene, newMap);
	}

	if (m_ControllerCommands[pScene].find(controllerButton) == m_ControllerCommands[pScene].end())
	{
		InputStruct inputStruct{};
		inputStruct.pOnHold = command;
		m_ControllerCommands[pScene].emplace(controllerButton, inputStruct);
	}
	else
	{
		m_ControllerCommands[pScene][controllerButton].pOnHold = command;
	}
}

void dae::InputManager::AddOnHold(SDL_Scancode scanCode, Command* command, const Scene* pScene)
{
	if (m_KeyboardCommands.find(pScene) == m_KeyboardCommands.end())
	{
		std::map<SDL_Scancode, dae::InputStruct> newMap = std::map<SDL_Scancode, dae::InputStruct>();
		m_KeyboardCommands.emplace(pScene, newMap);
	}

	if (m_KeyboardCommands[pScene].find(scanCode) == m_KeyboardCommands[pScene].end())
	{
		InputStruct inputStruct{};
		inputStruct.pOnHold = command;
		m_KeyboardCommands[pScene].emplace(scanCode, inputStruct);
	}
	else
	{
		m_KeyboardCommands[pScene][scanCode].pOnHold = command;
	}
}

void dae::InputManager::AddOnRelease(ControllerButton controllerButton, Command* command, const Scene* pScene)
{
	if (m_ControllerCommands.find(pScene) == m_ControllerCommands.end())
	{
		std::map<dae::ControllerButton, dae::InputStruct> newMap = std::map<dae::ControllerButton, dae::InputStruct>();
		m_ControllerCommands.emplace(pScene, newMap);
	}

	if (m_ControllerCommands[pScene].find(controllerButton) == m_ControllerCommands[pScene].end())
	{
		InputStruct inputStruct{};
		inputStruct.pOnRelease = command;
		m_ControllerCommands[pScene].emplace(controllerButton, inputStruct);
	}
	else
	{
		m_ControllerCommands[pScene][controllerButton].pOnRelease = command;
	}
}

void dae::InputManager::AddOnRelease(SDL_Scancode scanCode, Command* command, const Scene* pScene)
{
	if (m_KeyboardCommands.find(pScene) == m_KeyboardCommands.end())
	{
		std::map<SDL_Scancode, dae::InputStruct> newMap = std::map<SDL_Scancode, dae::InputStruct>();
		m_KeyboardCommands.emplace(pScene, newMap);
	}

	if (m_KeyboardCommands[pScene].find(scanCode) == m_KeyboardCommands[pScene].end())
	{
		InputStruct inputStruct{};
		inputStruct.pOnRelease = command;
		m_KeyboardCommands[pScene].emplace(scanCode, inputStruct);
	}
	else
	{
		m_KeyboardCommands[pScene][scanCode].pOnRelease = command;
	}
}
#pragma warning(pop)