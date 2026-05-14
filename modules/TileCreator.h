#pragma once
#include"Behaviour.h"
#include<vector>
static class Tile :public Behaviour_adapter
{

private:

	std::vector<std::vector<Rectangle>> tile_blocks;
public:

	static const int tile_h = 100;
	static const int tile_w = 100;

private:
	void MakeGird(std::vector<std::vector<Rectangle>>& tiles) {
		for (size_t r = 0; r < 8; r++) {
			for (size_t c = 0; c < 8; c++) {
				int x = (c - 4) * tile_h;
				int y = (r - 4) * tile_w;
				Rectangle Tile = Rectangle(x,y, tile_w, tile_h);
				tiles[r][c] = Tile;
			}
		}
	}

	void DrawGrid() {
		static int r_counter = 0, c_counter = 0;
		for (auto& rows : tile_blocks) {
			for (Rectangle tile : rows) {
				DrawRectangleRec(tile, (r_counter + c_counter) % 2 == 0 ? BROWN : BEIGE);
				c_counter++;
			}
			r_counter++;
		}
		r_counter = 0;
		c_counter = 0;
	}


	void Start() override {
		tile_blocks.assign(8, std::vector<Rectangle>(8));
		MakeGird(tile_blocks);
	}

	
	
	void Update() override {
		DrawGrid();
	}

};