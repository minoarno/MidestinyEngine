#pragma once
#include "Singleton.h"
class Time final : public dae::Singleton<Time>
{
public:
	~Time() = default;
	
	Time(const Time& other) = delete;
	Time& operator=(const Time& other) = delete;
	Time(Time&& other) = delete;
	Time& operator=(Time&& other) = delete;
	
	inline float GetTimeScale()const { return m_TimeScale; }
	inline float GetElapsedSeconds()const { return m_ElapsedSeconds * m_TimeScale; }
	inline float GetFixedElapsedSeconds()const { return m_FixedElapsedSeconds * m_TimeScale; }
	
	inline void SetTimeScale(const float value) { m_TimeScale = value; }
	inline void SetElapsedSeconds(const float value) { m_ElapsedSeconds = value; }
	inline void SetFixedElapsedSeconds(const float value) { m_FixedElapsedSeconds = value; }
private:
	friend class Singleton<Time>;
	Time() = default;
	
	float m_TimeScale = 1.f;
	float m_ElapsedSeconds = 0.f;
	float m_FixedElapsedSeconds = 0.02f;
};

