#pragma once
#include"Behaviour.h"

#include<iostream>
class Mouse : public Behaviour_adapter
{
	inline Point2D GetGridCoords() {
		return Point2D(GetMousePosition().x, GetMousePosition().y);
	}

	inline void HighlightHover(Point2D& MousePos) {


	}

	void Update() override {
		GetGridCoords();
	}

};


