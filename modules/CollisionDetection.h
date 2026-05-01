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
		Engine::_isDragStarted = false;
	}
	void OnMouseDrag() override {
		Engine::_isDragStarted = true;
		Piece PickedUpPiece = PiecePlacer::FinalPieceOutput[indx.y][indx.x];
		Point orgPos = Point(PickedUpPiece._Pos);
		Point nxtPos = Point(Mouse::MouseScreenPos);
		Rectangle PieceHolder = Rectangle(nxtPos.x - 550, nxtPos.y - 550, Tile::tile_w, Tile::tile_h);
		
		Rectangle src = Rectangle(0, 0, Tile::tile_w, Tile::tile_h);
		
		
		//nxtPos.x = ClampInt(nxtPos.x, 0, 800);
		//nxtPos.y = ClampInt(nxtPos.y, 0, 800);

		DrawTexturePro(PickedUpPiece.icon, src, PieceHolder, Vector2(0, 0), 0, WHITE);
		
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
		//std::cout << tmp_Pos <<std::endl;
		//std::cout << coord_x - 1 <<","<< coord_y +1 << std::endl;

	

	}

};