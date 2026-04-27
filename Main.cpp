#include "Behavior.h"
#include "TileLoader.h"
#include "InitializeCamera.h"
int main()
{
	int scr_width = 1000;
	int scr_height = 1000;

	InitWindow(1000, 1000, "Chess");
	Engine game;

	Tile TileLoader;
	InitializeCam Icam(scr_width, scr_height);

	game.AddObjects(&TileLoader);
	game.AddObjects(&Icam);
	
	game.Run();
	
	

	return 0;
}
