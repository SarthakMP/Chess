#pragma once

#include<Behavior.h>
#include<Mouse.h>
#include<TileLoader.h>


class Collision : public BehaviorAdapter {

public:
	Collision() {}

	Point ScreenToCoord() {
		Vector2 CoorToIndex = { Mouse::MouseScreenPos.x / Tile::tile_w - 1 ,Mouse::MouseScreenPos.y / Tile::tile_h - 1 }; // -1 for [1,8] -> [0,7] 
		return Point(CoorToIndex);
	}
	Point indx;
	void OnMouseDown() override {
		indx = ScreenToCoord();
	}
	void OnMouseUp() override {

		if (Engine::_isDragStarted) {

		}

		Engine::_isDragStarted = false;
	}
	void OnMouseDrag() override {
		Engine::_isDragStarted = true;
		Piece PickedUpPiece = PiecePlacer::FinalPieceOutput[indx.y][indx.x];
		Rectangle src = Rectangle(0, 0, PickedUpPiece._icon.width, PickedUpPiece._icon.height);
		Rectangle dest = Rectangle(0, 0, 100, 100);

		DrawTexturePro(PickedUpPiece._icon, src, dest, Vector2(Mouse::MouseScreenPos.x -450, Mouse::MouseScreenPos.y -450), 180, WHITE);
		
	}

	int ClampInt(int value, int min, int max) {
		return (value <= min) ? min : (value >= max) ? max: value;
	}

	void Start() override {

	}
	
	void Update() override {
		Vector2 LocalMousePos = Mouse::MouseScreenPos;
		Point tmp_Pos = Point(LocalMousePos);
		LocalMousePos = { LocalMousePos.x / Tile::tile_w,LocalMousePos.y / Tile::tile_h };

		int coord_x = ClampInt(LocalMousePos.x, 1, 8);
		int coord_y = ClampInt(-LocalMousePos.y, -8, -1);
		
		DrawRectanglePro(Tile::Tiles[(coord_x - 1) + 8 * (-coord_y - 1)], {0,0}, 0, GetColor(0xa9a9a973));


	

	}

};