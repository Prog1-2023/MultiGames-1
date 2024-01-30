#pragma once

template <typename ID>
class IManagable
{
protected:
	ID id;

public:
	IManagable(const ID& _id)
	{
		id = _id;
	}

public:
	ID GetID() const
	{
		return id;
	}
	void SetID(const ID& _id)
	{
		id = _id;
	}

public:
	virtual void Register() = 0;
};

