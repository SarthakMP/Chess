#pragma once

#include<Behavior.h>
#include<Point.h>


class Mouse : public BehaviorAdapter {

public:
	static inline Vector2 MouseScreenPos;


	void Start() override {
		MouseScreenPos = Vector2(0, 0);
	}
	void Update() override {
		MouseScreenPos = GetMousePosition();
	}

};