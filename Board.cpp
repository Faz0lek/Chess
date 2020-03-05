#include "Board.h"

#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"

Board::Board()
{
	this->BoardTexture.loadFromFile("Images/board.png");
	this->BoardSprite.setTexture(this->BoardTexture);
	this->MovingPiece = nullptr;
	

	std::string key;

	Tiles.assign(8, std::vector<Tile>(8, Tile()));

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			key = 65 + x;
			key.push_back(56 - y);

			this->Tiles[x][y].TileRectangle.left = Board::Offset + (70 * x);
			this->Tiles[x][y].TileRectangle.top = Board::Offset + (70 * y);
			this->TileMap[key] = &this->Tiles[x][y];
		}
	}

	this->WhiteTeam = { new Rook("A1", 'W'), new Knight("B1", 'W'), new Bishop("C1", 'W'), new Queen("D1", 'W'), new King("E1", 'W'), new Bishop("F1", 'W'), new Knight("G1", 'W'), new Rook("H1", 'W'),
						new Pawn("A2", 'W'), new Pawn("B2", 'W'), new Pawn("C2", 'W'), new Pawn("D2", 'W'), new Pawn("E2", 'W'), new Pawn("F2", 'W'), new Pawn("G2", 'W'), new Pawn("H2", 'W') };

	this->BlackTeam = { new Rook("A8", 'B'), new Knight("B8", 'B'), new Bishop("C8", 'B'), new Queen("D8", 'B'), new King("E8", 'B'), new Bishop("F8", 'B'), new Knight("G8", 'B'), new Rook("H8", 'B'),
						new Pawn("A7", 'B'), new Pawn("B7", 'B'), new Pawn("C7", 'B'), new Pawn("D7", 'B'), new Pawn("E7", 'B'), new Pawn("F7", 'B'), new Pawn("G7", 'B'), new Pawn("H7", 'B') };

	for (int i = 0; i < 16; i++)
	{
		this->WhiteTeam[i]->PieceSprite.setPosition(this->TileMap[this->WhiteTeam[i]->StartingPosition]->TileRectangle.left, this->TileMap[this->WhiteTeam[i]->StartingPosition]->TileRectangle.top);
		this->WhiteTeam[i]->OccupantOf = this->TileMap[WhiteTeam[i]->StartingPosition];

		this->BlackTeam[i]->PieceSprite.setPosition(this->TileMap[this->BlackTeam[i]->StartingPosition]->TileRectangle.left, this->TileMap[this->BlackTeam[i]->StartingPosition]->TileRectangle.top);
		this->BlackTeam[i]->OccupantOf = this->TileMap[BlackTeam[i]->StartingPosition];
	}

	for (int i = 0; i < 8; i++)
	{
		this->Tiles[i][0].Occupant = this->BlackTeam[i];
		this->Tiles[i][1].Occupant = this->BlackTeam[i + 8];
		this->Tiles[i][7].Occupant = this->WhiteTeam[i];
		this->Tiles[i][6].Occupant = this->WhiteTeam[i + 8];
	}

}

Board::~Board()
{
	for (int i = 0; i < this->WhiteTeam.size(); i++)
		delete (this->WhiteTeam[i]);

	for (int i = 0; i < this->BlackTeam.size(); i++)
		delete (this->BlackTeam[i]);
}

const int Board::Offset = 45;