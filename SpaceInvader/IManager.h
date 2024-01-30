#pragma once
#include <map>

using namespace std;

template <typename Key,typename Value>
class IManager
{
	map<Key, Value*> allValues;

public:
	~IManager()
	{
		for (auto& _pair : allValues)
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

	Value* Get(const Key& _key)
	{
		if (!Exist(_key)) return nullptr;

		return allValues[_key];
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

