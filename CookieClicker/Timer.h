#pragma once
#include "IManagable.h"
#include <functional>

using namespace std;

enum DurationType
{
	DURATION_SECONDS,
	DURATION_MILLISECONDS,
	DURATION_MICROSECONDS
};

class Timer : public IManagable<int>
{
	function<void()> callback;
	float currentDuration;
	float duration;
	bool isLoop;
	DurationType durationType;

public:
	Timer(const int _id, const function<void()>& _callback, const float _duration,
		const DurationType& _durationType = DURATION_SECONDS, const bool _isLoop = false);

private:
	virtual void Register() override;

public:
	bool Update(const float _deltaTime);
};