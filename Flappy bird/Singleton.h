#pragma once

template <class Class>
class Singleton
{
protected:
    static Class* instance;

public:
    static Class* GetInstance()
    {
        if (!instance) instance = new Class();
        return instance;
    }
public:
    Singleton() {};
    ~Singleton()
    {
        delete instance;
    }

};

template <class Class>
Class* Singleton<Class>::instance = nullptr;