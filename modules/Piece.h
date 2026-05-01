#include"Behavior.h"

class Piece : public BehaviorAdapter {
	
	

public:	
	static inline std::vector<std::vector<Piece>> FinalPieceOutput;
	Vector2 _Pos = Vector2(0,0);
	Engine::en_Piece _type = Engine::en_Piece(0);
	std::string _name;
	Texture2D icon;

};