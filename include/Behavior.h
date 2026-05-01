#pragma once
#include "raylib.h"
#include<vector>
#include<string>

class Behavior {
public:
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void OnMouseDown() = 0;
    virtual void OnMouseUp() = 0;
    virtual void OnMouseDrag() = 0;

};

class BehaviorAdapter : public Behavior {
public:
    void Start() override {}
    void Update() override {}
    void OnMouseDown() override {}
    void OnMouseUp() override {}
    void OnMouseDrag() override {}
};

class Engine {

    std::vector<Behavior*> objects;
   

public:
    static inline bool  _isDragStarted = false;
    enum en_Piece
    {
        B_KING = 16,
        B_QUEEN = 15,
        B_BISHOP = 14,
        B_KNIGHT = 13,
        B_ROOK = 12,
        B_PAWN = 11,
       
        W_KING = 6,
        W_QUEEN = 5,
        W_BISHOP = 4,
        W_KNIGHT = 3,
        W_ROOK = 2,
        W_PAWN = 1,

        NON = 0
    };

    static inline Camera2D cam = {0};
    static inline std::vector<std::vector<Engine::en_Piece>> Pos_matrix;
    
    void AddObjects(Behavior* obj) { objects.push_back(obj); }
    
    const Camera2D GetCamera() { return cam; }

    void Run() {
        for (auto obj : objects) obj->Start();
        
		while (!WindowShouldClose()) {
           
            BeginDrawing();
                ClearBackground(WHITE);
                BeginMode2D(cam);
                for (auto obj : objects) {
                    if (IsMouseButtonPressed(0)) {
                        obj->OnMouseDown();
                    }
                    if (IsMouseButtonReleased(0)) {
                        obj->OnMouseUp();
                    }

                    if (IsMouseButtonDown(0) && (GetMouseDelta().x != 0 || GetMouseDelta().y != 0)) {
                        obj->OnMouseDrag();
                    }

                    obj->Update();  
                }
                EndMode2D();
			EndDrawing();
			_sleep(1);
		}

    }


};