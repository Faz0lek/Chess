#pragma once

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <cmath>

class Tile;

class ChessPiece
{
public:
	sf::Texture PieceTexture;
	sf::Sprite PieceSprite;
	std::string StartingPosition;
	char team;

	Tile* OccupantOf;

	ChessPiece(std::string StartingTile, char team);
	virtual bool IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y) = 0;
	bool HasMoved;
	int IsCastling;
};
