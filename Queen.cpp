#include "Queen.h"

Queen::Queen(std::string StartingTile, char team) : ChessPiece(StartingTile, team)
{
	this->PieceTexture.loadFromFile(team == 'W' ? "Images/WhiteQueen.png" : "Images/BlackQueen.png");
	this->PieceSprite.setTexture(this->PieceTexture);
}

bool Queen::IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y)
{
	bool IsAttacking = false;

	if (Tiles[x][y].Occupant != nullptr) // POHYB NA OBSAZENE POLE
	{
		if (this->team == Tiles[x][y].Occupant->team) // POKUS O POHYB NA POLE OBSAZENE FIGURKOU STEJNE BARVY
		{
			return false;
		}
		else // SEBRANI FIGURKY
		{
			IsAttacking = true;
		}
	}

	if (this->PieceSprite.getPosition().x == Tiles[x][y].TileRectangle.left) // POHYB PO OSE Y
	{
		if (this->PieceSprite.getPosition().y > Tiles[x][y].TileRectangle.top) // POHYB PO OSE Y NAHORU
		{
			for (int i = 1; i < ((abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) - 45) / 70); i++)
			{
				if (Tiles[x][y + i].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
		else if (this->PieceSprite.getPosition().y < Tiles[x][y].TileRectangle.top) // POHYB PO OSE Y DOLU
		{
			for (int i = 1; i < (abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) - 45) / 70; i++)
			{
				if (Tiles[x][y - i].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
	}
	else if (this->PieceSprite.getPosition().y == Tiles[x][y].TileRectangle.top) // POHYB PO OSE X
	{
		if (this->PieceSprite.getPosition().x < Tiles[x][y].TileRectangle.left) // POHYB PO OSE X DOPRAVA
		{
			for (int i = 1; i < ((abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) - 45) / 70); i++)
			{
				if (Tiles[x - 1][y].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
		else if (this->PieceSprite.getPosition().x > Tiles[x][y].TileRectangle.left) // POHYB PO OSE X DOLEVA
		{
			for (int i = 1; i < (abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) - 45) / 70; i++)
			{
				if (Tiles[x + i][y].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
	}
	if (this->PieceSprite.getPosition().x < Tiles[x][y].TileRectangle.left && this->PieceSprite.getPosition().y > Tiles[x][y].TileRectangle.top) // POHYB VE SMERU [+, -]
	{
		if (abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) == abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top)) // KONTROLA POHYBU PO DIAGONALE
		{
			for (int i = 1; i < ((abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) - 45) / 70); i++)
			{
				if (Tiles[x - i][y + i].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
	}
	else if (this->PieceSprite.getPosition().x < Tiles[x][y].TileRectangle.left && this->PieceSprite.getPosition().y < Tiles[x][y].TileRectangle.top) // POHYB VE SMERU [+, +]
	{
		if (abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) == abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top)) // KONTROLA POHYBU PO DIAGONALE
		{
			for (int i = 1; i < ((abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) - 45) / 70); i++)
			{
				if (Tiles[x - i][y - i].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
	}
	else if (this->PieceSprite.getPosition().x > Tiles[x][y].TileRectangle.left && this->PieceSprite.getPosition().y < Tiles[x][y].TileRectangle.top) // POHYB VE SMERU [-, +]
	{
		if (abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) == abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top)) // KONTROLA POHYBU PO DIAGONALE
		{
			for (int i = 1; i < ((abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) - 45) / 70); i++)
			{
				if (Tiles[x + i][y - i].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
	}
	else if (this->PieceSprite.getPosition().x > Tiles[x][y].TileRectangle.left && this->PieceSprite.getPosition().y > Tiles[x][y].TileRectangle.top) // POHYB VE SMERU [-, -]
	{
		if (abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) == abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top)) // KONTROLA POHYBU PO DIAGONALE
		{
			for (int i = 1; i < ((abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) - 45) / 70); i++)
			{
				if (Tiles[x + i][y + i].Occupant != nullptr)
				{
					return false;
				}
			}
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
	}
	return false;
}