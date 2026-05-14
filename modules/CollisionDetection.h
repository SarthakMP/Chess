#pragma once

#include<Behavior.h>
#include<Mouse.h>
#include<TileLoader.h>
#include<Piece.h>

class Collision : public BehaviorAdapter {

public:
	Collision() {}
	


	Point indx;
	Piece* PickedUpPiece;
	Vector2 DroppedPos;
	Vector2 zero = Vector2(0, 0);
	
	void OnMouseDown() override {
		indx = Mouse::ScreenToCoord(Mouse::MouseScreenPos.x, Mouse::MouseScreenPos.y);
		indx.x = Engine::ClampInt(indx.x, 0, 7);
		indx.y = Engine::ClampInt(indx.y, 0, 7);

	}
	void OnMouseUp() override {
		
		if (Engine::_isDragStarted) {
			Point LocalMousePos = Mouse::ScreenToCoord(Mouse::MouseScreenPos.x, Mouse::MouseScreenPos.y); //100 tiles width/height 5* to match the screen W and H
			
			Point ClampedCoords = Point(Engine::ClampInt(LocalMousePos.x, 0, 7), Engine::ClampInt(LocalMousePos.y, 0, 7));
			PiecePlacer::Pos_matrix[indx.y][indx.x].isDragging = false;
			Engine::Swap(&PiecePlacer::Pos_matrix[indx.y][indx.x], &PiecePlacer::Pos_matrix[ClampedCoords.y][ClampedCoords.x]);

		}
		Engine::_isDragStarted = false;
	}
	void OnMouseDrag() override {
		Point LocalMousePos = Point(Mouse::MouseScreenPos.x, Mouse::MouseScreenPos.y) - Tile::tile_w*4.5f;
		//std::cout << LocalMousePos << std::endl;
		
		PickedUpPiece = &PiecePlacer::Pos_matrix[indx.y][indx.x];
		if (PickedUpPiece->_type == Engine::NON) return;
		Rectangle src = Rectangle(0, 0, PickedUpPiece->_icon.width, PickedUpPiece->_icon.height);
		Rectangle dest = Rectangle(0, 0, 100, 100);
		
		DrawTexturePro(PickedUpPiece->_icon, src, dest, Vector2(LocalMousePos.x, LocalMousePos.y), 180, WHITE);
		PiecePlacer::Pos_matrix[indx.y][indx.x].isDragging = true;
		


	}



	void Start() override {

	}
	long int counter = 0;
	void Update() override {

		Vector2 LocalMousePos = Mouse::MouseScreenPos;
		Point tmp_Pos = Point(LocalMousePos);
		LocalMousePos = { LocalMousePos.x / Tile::tile_w,LocalMousePos.y / Tile::tile_h };

		int coord_x = Engine::ClampInt(LocalMousePos.x, 1, 8);
		int coord_y = Engine::ClampInt(-LocalMousePos.y, -8, -1);
		
		DrawRectanglePro(Tile::Tiles[(coord_x - 1) + 8 * (-coord_y - 1)], { 0,0 }, 0, GetColor(0xa9a9a973));
		
	}

};