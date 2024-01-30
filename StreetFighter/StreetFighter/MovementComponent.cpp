#include "MovementComponent.h"

MovementComponent::MovementComponent(const MovementKey& _keys,
	const KeyPressedData& _boolKeyData)
{
	keys = _keys;
	boolKeyData = _boolKeyData;
}
