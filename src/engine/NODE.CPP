#include "engine/NODE.HPP"

NODE::NODE() {}

void NODE::Update(double, SCENE*) {}
void NODE::Render() {}

SPATIAL::SPATIAL() : NODE() {
	this->transform.position = {0, 0, 0};
	this->transform.rotation = {0, 0, 0};
}

void SPATIAL::Update(double, SCENE*) {}
void SPATIAL::Render() {}