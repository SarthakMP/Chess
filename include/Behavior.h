#pragma once
#include "raylib.h"
#include<vector>
#include<string>


class Behavior {
public:
    virtual void Start() = 0;
    virtual void Update() = 0;
    
};

class Engine {
    
    std::vector<Behavior*> objects;
    
    void UpdateAllObjects() {
        for (auto obj : objects) obj->Update();
    }

   
public:
    static inline Camera2D cam = {0};
    void AddObjects(Behavior* obj) { objects.push_back(obj); }
    
    const Camera2D GetCamera() { return cam; }

    void Run() {
        for (auto obj : objects) obj->Start();
		while (!WindowShouldClose()) {
           
            BeginDrawing();
                ClearBackground(WHITE);
                BeginMode2D(cam);
                    UpdateAllObjects();
                EndMode2D();
			EndDrawing();
			_sleep(1);
		}

    }


};