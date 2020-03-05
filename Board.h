#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

#include "ChessPiece.h"
#include "Tile.h"

class Board
{
public:
	sf::Texture BoardTexture;
	sf::Sprite BoardSprite;
	Board();
	~Board();

	std::vector <ChessPiece*> WhiteTeam;
	std::vector <ChessPiece*> BlackTeam;
	ChessPiece* MovingPiece;

	std::vector <std::vector <Tile>> Tiles;
	std::map <std::string, Tile*> TileMap;
	
	static const int Offset;
};