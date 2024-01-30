#pragma once
#include <vector>
#include <map>

using namespace std;

template<typename Key, typename Value>
class IManager
{
protected:
	Value* current;
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
	void Add(const Key& _key, Value* _value)
	{
		if (Exist(_value)) return;
		_value->SetID(_key);
		allValues[_key] = _value;
		current = _value;
	}
	void Remove(Value* _value)
	{
		if (!Exist(_value)) return;

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
	Value* GetCurrent() const
	{
		return current;
	}
	map<Key, Value*> GetAll() const
	{
		return allValues;
	}

};