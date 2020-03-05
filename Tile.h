#pragma once
#include "ChessPiece.h"

class ChessPiece;

class Tile
{
public:
	Tile();

	ChessPiece* Occupant;
	sf::IntRect TileRectangle;

	static const int TileSize;
};