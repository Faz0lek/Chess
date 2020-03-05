#include "Bishop.h"

Bishop::Bishop(std::string StartingTile, char team) : ChessPiece(StartingTile, team)
{
	this->PieceTexture.loadFromFile(team == 'W' ? "Images/WhiteBishop.png" : "Images/BlackBishop.png");
	this->PieceSprite.setTexture(this->PieceTexture);
}

bool Bishop::IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y)
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