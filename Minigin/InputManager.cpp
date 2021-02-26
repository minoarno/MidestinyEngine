#include "MiniginPCH.h"
#pragma once
#include "InputManager.h"
#include "Commands.h"

dae::InputManager::~InputManager()
{
	
	for (std::pair<ControllerButton, std::pair<bool, Command*>> c : m_ControllerCommands)
	{
		delete c.second.second;
		c.second.second = nullptr;
	}
	m_ControllerCommands.clear();

	for (std::pair<SDL_Scancode, Command*> c : m_KeyboardCommands)
	{
		delete c.second;
		c.second = nullptr;
	}
}


bool dae::InputManager::ProcessInput()
{
	//DWORD state;
	SecureZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	if (!IsPressed(ControllerButton(m_CurrentState.Gamepad.wButtons)))
	{
		for (auto& c : m_ControllerCommands)
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

		}
		if (e.type == SDL_KEYUP)
		{

		}
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{

		}
		if (e.type == SDL_MOUSEBUTTONUP)
		{

		}
		for (auto& key : m_KeyboardCommands)
		{
			if (key.first == e.key.keysym.scancode)
			{
				key.second->OnHold();
			}
		}

		if (m_KeyboardCommands.find(e.key.keysym.scancode) != m_KeyboardCommands.end())
		{
			m_KeyboardCommands.at(e.key.keysym.scancode)->OnHold();
		}
	}

	return true;
}

bool dae::InputManager::IsPressed(ControllerButton button)
{
	if (m_ControllerCommands.find(button) != m_ControllerCommands.end())
	{
		const bool previousState = m_ControllerCommands.at(button).first;
		if (previousState == false)
		{
			m_ControllerCommands.at(button).first = true;
			m_ControllerCommands.at(button).second->OnPressDown();
		}
		else
		{
			m_ControllerCommands.at(button).second->OnHold();
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

void dae::InputManager::AddInput(ControllerButton controllerButton, Command* command)
{
	m_ControllerCommands.emplace(controllerButton, std::make_pair(false, command));
}

#pragma warning(push)
#pragma warning(disable : 26812)
void dae::InputManager::AddInput(SDL_Scancode scanCode, Command* command)
{
	m_KeyboardCommands.emplace(scanCode, command);
}
#pragma warning(pop)