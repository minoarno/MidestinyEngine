#pragma once
#include <Windows.h>
#include <XInput.h>
#include <map>
#include "Singleton.h"
#include <SDL_events.h>

class Command;
namespace dae
{
	class Scene;

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

	struct InputStruct
	{
	public:
		Command* pOnPressDown = nullptr;
		Command* pOnHold = nullptr;
		Command* pOnRelease = nullptr;
		bool wasPressedDownPreviousFrame = false;

		InputStruct()
		{
		}
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		~InputManager();
		bool ProcessInput();
		bool IsPressed(ControllerButton button);
		SDL_Event GetEvent();

		void AddOnPressDown(ControllerButton controllerButton, Command* command, const Scene* pScene);
		void AddOnPressDown(SDL_Scancode scanCode, Command* command, const Scene* pScene);

		void AddOnHold(ControllerButton controllerButton, Command* command, const Scene* pScene);
		void AddOnHold(SDL_Scancode scanCode, Command* command, const Scene* pScene);

		void AddOnRelease(ControllerButton controllerButton, Command* command, const Scene* pScene);
		void AddOnRelease(SDL_Scancode scanCode, Command* command, const Scene* pScene);
	private:
		friend class Singleton<InputManager>;
		InputManager() = default;

		std::map<const Scene*, std::map<ControllerButton, InputStruct>> m_ControllerCommands;
		std::map<const Scene*, std::map<SDL_Scancode, InputStruct>> m_KeyboardCommands;

		XINPUT_STATE m_CurrentState;
		SDL_Event m_Event;
		bool m_DidInputGet = false;
	};

}
