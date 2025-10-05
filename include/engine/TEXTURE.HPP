#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "glad/glad.h"

#include "engine/SHADER.HPP"

class TEXTURE
{
 private:
   GLuint ID;
 public:
   TEXTURE(const char* a_path);
   void Use();
   ~TEXTURE();
};

#endif