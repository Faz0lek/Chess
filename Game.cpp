#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Board.h"
#include "VoiceControl.h"


using namespace sf;

Game::Game()
{
	RenderWindow window(VideoMode(650, 650), "Chess!", Style::Default); // Nastaveni okna
	this->Icon.loadFromFile("Images/Icon.png");
	window.setIcon(256, 256, this->Icon.getPixelsPtr());
	Board Board1; // Hraci plocha
	VoiceControl VoiceInput;

	bool SelectingPiece = true;
	this->WhiteTurn = true;

	while (window.isOpen())
	{
		// Logovani hry + debug v konzoli
		VoiceInput.Init();

		if (VoiceInput.Move != VoiceInput.LastMove)
		{
			if (Board1.TileMap[VoiceInput.From]->Occupant->team == 'W' && WhiteTurn || Board1.TileMap[VoiceInput.From]->Occupant->team == 'B' && !WhiteTurn)
			{
				Board1.MovingPiece = Board1.TileMap[VoiceInput.From]->Occupant;

				int x = (Board1.TileMap[VoiceInput.To]->TileRectangle.left - 45) / 70;
				int y = (Board1.TileMap[VoiceInput.To]->TileRectangle.top - 45) / 70;

				if (Board1.MovingPiece->IsLegalMove(Board1.Tiles, x, y))
				{
					this->WhiteTurn = !WhiteTurn;
					Board1.MovingPiece->OccupantOf->Occupant = nullptr;
					Board1.MovingPiece->OccupantOf = &Board1.Tiles[x][y];
					Board1.Tiles[x][y].Occupant = Board1.MovingPiece;
					Board1.MovingPiece->PieceSprite.setPosition(Board1.Tiles[x][y].TileRectangle.left, Board1.Tiles[x][y].TileRectangle.top);
					Board1.MovingPiece = nullptr;
				}

				VoiceInput.LastMove = VoiceInput.Move;
			}
		}

		Vector2i MousePosition = Mouse::getPosition(window); // Aktualni pozice mysi relativne k hernimu oknu

		Event e; // Fronta udalosti

		// Event loop, provadi se dokud neni fronta prazdna
		while (window.pollEvent(e))
		{
			// Zavreni okna a ukonceni programu
			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					if (SelectingPiece)
					{
						for (int i = 0; i < 16; i++)
						{
							if (Board1.WhiteTeam[i]->PieceSprite.getGlobalBounds().contains(MousePosition.x, MousePosition.y) && this->WhiteTurn)
							{
								Board1.MovingPiece = Board1.WhiteTeam[i];
								SelectingPiece = false;
							}
							else if (Board1.BlackTeam[i]->PieceSprite.getGlobalBounds().contains(MousePosition.x, MousePosition.y) && !this->WhiteTurn)
							{
								Board1.MovingPiece = Board1.BlackTeam[i];
								SelectingPiece = false;
							}
						}
					}
					else
					{
						for (int x = 0; x < 8; x++)
						{
							for (int y = 0; y < 8; y++)
							{
								if (Board1.Tiles[x][y].TileRectangle.contains(MousePosition.x, MousePosition.y))
								{
									if (Board1.MovingPiece->IsLegalMove(Board1.Tiles, x, y))
									{
										Board1.MovingPiece->HasMoved = true;
										this->WhiteTurn = !WhiteTurn;
										Board1.MovingPiece->OccupantOf->Occupant = nullptr;
										Board1.MovingPiece->OccupantOf = &Board1.Tiles[x][y];
										Board1.Tiles[x][y].Occupant = Board1.MovingPiece;
										Board1.MovingPiece->PieceSprite.setPosition(Board1.Tiles[x][y].TileRectangle.left, Board1.Tiles[x][y].TileRectangle.top);
									}
									else if (Board1.MovingPiece->IsCastling)
									{								
										this->WhiteTurn = !WhiteTurn;

										Board1.MovingPiece->HasMoved = true;
										Board1.MovingPiece->OccupantOf->Occupant = nullptr;
										Board1.MovingPiece->OccupantOf = &Board1.Tiles[x][y];
										Board1.Tiles[x][y].Occupant = Board1.MovingPiece;

										Board1.Tiles[x + Board1.MovingPiece->IsCastling][y].Occupant->HasMoved = true;
										Board1.Tiles[x + Board1.MovingPiece->IsCastling][y].Occupant->OccupantOf = &Board1.Tiles[Board1.MovingPiece->IsCastling == 1 ? x - 1 : x + 1][y];
										Board1.Tiles[x + Board1.MovingPiece->IsCastling][y].Occupant->PieceSprite.setPosition(Board1.Tiles[Board1.MovingPiece->IsCastling == 1 ? x - 1 : x + 1][y].TileRectangle.left, Board1.Tiles[Board1.MovingPiece->IsCastling == 1 ? x - 1 : x + 1][y].TileRectangle.top);
										Board1.Tiles[Board1.MovingPiece->IsCastling == 1 ? x - 1 : x + 1][y].Occupant = Board1.Tiles[x + Board1.MovingPiece->IsCastling][y].Occupant;
										Board1.Tiles[x + Board1.MovingPiece->IsCastling][y].Occupant = nullptr;
										
										
										Board1.MovingPiece->PieceSprite.setPosition(Board1.Tiles[x][y].TileRectangle.left, Board1.Tiles[x][y].TileRectangle.top);
									}
								}
							}
						}
						Board1.MovingPiece = nullptr;
						SelectingPiece = true;
					}
				}
			}
		}

		window.clear(); // Vymazani obrazu pro render noveho snimku	
		window.draw(Board1.BoardSprite); // Render hraci plochy

		// Render figurek
		for (int i = 0; i < 16; i++)
		{
				window.draw(Board1.WhiteTeam[i]->PieceSprite);
				window.draw(Board1.BlackTeam[i]->PieceSprite);
		}

		window.display(); // Zobrazení na monitor
		VoiceInput.Save();
	}
}