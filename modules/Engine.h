#pragma once
#include"Behaviour.h"
#include<vector>
static class Engine : Behaviour_adapter {

private:

	Camera2D cam;

	int ObjCount = 0;
	std::vector<Behaviour*> ObjList;
public:
	static const int screenwidth = 800;
	static const int screenHeight = 800;


	void AddObjects(Behaviour* obj) {
		ObjCount++;
		ObjList.reserve(ObjCount);
		ObjList.push_back(obj);
	}

	void InitializeWindow(){
		InitWindow(screenwidth, screenHeight, "Chess");
		SetTargetFPS(30);
	}

	void InitializeCam(){
		cam.offset = Vector2(screenwidth / 2, screenHeight / 2);
		cam.target = Vector2(0, 0);
		cam.rotation = 0;
		cam.zoom = 1.0f;
	}

	void Run() {
		InitializeWindow();
		InitializeCam();

		for (auto obj : ObjList) {obj->Start();}

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(GetColor(0xa9a9a973));
			BeginMode2D(cam);
				rlPushMatrix();
					rlEnableBackfaceCulling();
						rlScalef(1.0f, -1.0f, 1.0f);
						
						for (auto obj : ObjList) { obj->Update(); }

					rlDisableBackfaceCulling();
				rlPopMatrix();
			EndMode2D();

			EndDrawing();


		}
	}

};
