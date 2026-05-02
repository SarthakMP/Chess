#pragma once
#include"Behavior.h"

class Piece : public BehaviorAdapter {

public:	
	Vector2 _Pos = Vector2(0, 0);
	Engine::en_Piece _type = Engine::en_Piece(0);
	std::string _name;
	Texture2D _icon;

	Piece(Engine::en_Piece type, Vector2 pos,Texture2D icon) {
		_type = type;
		_Pos = pos;
		_icon = icon;
	}
	Piece() {}
	

};