#pragma once

#include "ChessPiece.h"

// Trida jezdce
class Knight : public ChessPiece
{
public:
	Knight(std::string StartingTile, char team);

	bool IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y);
private:
	static const int AvailableMoves[8][2];
};