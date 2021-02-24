#pragma once
#include <map>
#include "Singleton.h"

class Command;
namespace dae
{
	enum class ControllerButton
	{
		DPadUp = 0x0001,
		DPadDown = 0x0002,
		DPadLeft = 0x0004,
		DPadRight = 0x0008,
		ButtonStart = 0x0010,
		ButtonBack = 0x0020,
		LeftThumb = 0x0040,
		RightThumb = 0x0080,
		LeftShoulder = 0x0100,
		RightShoulder = 0x0200,
		ButtonA = 0x1000,
		ButtonB = 0x2000,
		ButtonX = 0x4000,
		ButtonY = 0x8000
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		~InputManager();
		bool ProcessInput();
		bool IsPressed(ControllerButton button);
		SDL_Event GetEvent();

		void AddInput(ControllerButton controllerButton, Command* command);
		void AddInput(SDL_Scancode scanCode, Command* command);

	private:
		friend class Singleton<InputManager>;
		InputManager() = default;
		std::map<ControllerButton, std::pair<bool, Command*>> m_ControllerCommands;
		std::map<SDL_Scancode, Command*> m_KeyboardCommands;
		XINPUT_STATE m_CurrentState{};
		SDL_Event m_Event;
		bool m_DidInputGet = false;
	};

}
