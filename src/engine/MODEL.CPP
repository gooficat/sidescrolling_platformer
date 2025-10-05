#include "engine/MODEL.HPP"

MODEL::MODEL(MESH* a_mesh, SHADER* a_shader, TEXTURE* a_texture) : mesh(a_mesh), shader(a_shader), texture(a_texture) {}

MODEL::~MODEL() {}

void MODEL::Render()
{
   this->shader->Use();
   this->texture->Use();
   glm::mat4 matrix = this->transform.GetMatrix();
   shader->SetMat4(matrix, "model");
   this->mesh->Draw();
}

void MODEL::Update(double, SCENE*) {}