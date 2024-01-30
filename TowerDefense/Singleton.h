#pragma once

template <typename Type>
class Singleton
{
	static Type* instance;
	
public:
	static Type* GetInstance()
	{
		if (!instance) instance = new Type();
		return instance;
	}

public:
	~Singleton()
	{
		delete instance;
	}
};

template <typename Type> Type* Singleton<Type>::instance = nullptr;