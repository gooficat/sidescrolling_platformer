#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include "glad/glad.h"

#include <glm/glm.hpp>

#include "engine/UTIL.HPP"

class SHADER
{
 private:
   GLuint ID;

 public:
   SHADER();
   void Compile(std::string a_vertexShaderSource, std::string a_fragmentShaderSource);
   ~SHADER();
   void Use();
   void SetMat4(const glm::mat4& a_matrix, const char* a_name);
};

#endif