#include "King.h"

King::King(std::string StartingTile, char team) : ChessPiece(StartingTile, team)
{
	this->PieceTexture.loadFromFile(team == 'W' ? "Images/WhiteKing.png" : "Images/BlackKing.png");
	this->PieceSprite.setTexture(this->PieceTexture);
}

bool King::IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y)
{
	int thisx = (this->OccupantOf->TileRectangle.left - 45) / 70;
	int thisy = (this->OccupantOf->TileRectangle.top - 45) / 70;
	bool IsAttacking = false;

	if (thisy == y) // CASTLING
	{
		if (thisx == x - 2 && Tiles[x + 1][y].Occupant != nullptr) // CASTLING DOPRAVA
		{		
			if (!this->HasMoved && !Tiles[x + 1][y].Occupant->HasMoved)
			{
				this->IsCastling = 1;
				for (int i = 0; i < 2; i++)
				{
					if (Tiles[x - i][y].Occupant != nullptr)
					{
						this->IsCastling = 0;
					}
				}
			}
		}
		else if (thisx == x + 2 && Tiles[x - 2][y].Occupant != nullptr) // CASTLING DOLEVA
		{
			if (!this->HasMoved && !Tiles[x - 2][y].Occupant->HasMoved)
			{
				this->IsCastling = -2;
				for (int i = 0; i < 2; i++)
				{
					if (Tiles[x + i][y].Occupant != nullptr)
					{
						this->IsCastling = 0;
					}
				}
				if (Tiles[x - 1][y].Occupant != nullptr)
					this->IsCastling = 0;
			}
		}
	}

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

	if ((abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) == 70 || abs(this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left) == 0) && (abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) == 70 || abs(this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top) == 0))
	{
		if (IsAttacking)
			Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
		return true;
	}

	return false;
}