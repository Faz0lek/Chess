#include "Tile.h"

Tile::Tile() : Occupant(nullptr)
{
	this->TileRectangle.left = 0;
	this->TileRectangle.top = 0;
	this->TileRectangle.height = Tile::TileSize;
	this->TileRectangle.width = Tile::TileSize;
}

const int Tile::TileSize = 70;