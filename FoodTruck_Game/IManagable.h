#pragma once
template <typename ID>
class IManagable
{
	ID id;

public:
	ID GetID()
	{
		return id;
	}
	void SetID(const ID& _id)
	{
		id = _id;
	}

public:
	IManagable(const ID& _id)
	{
		id = _id;
	}
public:
	virtual void Register() = 0;
};

