#include"Behavior.h"

enum en_Piece
{
	KING = 5,
	QUEEN = 4,
	BISHOP = 3,
	KNIGHT = 2,
	PAWN = 1,
	NON =0
};

class Piece : Behavior {
public:	
	
	Vector2 _Pos = Vector2(0,0);
	en_Piece _type = NON;
	std::string _name;
	Texture2D icon;

};