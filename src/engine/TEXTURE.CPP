#include "engine/TEXTURE.HPP"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TEXTURE::TEXTURE(const char* a_path)
{
   int width, height, nrChannels;

   unsigned char* data = stbi_load(a_path, &width, &height, &nrChannels, 0);

   glGenTextures(1, &this->ID);
   glBindTexture(GL_TEXTURE_2D, this->ID);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
   glGenerateMipmap(GL_TEXTURE_2D);
}
TEXTURE::~TEXTURE()
{
   glDeleteTextures(1, &this->ID);
}

void TEXTURE::Use()
{
   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, this->ID);
}