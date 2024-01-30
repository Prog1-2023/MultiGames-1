#pragma once

class TextureManager;
class EntityManager;
class MapManager;

template<typename ID>
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

private:
	virtual void Register() = 0;
};