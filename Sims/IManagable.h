#pragma once

template <typename ID>
class IManagable
{
protected:
	ID id;
	virtual void Register() = 0;

public:

	IManagable(const ID& _id) { id = _id; }

	void SetID(const ID& _id) { id = _id; }

	ID GetID() const { return id; }


};
