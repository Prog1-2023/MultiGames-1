#include "Timer.h"
#include "TimerManager.h"

Timer::Timer(const int _id, const function<void()>& _callback, const float _duration,
	const DurationType& _durationType, const bool _isLoop) : IManagable(_id)
{
	Register();

	callback = _callback;
	currentDuration = 0.0f;
	duration = _duration;
	isLoop = _isLoop;
	durationType = _durationType;
}


void Timer::Register()
{
	TimerManager::GetInstance().Add(id, this);
}


bool Timer::Update(const float _deltaTime)
{
	currentDuration += _deltaTime;
	if (currentDuration >= duration / pow(1000.0f, static_cast<float>(durationType)))
	{
		callback();
		currentDuration = 0.0f;

		if (!isLoop)
		{
			return false;
		}
	}

	return true;
}