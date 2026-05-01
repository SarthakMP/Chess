#pragma once

#include<Behavior.h>
#include<Point.h>


class Mouse : public BehaviorAdapter {

public:
	static inline Vector2 MouseScreenPos;

	static inline Vector2 ScreenToWorld(Vector2 screen, const Camera2D cam) {
		Vector2 world = Vector2(0,0);
		world.x = (screen.x);
		world.y = (2*cam.offset.y - screen.y);

		return world;
	}

	void Start() override {
		MouseScreenPos = Vector2(0, 0);
	}
	void Update() override {
		MouseScreenPos = ScreenToWorld(GetMousePosition(),Engine::GetCamera());
		//MouseScreenPos.y = -MouseScreenPos.y + 1000;
		//std::cout << MouseScreenPos.x << "," << MouseScreenPos.y << std::endl;
		//DrawCircle(0 , 0, 100, BLACK);
	}

};