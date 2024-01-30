#pragma once
#include<map>

using namespace std;

template <typename Key, typename Value>
class IManager
{
protected:
	map< Key, Value*> allValues;
	Value* selectedValue;

public:
	Value* GetSelected()
	{
		return selectedValue;
	}

public:
	~IManager()
	{
		for (auto _pair : allValues)
		{
			if (_pair.second)return;
			delete _pair.second;
			_pair.second = nullptr;
		}
	}
public:
	void Add(const Key& _key, Value* _value)
	{
		if (Exist(_value))return;
		allValues[_key] = _value;
		_value->SetID(_key);
		selectedValue = _value;
	}
	void Remove(Value* _value)
	{
		if (!Exist(_value))return;
		allValues[_value->GetID()] = nullptr;
	}
	void Remove(const Key& _key)
	{
		if (!Exist(_key))return;
		allValues[_key] = nullptr;
	}
	Value* Get(const Key& _key)
	{
		if (!Exist(_key))return nullptr;
		selectedValue = allValues[_key];
		return allValues[_key];

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

