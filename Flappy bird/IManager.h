#pragma once
#include <map>

using namespace std;

template <typename Key, typename Value>
class IManager
{
	Value* current;

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

	void Add(const Key& _key, Value* _value)
	{
		if (Exist(_value)) return;
		allValues[_key] = _value;
		_value->SetID(_key);
		current = _value;
	}

	void Remove(Value* _value)
	{
		if (!Exist(_value)) return;
		delete _value;
		allValues[_value->GetID()] = nullptr;
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

	Value* GetCurrent() const
	{
		return current;
	}

	map<Key, Value*> GetAll() const
	{
		return allValues;
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

