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
	virtual void Execute() const = 0;
};

class FunctionCommand : public Command
{
public:
	FunctionCommand() = default;
	FunctionCommand(const FunctionCommand& other) = delete;
	FunctionCommand& operator=(const FunctionCommand& other) = delete;
	FunctionCommand(FunctionCommand&& other) = delete;
	FunctionCommand& operator=(FunctionCommand&& other) = delete;
	~FunctionCommand() = default;
	
	virtual void Execute()const override
	{
		if (m_Function != nullptr)
		{
			m_Function();
		}
	}

	void SetFunction(std::function<void()> func)
	{
		m_Function = func;
	}
protected:
	std::function<void()> m_Function;
};