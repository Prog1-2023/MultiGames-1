#pragma once

template<typename ID>
class IManageable
{
protected:
	ID id;

public:
	void SetID(const ID& _id)
	{
		id = _id;
	}

	ID GetID()const
	{
		return id;
	}

public:
	IManageable(const ID& _id)
	{
		id = _id;
	}

public:
	virtual void Register() = 0;
};
