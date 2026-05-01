#pragma once	
#include"Behavior.h"
#include<iostream>
class InitializeCam : public BehaviorAdapter {
public:
	int width, height;
	InitializeCam(int in_w, int in_h) : width(in_w), height(in_h) {}

	void Initializer() {
		Engine::cam.offset = Vector2(width/2, height/2);
		Engine::cam.rotation = 0.0f;
		Engine::cam.zoom = 1.0f;
	}

	void Start() override {
		Initializer();
	}

	void Update() override {
	
	}


};