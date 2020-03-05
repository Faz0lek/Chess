#pragma once

#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"

class Game
{
public:
	Game();

private:
	sf::Image Icon;
	bool WhiteTurn;
};
