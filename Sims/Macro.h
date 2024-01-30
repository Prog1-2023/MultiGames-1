#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

template <typename T>
static bool Contains(const vector<T>& _vector, const T& _value) {
	return (find(_vector.begin(), _vector.end(), _value) != _vector.end());
}

template <typename T>
static T Random(const T& _min, const T& _max) {
	return rand() % _max + _min;
}

static Vector2i RandomPosition(const Vector2i _min, const Vector2i _max) {
	const int _x = rand() % _max.x + _min.x;
	const int _y = rand() % _max.y + _min.y;
	return Vector2i(_x, _y);
}

static void SetOriginAtMiddle(Shape* _shape) {
	const Vector2f _shapeSize = _shape->getLocalBounds().getSize();
	_shape->setOrigin(_shapeSize.x / 2, _shapeSize.y / 2);
}

static void SetOriginAtMiddle(Text* _text) {
	const Vector2f _shapeSize = _text->getLocalBounds().getSize();
	_text->setOrigin(_shapeSize.x / 2, _shapeSize.y / 2);
}
