#pragma once

#include "ChessPiece.h"

class King : public ChessPiece
{
public:
	King(std::string StartingTile, char team);

	bool IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y);
};