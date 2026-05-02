#pragma once
#include "raylib.h"
#include "rlgl.h"
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
    static inline Font font;
    
    void LoadFont() {
        font = LoadFontEx("./res/SF-Pro.ttf",20,0,0);
    }
    void AddObjects(Behavior* obj) { objects.push_back(obj); }
    
    const static Camera2D GetCamera() { return cam; }
    
    Vector2 dragStart;

    void Run() {
        for (auto obj : objects) obj->Start();
        
		while (!WindowShouldClose()) {
           
            BeginDrawing();
                ClearBackground(RAYWHITE);
                BeginMode2D(cam);
                rlPushMatrix();
                    rlDisableBackfaceCulling();
                
                    rlScalef(1.0f, -1.0f, 1.0f);
                    
                    
                        for (auto obj : objects) {
                            if (IsMouseButtonPressed(0)) {
                                dragStart = GetMousePosition();
                                _isDragStarted = false;
                                obj->OnMouseDown();
                            }
                            if (IsMouseButtonReleased(0)) {
                                obj->OnMouseUp();
                            }

                            if (IsMouseButtonDown(0) ) {
                                Vector2 current = GetMousePosition();

                                float dist = sqrtf(
                                    (current.x - dragStart.x) * (current.x - dragStart.x) +
                                    (current.y - dragStart.y) * (current.y - dragStart.y)
                                );

                                if (dist > 5.0f || _isDragStarted) {
                                    _isDragStarted = true;
                                    obj->OnMouseDrag();
                                }
                                
                            }

                            obj->Update();  
                        }
                    
                    
                   
                    

                    rlPopMatrix();
                EndMode2D();
                
			EndDrawing();
			_sleep(1);
		}

    }


};