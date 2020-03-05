#pragma once
#include "ChessPiece.h"

// Trida strelce
class Bishop : public ChessPiece
{
public:
	Bishop(std::string StartingTile, char team);

	bool IsLegalMove(const std::vector<std::vector<Tile>>& Tiles, const int x, const int y);
};