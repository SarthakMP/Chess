#pragma once
#include<Behavior.h>
#include<IconLoader.h>
#include<TileLoader.h>
#include<Mouse.h>

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

	std::vector<Piece> StoredPiece;
	
	
	void SetIcons() {
		StoredPiece.reserve(12);
		
		Piece::FinalPieceOutput.assign(8, std::vector<Piece>(8));
		
		int size = IconLoader::Images.size();
		for (size_t i = 0; i < size; i++) {
			Piece p;
			if (ExtractPieceName(IconLoader::ImagesPaths[i])[0] == "black") {
				p.icon = IconLoader::Images[i];
				p._name = ExtractPieceName(IconLoader::ImagesPaths[i])[1];
				StoredPiece.push_back(p);
				
			}
			else {
				p.icon = IconLoader::Images[i];
				p._name = ExtractPieceName(IconLoader::ImagesPaths[i])[1];
				StoredPiece.push_back(p);
			}

		}

		for (size_t r = 0; r < Engine::Pos_matrix.size(); r++) {
			
			for (size_t c = 0; c < Engine::Pos_matrix[r].size(); c++)
			{	
				switch (Engine::Pos_matrix[r][c]) {
					
					case Engine::B_BISHOP: {
						StoredPiece[0]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] = (StoredPiece[0]);
						break;
					}
					case Engine::B_KING: {
						StoredPiece[1]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] = (StoredPiece[1]);
						break;
					}
					case Engine::B_KNIGHT: {
						StoredPiece[2]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[2]);
						break;
					}
					
					case Engine::B_PAWN: {
						StoredPiece[3]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[3]);
						break;
					}
					case Engine::B_QUEEN: {
						StoredPiece[4]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[4]);
						break;
					}
					case Engine::B_ROOK: {
						StoredPiece[5]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[5]);
						break;
					}
					
					case Engine::W_BISHOP: {
						
						StoredPiece[6]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] = (StoredPiece[6]);
						break;
					}
					case Engine::W_KING: {
						StoredPiece[7]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] = (StoredPiece[7]);
						break;
					}
					case Engine::W_KNIGHT: {
						StoredPiece[8]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[8]);
						break;
					}
					
					case Engine::W_PAWN: {
						StoredPiece[9]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[9]);
						break;
					}
					case Engine::W_QUEEN: {
						StoredPiece[10]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[10]);
						break;
					}
					case Engine::W_ROOK: {
						StoredPiece[11]._Pos = Tile::Pieces_pos[r][c];
						Piece::FinalPieceOutput[r][c] =(StoredPiece[11]);
						break;
					}


				}
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

		for (size_t r = 0; r < Engine::Pos_matrix.size(); r++) {

			for (size_t c = 0; c < Engine::Pos_matrix[r].size(); c++)
			{
				//TODO Dragging of Objects

				Piece p = Piece::FinalPieceOutput[r][c];
				src = Rectangle(0, 0, p.icon.height, p.icon.width);
				
				dest = Rectangle(0, 0, 100, 100);
				DrawTexturePro(p.icon, src, dest, { p._Pos.x + 100,p._Pos.y + 100 }, 0.0f, WHITE);
			}
		}
	}

};