#pragma once

template <typename Class>
class Singleton
{
	static Class instance;

public:
	static Class& GetInstance()
	{
		return instance;
	}
};

template <typename Class>
Class Singleton<Class>::instance;