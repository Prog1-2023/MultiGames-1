#pragma once

template<typename ClassName>
class Singleton
{
public:
	static ClassName& GetInstance()
	{
		static ClassName instance;
		return instance;
	}

public:
	Singleton(){}
	Singleton(const Singleton&) = delete;

};

