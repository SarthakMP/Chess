#pragma once
#include<Behavior.h>
#include<IconLoader.h>
#include<TileLoader.h>
#include<Mouse.h>
#include<unordered_map>


class PiecePlacer : public BehaviorAdapter {
public:
	static inline std::vector<std::vector<Piece>> Pos_matrix;
private:	



	void Postion() {
		
		for (size_t r = 0; r < 8; r++) {
			for (size_t c = 0; c < 8; c++)
			{
				Piece p = Piece();
				if (r >= 2 && r <= 5) { 
					p._type = Engine::NON; 
				}

				if (r < 2) { //BLACK
					
					if (r == 0) {
						if (c == 0 || c == 7) {
							p._type = Engine::B_ROOK;

						}
						else if (c == 1 || c == 6) {
							p._type = Engine::B_KNIGHT;
						}
						else if (c == 2 || c == 5) {
							p._type = Engine::B_BISHOP;
						}
						else if (c == 3) {
							p._type = Engine::B_QUEEN;
						}
						else if (c == 4) {
							p._type = Engine::B_KING;
						}

					}
					else if (r == 1) {
						p._type = Engine::B_PAWN;
					}
					
				}

				if (r > 5) { //WHITE
					if (r == 7) {
						if (c == 0 || c == 7) {
							p._type = Engine::W_ROOK;

						}
						else if (c == 1 || c == 6) {
							p._type = Engine::W_KNIGHT;
						}
						else if (c == 2 || c == 5) {
							p._type = Engine::W_BISHOP;
						}
						else if (c == 3) {
							p._type = Engine::W_QUEEN;
						}
						else if (c == 4) {
							p._type = Engine::W_KING;
						}

					}
					else if(r ==6) {
						p._type = Engine::W_PAWN;
					}
				}

				p._icon = PieceTextures[p._type];
				p._Pos = Tile::Pieces_pos[r][c];
				Pos_matrix[r][c] = p;
			}

		}

	}

public:
	static inline void PrintPosMatrix() {
		for (size_t r = 0; r < 8; r++) {

			for (size_t c = 0; c < 8; c++)
			{
				std::cout << Pos_matrix[r][c]._Pos << " ";
			}
			std::cout << "\n";
		}
	}

private:

	std::unordered_map<Engine::en_Piece, Texture2D> PieceTextures;

	void SetIcons() {

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
		
	}

	void PositionMatrixMaker() {
		Pos_matrix.assign(8, std::vector<Piece>(8));
		SetIcons();
		Postion();
	}


	int coord_x = 0, coord_y = 0;
	void OnMouseDown() override {
		Point indx = Mouse::ScreenToCoord(Mouse::MouseScreenPos.x, Mouse::MouseScreenPos.y);
		coord_x = Engine::ClampInt(indx.x, 0, 7);
		coord_y = Engine::ClampInt(indx.y, 0, 7);
	}

	void Start() override {
		PositionMatrixMaker();
	}
	void Update() override {
		
		for (size_t r = 0; r <8; r++) {

			for (size_t c = 0; c <8; c++)
			{
				
				Piece* p = &Pos_matrix[r][c];
				Rectangle src = Rectangle(0, 0, p->_icon.width, p->_icon.height);
				Rectangle dest = Rectangle(0, 0, 100, 100);
				if (Pos_matrix[r][c].isDragging == false) {
					DrawTexturePro(p->_icon, src, dest, Vector2(p->_Pos.x + 100, p->_Pos.y + 100), 180, WHITE);
				}

			}
		}


	}

	void OnDestroy() override {

	}

};