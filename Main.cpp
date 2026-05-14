#include<iostream>
#include"Engine.h"
#include"TileCreator.h"
#include"MouseHandler.h"
int main() {
	Engine game;
	Tile tiles;
	Mouse mouseMethods;

	game.AddObjects(&tiles);
	game.AddObjects(&mouseMethods);

	game.Run();
}