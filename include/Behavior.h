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
    
     
public:
    void AddObjects(Behavior* obj) { objects.push_back(obj); }

    void Run() {
        for (auto obj : objects) obj->Start();
		while (!WindowShouldClose()) {
			BeginDrawing();
            ClearBackground(WHITE);

            for (auto obj : objects) obj->Update();

			EndDrawing();
			_sleep(1);
		}

    }


};