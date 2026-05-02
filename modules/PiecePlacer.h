#pragma once
#include<Behavior.h>
#include<IconLoader.h>
#include<TileLoader.h>
#include<Mouse.h>
#include<unordered_map>

class PiecePlacer : public BehaviorAdapter {

	
	void Postion() {
		
		Engine::Pos_matrix = {
			{Engine::B_ROOK ,Engine::B_KNIGHT,Engine::B_BISHOP, Engine::B_KING, Engine::B_QUEEN,Engine::B_BISHOP,Engine::B_KNIGHT,Engine::B_ROOK},
			{Engine::B_PAWN,Engine::B_PAWN,Engine::B_PAWN,Engine::B_PAWN,Engine::B_PAWN,Engine::B_PAWN,Engine::B_PAWN,Engine::B_PAWN},
			{Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON},
			{Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON},
			{Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON},
			{Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON,Engine::NON},
			{Engine::W_PAWN,Engine::W_PAWN,Engine::W_PAWN,Engine::W_PAWN,Engine::W_PAWN,Engine::W_PAWN,Engine::W_PAWN,Engine::W_PAWN},
			{Engine::W_ROOK ,Engine::W_KNIGHT,Engine::W_BISHOP, Engine::W_KING, Engine::W_QUEEN,Engine::W_BISHOP,Engine::W_KNIGHT,Engine::W_ROOK},
		};

	}
	

	std::vector<std::string> ExtractPieceName(std::string path) {
		std::string trimmed_path ="";
		bool _split = false;
		for (char c : path) { //trimming the path
			if (c == '\\') {
				_split = true;
				continue;
			}

			if (_split) {
				if (c != '.')
					trimmed_path += c;
				else
					break;
			}

		}
		_split = false;
		std::string piece_type="";
		std::string piece_color = "";
		for (char c : trimmed_path) {//trimmed name
			if (c == '-') {
				_split = true;
				continue;
			}
			else if (c != '-' && _split == false) {
				piece_color += c;
			}

			if (_split) {
				piece_type += c;
			}

		}


		return { piece_color,piece_type};
	}

public:
	static inline std::vector<std::vector<Piece>> FinalPieceOutput;
private:

	std::unordered_map<Engine::en_Piece, Texture2D> PieceTextures;

	void SetIcons() {

		
		FinalPieceOutput.assign(8, std::vector<Piece>(8));
		
		PieceTextures[Engine::B_PAWN] = LoadTexture("../../../res/Icons/black-pawn.png");
		PieceTextures[Engine::B_ROOK] = LoadTexture("../../../res/Icons/black-rook.png");
		PieceTextures[Engine::B_KNIGHT] = LoadTexture("../../../res/Icons/black-knight.png");
		PieceTextures[Engine::B_BISHOP] = LoadTexture("../../../res/Icons/black-bishop.png");
		PieceTextures[Engine::B_QUEEN] = LoadTexture("../../../res/Icons/black-queen.png");
		PieceTextures[Engine::B_KING] = LoadTexture("../../../res/Icons/black-king.png");

		PieceTextures[Engine::W_PAWN] = LoadTexture("../../../res/Icons/white-pawn.png");
		PieceTextures[Engine::W_ROOK] = LoadTexture("../../../res/Icons/white-rook.png");
		PieceTextures[Engine::W_KNIGHT] = LoadTexture("../../../res/Icons/white-knight.png");
		PieceTextures[Engine::W_BISHOP] = LoadTexture("../../../res/Icons/white-bishop.png");
		PieceTextures[Engine::W_QUEEN] = LoadTexture("../../../res/Icons/white-queen.png");
		PieceTextures[Engine::W_KING] = LoadTexture("../../../res/Icons/white-king.png");
		
		for (int r = 7; r >=0; r--) {
			for (size_t c = 0; c < 8; c++) {

				Engine::en_Piece type = Engine::Pos_matrix[7-r][c];

				FinalPieceOutput[r][c] = Piece(type, Tile::Pieces_pos[r][c], PieceTextures[type]);
				
			}

		}
	

	}

	void PositionMatrixMaker() {
		Engine::Pos_matrix.reserve(64);
		Postion();
		SetIcons();
	}

	void Start() override {
		PositionMatrixMaker();

	}
	Rectangle src, dest;
	void Update() override {

		for (size_t r = 0; r <8; r++) {

			for (size_t c = 0; c <8; c++)
			{
				Piece p = FinalPieceOutput[r][c];
				Rectangle src = Rectangle(0, 0, p._icon.width, p._icon.height);
				Rectangle dest = Rectangle(0, 0, 100, 100);
				DrawTexturePro(p._icon, src, dest, Vector2(p._Pos.x +100, p._Pos.y +100), 180, WHITE);

			}
		}
	}

};