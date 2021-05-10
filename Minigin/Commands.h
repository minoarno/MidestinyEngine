#pragma once
#include <functional>

class Command
{
public:
	Command() = default;
	Command(const Command& other) = delete;
	Command& operator=(const Command& other) = delete;
	Command(Command&& other) = delete;
	Command& operator=(Command&& other) = delete;
	
	virtual ~Command() = default;
	virtual void OnPressDown()const = 0;
	virtual void OnHold()const = 0;
	virtual void OnRelease()const = 0;
};

class FunctionCommand : public Command
{
public:
	FunctionCommand() = default;
	//FunctionCommand(const std::function<void>& funcDown, const std::function<void>& hold, const std::function<void>& release);
	FunctionCommand(const FunctionCommand& other) = delete;
	FunctionCommand& operator=(const FunctionCommand& other) = delete;
	FunctionCommand(FunctionCommand&& other) = delete;
	FunctionCommand& operator=(FunctionCommand&& other) = delete;
	~FunctionCommand() = default;
	
	virtual void OnPressDown()const override
	{
		if (m_FunctionOnPressDown != nullptr)
		{
			m_FunctionOnPressDown();
		}
	}
	
	virtual void OnHold()const override
	{
		if (m_FunctionOnHold != nullptr)
		{
			m_FunctionOnHold();
		}
	}
	
	virtual void OnRelease()const override
	{
		if (m_FunctionOnRelease != nullptr)
		{
			m_FunctionOnRelease();
		}
	}

	void SetFunctionOnPressDown(std::function<void()> func)
	{
		m_FunctionOnPressDown = func;
	}

	void SetFunctionOnHold(std::function<void()> func)
	{
		m_FunctionOnHold = func;
	}

	void SetFunctionOnRelease(std::function<void()> func)
	{
		m_FunctionOnRelease = func;
	}
protected:
	std::function<void()> m_FunctionOnPressDown;
	std::function<void()> m_FunctionOnHold;
	std::function<void()> m_FunctionOnRelease;
};