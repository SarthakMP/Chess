#pragma once
#include"Behavior.h"
#include<Point.h>
class Piece : public BehaviorAdapter {
public:	
	Point _Pos = Point(0, 0);
	Engine::en_Piece _type = Engine::en_Piece(0);
	Texture2D _icon;
	bool isDragging = false;

	Piece(Engine::en_Piece type, Point pos,Texture2D icon) {
		_type = type;
		_Pos = pos;
		_icon = icon;
	}
	Piece(Piece* p) {
		p = nullptr;
	}
	Piece() {
		
	}

};