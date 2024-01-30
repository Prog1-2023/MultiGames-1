#include <random>
#include "Game.h"

using namespace std;
using namespace sf;


int main()
{
	srand(static_cast<int>(time(nullptr)));
	locale::global(locale(""));

	Game _game;
	_game.Launch();
}





