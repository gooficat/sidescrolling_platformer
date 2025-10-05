#include "PRIMITIVES.HPP"

MESH* QUAD_PRIMITIVE;
MESH* CUBE_PRIMITIVE;

void INIT_PRIMITIVES() {
	QUAD_PRIMITIVE = new MESH("../res/quad.obj");
	CUBE_PRIMITIVE = new MESH("../res/cube.obj");
}
