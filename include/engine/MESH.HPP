#ifndef MESH_HPP
#define MESH_HPP

#include "glad/glad.h"

#include <vector>

#include "engine/SHADER.HPP"


struct Vertex
{
   glm::vec3 position;
   glm::vec2 texCoord;
   glm::vec3 normal;
};


class MESH
{
 private:
   GLuint VAO, VBO;
   size_t vertexCount;
   GLenum drawMode;
   void genMesh(std::vector<Vertex>& a_vertices, GLenum a_drawMode);
 public:
   MESH(std::vector<Vertex>& a_vertices, GLenum a_drawMode);
   
   MESH(std::string a_path);
   ~MESH();
   void Draw();
};


#endif