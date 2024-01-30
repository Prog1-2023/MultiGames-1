#pragma once

template <typename ID>
class IManagable
{
protected:
	ID id;

public:
	void SetID(const ID& _id)
	{
		id = _id;
	}
	ID GetID() const
	{
		return id;
	}

public:
	IManagable(const ID& _id)
	{
		id = _id;
	}

protected:
	virtual void Register() = 0;
};