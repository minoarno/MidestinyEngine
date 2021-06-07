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
		for (std::pair<ControllerButton, std::pair<bool, Command*>> c : controllerCommands.second)
		{
			delete c.second.second;
			c.second.second = nullptr;
		}
		controllerCommands.second.clear();
	}
	m_ControllerCommands.clear();

	for (auto& keyboardCommands : m_KeyboardCommands)
	{
		for (std::pair<SDL_Scancode, Command*> c : keyboardCommands.second)
		{
			delete c.second;
			c.second = nullptr;
		}
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
			if (c.second.first == true)
			{
				c.second.first = false;
				c.second.second->OnRelease();
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
				m_KeyboardCommands[pActiveScene].at(e.key.keysym.scancode)->OnPressDown();
			}
		}
		if (e.type == SDL_KEYUP)
		{
			if (m_KeyboardCommands[pActiveScene].find(e.key.keysym.scancode) != m_KeyboardCommands[pActiveScene].end())
			{
				m_KeyboardCommands[pActiveScene].at(e.key.keysym.scancode)->OnRelease();
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
				key.second->OnHold();
			}
		}

		if (m_KeyboardCommands[pActiveScene].find(e.key.keysym.scancode) != m_KeyboardCommands[pActiveScene].end())
		{
			m_KeyboardCommands[pActiveScene].at(e.key.keysym.scancode)->OnHold();
		}
	}

	return true;
}

bool dae::InputManager::IsPressed(ControllerButton button)
{
	dae::Scene* pActiveScene = SceneManager::GetInstance().GetActiveScene().get();


	if (m_ControllerCommands[pActiveScene].find(button) != m_ControllerCommands[pActiveScene].end())
	{
		const bool previousState = m_ControllerCommands[pActiveScene].at(button).first;
		if (previousState == false)
		{
			m_ControllerCommands[pActiveScene].at(button).first = true;
			m_ControllerCommands[pActiveScene].at(button).second->OnPressDown();
		}
		else
		{
			m_ControllerCommands[pActiveScene].at(button).second->OnHold();
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

void dae::InputManager::AddInput(ControllerButton controllerButton, Command* command,const Scene* pScene)
{
	
	if (m_ControllerCommands.find(pScene) == m_ControllerCommands.end())
	{
		std::map<dae::ControllerButton, std::pair<bool, Command*>> newMap = std::map<dae::ControllerButton, std::pair<bool, Command*>>();
		m_ControllerCommands.emplace(pScene, newMap);
	}
	m_ControllerCommands[pScene].emplace(controllerButton, std::make_pair(false, command));
}

#pragma warning(push)
#pragma warning(disable : 26812)
void dae::InputManager::AddInput(SDL_Scancode scanCode, Command* command,const Scene* pScene)
{
	if (m_KeyboardCommands.find(pScene) == m_KeyboardCommands.end())
	{
		std::map<SDL_Scancode, Command*> newMap = std::map<SDL_Scancode, Command*>();
		m_KeyboardCommands.emplace(pScene, newMap);
	}
	m_KeyboardCommands[pScene].emplace(scanCode, command);
}
#pragma warning(pop)