#pragma once
#include<map>
#include<vector>

using namespace std;

template <typename Key, typename Value>
class IManager
{
    Value* current;
protected:
    map<Key, Value*> allValues;
    vector<Value*> unregisteredValues;

public:
    ~IManager()
    {
        for (auto _pair : allValues)
        {
            delete _pair.second;
        }

        for (Value* _value : unregisteredValues)
        {
            delete _value;
        }
    }

public:
    void Add(const Key& _key, Value* _value)
    {
        if (Exist(_value))
        {
            unregisteredValues.push_back(_value);
            return;
        }
        allValues[_key] = _value;
        current = _value;
        _value->SetID(_key);
    }
    void Remove(Value* _value)
    {
        if (!Exist(_value))return;

        const Key& _key = _value->GetID();
        delete _value;
        allValues[_value->GetID()] = nullptr;
        allValues.erase(_key);
    }
    void Remove(const Key& _key)
    {
        if (!Exist(_key))return;
        delete allValues[_key];
        allValues[_key] = nullptr;
        allValues.erase(_key);
    }
    Value* Get(const Key& _key)
    {
        if (!Exist(_key))return nullptr;
        return allValues[_key];

    }
    map<Key, Value*> GetAll() const
    {
        return allValues;
    }
    Value* GetCurrent()
    {
        return current;
    }
    bool Exist(const Key& _key)
    {
        return allValues.find(_key) != allValues.end();
    }
    bool Exist(Value* _value)
    {
        return Exist(_value->GetID());
    }
};