#include "engine/CAMERA.HPP"

CAMERA::CAMERA(SHADER* a_shader) : SPATIAL(), shader(a_shader) {}

CAMERA::~CAMERA() {}

void CAMERA::SetPerspective(float a_fov, float a_aspect, float a_near, float a_far)
{
   this->projection = glm::perspective(glm::radians(a_fov), a_aspect, a_near, a_far);
}
// void CAMERA::SetOrthographic(uint16_t a_left, uint16_t a_right, uint16_t a_bottom, uint16_t
// a_top, uint16_t a_near, uint16_t a_far)
// {
//    this->projection = glm::ortho(a_left, a_right, a_bottom, a_top, a_near, a_far);
// }
void CAMERA::SetOrthographic(float a_left, float a_right, float a_bottom, float a_top, float a_near,
                             float a_far)
{
   this->projection = glm::ortho(a_left, a_right, a_bottom, a_top, a_near, a_far);
}

void CAMERA::Update(double, SCENE*)
{
   if (this->targetMode == true)
   {
      this->view = glm::lookAt(this->transform.position, this->transform.position + this->dirFront,
                               this->dirUp);
   }
   else
   {
      this->view = glm::inverse(glm::mat4(1.0f));
      this->view = glm::rotate(this->view, this->transform.rotation.x, {1.0f, 0.0f, 0.0f});
      this->view = glm::rotate(this->view, this->transform.rotation.y, {0.0f, 1.0f, 0.0f});
      this->view = glm::rotate(this->view, this->transform.rotation.z, {0.0f, 0.0f, 1.0f});
      this->view = glm::translate(this->view, -this->transform.position);
   }
}

void CAMERA::Render()
{
   shader->Use();
   shader->SetMat4(this->view, "view");
   shader->SetMat4(this->projection, "projection");
}