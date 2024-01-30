#pragma once
#include <map>

using namespace std;

template <typename Key, typename Value>

class IManager
{
	Value* value;
protected:
	map<Key, Value*> allValues;
public:
	~IManager()
	{
		for (auto _pair : allValues)
		{
			delete _pair.second;
		}
	}

public:
	void Add(Key _key, Value* _value)
	{
		if (Exist(_value)) return;
		allValues[_key] = _value;
		_value->SetID(_key);
		value = _value;
	}
	void Remove(Value* _value)
	{
		if (!Exist(_value)) return;
		const Key& _key = _value->GetID();
		delete _value;
		allValues[_value->GetID()] = nullptr;
	}
	void Remove(const Key& _key)
	{
		if (!Exist(value)) return;
		delete allValues[_key];
	}
	Value* Get(const Key& _key)
	{
		if (!Exist(value)) return;
		return allValues[_key];
	}
	Value* GetCurrent() const
	{
		return value;
	}
	map<Key, Value*> GetAll() const
	{
		return allValues;
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