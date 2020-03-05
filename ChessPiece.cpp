#include "ChessPiece.h"

ChessPiece::ChessPiece(std::string StartingTile, char team)
{
	this->OccupantOf = nullptr;
	this->team = team;
	this->StartingPosition = StartingTile;
	this->HasMoved = false;
	this->IsCastling = 0;
}