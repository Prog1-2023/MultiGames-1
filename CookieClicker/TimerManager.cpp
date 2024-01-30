#include "TimerManager.h"

TimerManager::TimerManager()
{
	clock = Clock();
	time = 0.0f;
	lastTime = 0.0f;
	elapsedTime = 0;
	timeScale = 1.0f;
	deltaTime = 0.0f;
	framesCount = 0;
	maxFrameRate = 60;
	fps = 0;
}


void TimerManager::UpdateTimers()
{
	vector<int> _idsToRemove;

	for (const auto& _pair : allValues)
	{
		if (!_pair.second->Update(deltaTime))
		{
			// remove timer
			_idsToRemove.push_back(_pair.first);
		}
	}

	RemoveOldTimers(_idsToRemove);
}

void TimerManager::RemoveOldTimers(const vector<int>& _oldTimersId)
{
	for (const int _id : _oldTimersId)
	{
		Remove(_id);
	}
}


void TimerManager::Update()
{
	time = clock.getElapsedTime().asSeconds();
	elapsedTime = (time - lastTime) / 450000.0f;
	deltaTime = elapsedTime * timeScale;
	framesCount++;
	UpdateTimers();
}