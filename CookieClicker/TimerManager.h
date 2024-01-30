#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Timer.h"

#include <SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class TimerManager : public Singleton<TimerManager>, public IManager<int, Timer>
{
	Clock clock;
	float time;
	float lastTime;
	float elapsedTime;
	float timeScale;
	float deltaTime;
	unsigned int framesCount;
	unsigned int maxFrameRate;
	float fps;

public:
	void SetTimeScale(const float _timeScale)
	{
		timeScale = _timeScale;
	}
	void SetMaxFrameRate(const unsigned int _maxFrameRate)
	{
		maxFrameRate = _maxFrameRate;
	}
	float GetFPS() const
	{
		return fps;
	}
	void ComputeFPS()
	{
		fps = 1.0f / (time - lastTime);
	}
	bool Render()
	{
		if (lastTime == 0 || time - lastTime >= 1.0f / maxFrameRate)
		{
			ComputeFPS();
			lastTime = time;
			return true;
		}

		return false;
	}

public:
	TimerManager();

private:
	void UpdateTimers();
	void RemoveOldTimers(const vector<int>& _oldTimersId);

public:
	void Update();
};