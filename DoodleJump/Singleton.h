#pragma once
template <typename Class>
class Singleton
{
protected:
	static Class* _instance;
public:
	static Class* GetInstance()
	{
		if (!instance) intance = new Class();
		return instance;
	}

public:
	Singleton(){}
	~Singleton()
	{
		delete _instance;
	}
};

template <typename Class> 
Class* Singleton<Class>::_instance = nullptr;
