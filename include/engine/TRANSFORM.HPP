#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct TRANSFORM
{
   glm::vec3 position;
   glm::vec3 rotation;
   glm::vec3 scale;
   glm::mat4 GetMatrix();
};

#endif