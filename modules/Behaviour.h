#pragma once
#include"raylib.h"
#include"rlgl.h"
#include"Point.h"
static class Behaviour
{
public:
	Behaviour();
	virtual ~Behaviour();

	virtual void Start() = 0;
	virtual void Update() = 0;

private:


};
class Behaviour_adapter : public Behaviour {
	void Start() override {}
	void Update() override {}
};

Behaviour::Behaviour()
{
}

Behaviour::~Behaviour()
{
}

