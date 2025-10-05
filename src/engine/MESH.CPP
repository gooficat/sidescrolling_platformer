#include "ENGINE/MESH.HPP"

MESH::MESH(std::vector<Vertex>& a_positions, GLenum a_drawMode)
{
   this->genMesh(a_positions, a_drawMode);
}
void MESH::genMesh(std::vector<Vertex>& a_positions,
                   GLenum a_drawMode)
{
   glGenVertexArrays(1, &(this->VAO));
   glGenBuffers(1, &(this->VBO));
   glBindVertexArray(this->VAO);

   glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
   glBufferData(GL_ARRAY_BUFFER, a_positions.size() * sizeof(Vertex), &a_positions[0],
                GL_STATIC_DRAW);

   glEnableVertexAttribArray(0);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

   glEnableVertexAttribArray(1);
   glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                         (void*)(offsetof(Vertex, Vertex::texCoord)));
   this->vertexCount = a_positions.size();
   this->drawMode = a_drawMode;
}

MESH::MESH(std::string a_path)
{
   std::vector<Vertex> vertices;
   std::vector<glm::vec3> positions;
   std::vector<glm::vec2> texCoords;
   std::vector<glm::vec3> normals;
   std::ifstream file(a_path);
   if (file.is_open() == false)
   {
      std::cerr << "Failed to open file: " << a_path << std::endl;
      return;
   }
   std::string line;
   while (std::getline(file, line))
   {
      std::string header = line.substr(0, 2);
      if (header == "v ")
      {
         glm::vec3 v;
         std::sscanf(line.c_str(), "v %f %f %f", &v.x, &v.y, &v.z);
         positions.push_back(v);
      }
      else if (header == "vt")
      {
         glm::vec2 v;
         std::sscanf(line.c_str(), "vt %f %f", &v.x, &v.y);
         texCoords.push_back(v);
      }
      else if (header == "vn")
      {
         glm::vec3 v;
         std::sscanf(line.c_str(), "vn %f %f %f", &v.x, &v.y, &v.z);
         normals.push_back(v);
      }
      else if (header == "f ")
      {
         Vertex v1;
         Vertex v2;
         Vertex v3;
         uint32_t iv[3];
         uint32_t it[3];
         uint32_t in[3];
         std::sscanf(line.c_str(), "f %u/%u/%u %u/%u/%u %u/%u/%u",
            &iv[0], &it[0], &in[0],
            &iv[1], &it[1], &in[1],
            &iv[2], &it[2], &in[2]
         );
         v1.position = positions[iv[0]-1];
         v1.texCoord = texCoords[it[0]-1];
         v1.normal = normals[in[0]-1];

         v2.position = positions[iv[1]-1];
         v2.texCoord = texCoords[it[1]-1];
         v2.normal = normals[in[1]-1];
         
         v3.position = positions[iv[2]-1];
         v3.texCoord = texCoords[it[2]-1];
         v3.normal = normals[in[2]-1];
         vertices.push_back(v1);
         vertices.push_back(v2);
         vertices.push_back(v3);
      }
      else {
         std::cout << line << std::endl;
      }
   }

   this->genMesh(vertices, GL_TRIANGLES);
}

MESH::~MESH()
{
   glDeleteVertexArrays(1, &(this->VAO));
   glDeleteBuffers(1, &(this->VBO));
}

void MESH::Draw()
{
   glBindVertexArray(this->VAO);
   glDrawArrays(this->drawMode, 0, this->vertexCount);
}