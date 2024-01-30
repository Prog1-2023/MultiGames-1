#pragma once
#include "Card.h"
#include <vector>

using namespace std;

class Board
{
	vector<Card*> cards;
	int gap;
	int nbCard;

public:
	Board();

public:
	void Init(const Vector2f& _windowSize);
	void InitCard(const Vector2f& _windowSize);
};

