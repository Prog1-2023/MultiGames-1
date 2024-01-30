#include "Board.h"

Board::Board()
{
	cards = vector<Card*>();
	int gap = 3;
}

void Board::Init(const Vector2f& _windowSize)
{
	InitCard(_windowSize);
}

void Board::InitCard(const Vector2f& _windowSize)
{
	for (int _index = 0; _index < nbCard; _index++)
	{
		//cards.push_back(new Card());
	}
}
