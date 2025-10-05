#include "ENGINE/SCENE.HPP"

SCENE::SCENE(/* args */) {}

SCENE::~SCENE() {}


void SCENE::Update(double a_deltaTime) {
	for (auto& node : this->nodes) {
		node->Update(a_deltaTime, this);
	}
}
void SCENE::Render() {
	for (auto& node : this->nodes) {
		node->Render();
	}
}