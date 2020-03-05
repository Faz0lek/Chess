#include "Knight.h"

Knight::Knight(std::string StartingTile, char team) : ChessPiece(StartingTile, team)
{
	this->PieceTexture.loadFromFile(team == 'W' ? "Images/WhiteKnight.png" : "Images/BlackKnight.png");
	this->PieceSprite.setTexture(this->PieceTexture);
}

bool Knight::IsLegalMove(const std::vector <std::vector <Tile>>& Tiles, const int x, const int y)
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

	for (int i = 0; i < 8; i++)
	{
		if (this->PieceSprite.getPosition().x - Tiles[x][y].TileRectangle.left == Knight::AvailableMoves[i][0] * 70 && this->PieceSprite.getPosition().y - Tiles[x][y].TileRectangle.top == Knight::AvailableMoves[i][1] * 70)
		{
			if (IsAttacking)
				Tiles[x][y].Occupant->PieceSprite.setPosition(-100, -100);
			return true;
		}
	}

	return false;
}


const int Knight::AvailableMoves[8][2] = { { 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };