#pragma once
#include"Behavior.h"
#include<iostream> //DEBUGGING ONLY
static class Tile : public BehaviorAdapter {
	
	Color White = Color(255, 255, 255, 255);
	Color Black = Color(0, 0, 0, 255);
	Color Brown = Color(100, 50, 0, 255);

	

public:
	static const int tile_h = 100, tile_w = 100;
	static inline std::vector<std::vector<Vector2>> Pieces_pos;
	static inline std::vector<Rectangle> Tiles;
private:
	
	
	void CreateTiles() {

		Tiles.reserve(64);
		Pieces_pos.assign(8, std::vector<Vector2>(8, Vector2(0, 0)));

		for (int r = -4; r < 4; r++) {
			for (int c = -4; c < 4; c++) {
				Vector2 pos = { c * 100.0f,r *100.0f};
				std::cout << '[' << pos.x << "," << pos.y<<']' << " ";
				Rectangle Tile = Rectangle(pos.x, pos.y, tile_w-1, tile_h-1);
				Tiles.push_back(Tile);
				Pieces_pos[r + 4][c + 4] = pos;
				
			}std::cout <<"\n";
		}
	}

	void Start() override {
		CreateTiles();
	}

	void Update() override{
		
		
		ClearBackground(GetColor(0x2A4055));

		//Draw the tiles
		for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++)
			{
				//FOR TILES
				Color WorB = (i + j) % 2 == 0 ? Brown : White;
				DrawRectangleRec(Tiles[j + 8 * i], WorB);
			}
		}
		
		
	}


};