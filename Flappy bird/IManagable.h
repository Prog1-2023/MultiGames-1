#pragma once

template <typename ID>
class IManagable
{
protected:
	ID id;

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
	IManagable() = default;

	IManagable(const ID& _id)
	{
		id = _id;
	}

protected:
	virtual void Register() = 0;
};

