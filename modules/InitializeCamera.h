#pragma once	
#include"Behavior.h"
class InitializeCam : public Behavior  {

	Camera2D cam;
	int width, height;

	void Initializer(Camera2D& cam,int& scr_width,int& scr_height) {

		cam.offset = Vector2(scr_width/2, scr_height/2);
		cam.rotation = 0;
		cam.zoom = 1.0;

	}

	void Start() override {
		
	}

	void Update() override {
		Initializer(cam, width, height);
	}

public:
	void Setvalues(Camera2D& c, int& in_width, int& in_height) {
		cam = c;
		width = in_width;
		height = in_height;
	}

};