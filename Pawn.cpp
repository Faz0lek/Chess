#include "Pawn.h"

Pawn::Pawn(std::string StartingTile, char team) : ChessPiece(StartingTile, team)
{
	this->PieceTexture.loadFromFile(team == 'W' ? "Images/WhitePawn.png" : "Images/BlackPawn.png");
	this->PieceSprite.setTexture(this->PieceTexture);
}

bool Pawn::IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y)
{
	int thisx = (this->OccupantOf->TileRectangle.left - 45) / 70;
	int thisy = (this->OccupantOf->TileRectangle.top - 45) / 70;

	if (this->team == 'W') // NECO STOJI PRED PESCEM
	{
		if (thisx == x && thisy - y == 1 && Tiles[x][y].Occupant != nullptr)
			return false;
	}
	else if (this->team == 'B')
	{
		if (thisx == x && thisy - y == -1 && Tiles[x][y].Occupant != nullptr)
			return false;
	}

	if (this->team == 'W' && thisy - y == 1  && abs(thisx - x) == 1 && Tiles[x][y].Occupant != nullptr && Tiles[x][y].Occupant->team != this->team) // BRANI FIGUREK
	{
		Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
		return true;
	}
	else if (this->team == 'B' && thisy - y == -1 && abs(thisx - x) == 1 && Tiles[x][y].Occupant != nullptr && Tiles[x][y].Occupant->team != this->team)
	{
		Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
		return true;
	}

	if (this->PieceSprite.getPosition().x == Tiles[x][y].TileRectangle.left) // POHYB POUZE PO OSE Y
	{
		if (this->team == 'W') // KONTROLA TYMU - BILY TYM
		{
			if (this->PieceSprite.getPosition().y > Tiles[x][y].TileRectangle.top) // KONTROLA SPRAVNEHO SMERU PO OSE Y
			{
				if (!this->HasMoved && this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top == 140) // POKUD SE PESEC NIKDY NEPOHNUL, MUZE JIT O 2 POLE DOPREDU
				{
					if (Tiles[x][y].Occupant == nullptr && Tiles[x][y + 1].Occupant == nullptr)
					{
						return true;
					}
					//this->HasMoved = true;
					return false;
				}
				if (this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top > 70) // KONTROLA POHYBU O VICE NEZ 1 POLE
				{
					return false;
				}

				//this->HasMoved = true;
				return true;
			}
		}
		else // KONTROLA TYMU - CERNY TYM
		{
			if (this->PieceSprite.getPosition().y < Tiles[x][y].TileRectangle.top) // KONTROLA SPRAVNEHO SMERU PO OSE Y
			{
				if (!this->HasMoved && Tiles[x][y].TileRectangle.top - this->PieceSprite.getPosition().y == 140) // POKUD SE PESEC NIKDY NEPOHNUL, MUZE JIT O 2 POLE DOPREDU
				{
					if (Tiles[x][y].Occupant == nullptr && Tiles[x][y - 1].Occupant == nullptr)
					{
						return true;
					}

					//this->HasMoved = true;
					return false;
				}
				if (Tiles[x][y].TileRectangle.top - this->PieceSprite.getPosition().y > 70)// KONTROLA POHYBU O VICE NEZ 1 POLE
				{
					return false;
				}

				//this->HasMoved = true;
				return true;
			}
		}
	}

	return false;
}