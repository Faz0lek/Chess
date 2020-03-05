#pragma once

#include "ChessPiece.h"

// Trida veze
class Rook : public ChessPiece
{
public:
	Rook(std::string StartingTile, char team);

	bool IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y);
};