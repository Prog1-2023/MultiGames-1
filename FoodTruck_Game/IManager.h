#pragma once
#include <map>
#include <iostream>
using namespace std;

template<typename Key , typename Value>
class IManager
{

	map<Key, Value*> allValues;

public:
	map<Key, Value*> GetAllValues() const
	{
		return allValues;
	}

public:
	void Add(const Key& _key, Value* _value)
	{
		if (Exist(_value))
		{
			return;
		}

		_value->SetID(_key);
		allValues[_key] = _value;
	}


	void Remove(Value* _value)
	{
		if(!Exist(_value)) return;

		const Key& _key = _value->GetID();
		delete _value;
		allValues[_key] = nullptr;

	}


	void Remove(const Key& _key)
	{
		if (!Exist(_key)) return;
		delete allValues[_key];
		allValues[_key] = nullptr;

	}

	Value* Get(const Key& _key)
	{
		if (!Exist(_key)) return nullptr;
		return allValues[_key];
	}

	bool Exist(const Key& _key) const
	{
		return allValues.find(_key) != allValues.end();
	}

	bool Exist(Value* _value) const
	{
		return Exist(_value->GetID());
	}
};

