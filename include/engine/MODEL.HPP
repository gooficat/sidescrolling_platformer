#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>

#include "engine/PREDEF.HPP"

#include "engine/MESH.HPP"
#include "engine/NODE.HPP"
#include "engine/SHADER.HPP"

#include "engine/TEXTURE.HPP"

class MODEL : public SPATIAL
{
 protected:
   MESH* mesh;
 public:
   SHADER* shader;
   TEXTURE* texture;
   MODEL(MESH* a_mesh, SHADER* a_shader, TEXTURE* a_texture);
   void Update(double a_deltaTime, SCENE* a_parent);
   void Render();
   ~MODEL();
};

#endif