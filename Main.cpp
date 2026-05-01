#include "Behavior.h"
#include "TileLoader.h"
#include "InitializeCamera.h"
#include "Piece.h"
#include "PiecePlacer.h"
#include "IconLoader.h"
#include "Mouse.h"
#include "CollisionDetection.h"

int main()
{
	
	int scr_width = 1000;
	int scr_height = 1000;

	InitWindow(1000, 1000, "Chess");
	Engine game;

	Tile TileLoader;
	InitializeCam Icam( scr_width, scr_height);
	IconLoader IconL;
	PiecePlacer PieceP;
	Mouse Mouse;
	Collision Col;

	game.AddObjects(&TileLoader);
	game.AddObjects(&Icam);
	game.AddObjects(&IconL);
	game.AddObjects(&PieceP);
	game.AddObjects(&Mouse);
	game.AddObjects(&Col);
	
	
	game.Run();
	
	

	return 0;
}
