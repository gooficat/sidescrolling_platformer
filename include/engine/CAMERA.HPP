#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

#include "NODE.HPP"
#include "SHADER.HPP"

class CAMERA : public SPATIAL
{
 private:
   glm::mat4 view, projection;
   SHADER* shader;

 protected:

 public:
   glm::vec3 dirUp, dirFront;
   
   glm::vec3 up;
   bool targetMode;
   CAMERA(SHADER* a_shader);
   void SetPerspective(float a_fov, float a_aspect, float a_near, float a_far);
   // void SetOrthographic(uint16_t a_left, uint16_t a_right, uint16_t a_bottom, uint16_t a_top,
   // uint16_t a_near, uint16_t a_far);
   void SetOrthographic(float a_left, float a_right, float a_bottom, float a_top, float a_near,
                        float a_far);
   ~CAMERA();
   void Update(double a_deltaTime, SCENE* a_scene);
   void Render();
};

#endif