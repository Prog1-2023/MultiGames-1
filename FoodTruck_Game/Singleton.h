#pragma once
template<typename Class>
class Singleton
{
	static Class* instance;


public:
	Class* GetInstance() const
	{
		if (!instance) instance = new Class();
		return instance;
	}

public:
	~Singleton()
	{
		delete instance;
	}
};

template<typename Class>
Class* Singleton<Class>::instance = nullptr;

