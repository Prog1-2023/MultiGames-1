#pragma once
#include <map>
using namespace std;


template <typename Key, typename Value>
class IManager
{
protected:
	map<Key, Value*> allValues;

public:

	~IManager() {
		for (auto _pair : allValues) {
			delete _pair.second;
		}
	}

	void Add(const Key& _key, Value* _value) {
		if (Exist(_value)) return;
		allValues[_key] = _value;
		_value->SetID(_key);
	}

	void Remove(Value* _value){
		if (!Exist(_value)) return;
		const Key& _key = _value->GetID();
		delete _value;
		allValues[_key] = nullptr;
		allValues.erase(_key);
	}

	void Remove(const Key& _key) {
		if (!Exist(_key)) return;
		allValues[_key] = nullptr;
	}

	void Clear() {
		for (auto _pair : allValues) {
			delete _pair.second;
		}
		allValues.clear();
	}

	Value* Get(const Key& _key) {
		if (!Exist(_key)) return nullptr;
		return allValues[_key];
	}

	map<Key, Value*> GetAll() const
	{
		return allValues;
	}

	bool Exist(Value* _value) {
		return Exist(_value->GetID());
	}

	bool Exist(const Key& _key) {
		return allValues.find(_key) != allValues.end();
	}

};

