#pragma once

#include "ChessPiece.h"

// Trida pesce
class Pawn : public ChessPiece
{
public:
	Pawn(std::string StartingTile, char team);

	bool IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y);
};