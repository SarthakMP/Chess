#pragma once

#include<Behavior.h>
#include<Mouse.h>
#include<TileLoader.h>


class Collision : public BehaviorAdapter {

public:
	Collision() {}

	Point ScreenToCoord() {
		Vector2 CoorToIndex = { Mouse::MouseScreenPos.x / 100 - 1 ,Mouse::MouseScreenPos.y / 100 - 1 }; // -1 for [1,8] -> [0,7] 
		return Point(CoorToIndex);
	}
	Point indx;
	void OnMouseDown() override {
		indx = ScreenToCoord();
	}

	void OnMouseDrag() override {
		Engine::_isDragStarted = true;
		Piece PickedUpPiece = Piece::FinalPieceOutput[indx.y][indx.x];
		
		Rectangle PieceHolder = Rectangle(Mouse::MouseScreenPos.x, Mouse::MouseScreenPos.y, 100, 100);
		
	}

	int ClampInt(int value, int min, int max) {
		return (value <= min) ? min : (value >= max) ? max: value;
	}

	void Start() override {

	}
	
	void Update() override {
		Vector2 LocalMousePos = Mouse::MouseScreenPos;
		LocalMousePos = { LocalMousePos.x / 100,LocalMousePos.y / 100 };

		int coord_x = ClampInt(LocalMousePos.x, 1, 8);
		int coord_y = ClampInt(LocalMousePos.y, 1, 8);
	
		DrawRectanglePro(Tile::Tiles[(coord_x - 1) + 8 * (coord_y - 1)], {0,0}, 0, GetColor(0xa9a9a973));
		//std::cout << (coord_x) + 8 * (coord_y) << std::endl;
		//std::cout << coord_x - 1 <<","<< coord_y -1 << std::endl;

	}

};