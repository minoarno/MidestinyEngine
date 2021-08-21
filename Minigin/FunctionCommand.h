#pragma once
#include "Commands.h"
#include <functional>

class FunctionCommand : public Command
{
public:
	FunctionCommand() = default;
	FunctionCommand(const FunctionCommand& other) = delete;
	FunctionCommand& operator=(const FunctionCommand& other) = delete;
	FunctionCommand(FunctionCommand&& other) = delete;
	FunctionCommand& operator=(FunctionCommand&& other) = delete;
	~FunctionCommand() = default;

	inline virtual void Execute()const override
	{
		if (m_Function != nullptr)
		{
			m_Function();
		}
	}

	inline void SetFunction(std::function<void()> func)
	{
		m_Function = func;
	}
protected:
	std::function<void()> m_Function;
};