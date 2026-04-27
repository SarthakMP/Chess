#include "Behavior.h"
#include "TileLoader.h"
#include "InitializeCamera.h"
int main()
{
	int scr_width = 1000;
	int scr_height = 1000;

	InitWindow(1000, 1000, "Chess");
	Engine game;
	
	Camera2D MainCam2D;

	Tile TitleLoader;
	InitializeCam Icam;
	Icam.Setvalues(MainCam2D, scr_width, scr_height);
	

	game.AddObjects(&TitleLoader);
	game.AddObjects(&Icam);
	
	game.Run();
	
	

	return 0;
}
