#pragma once

#include "ChessPiece.h"

// Trida kralovny
class Queen : public ChessPiece
{
public:
	Queen(std::string StartingTile, char team);

	bool IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y);
};