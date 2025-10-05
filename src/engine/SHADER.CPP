#include "engine/SHADER.HPP"

GLuint createShader(GLenum a_type, const std::string& a_source) {
	GLuint shader = glCreateShader(a_type);
	std::string source = ReadFileToTxt(a_source);
	const char* source_c = source.c_str();
	glShaderSource(shader, 1, &source_c, NULL);
	glCompileShader(shader);
	return shader;
}

SHADER::SHADER(/* args */) {}

SHADER::~SHADER()
{
   glDeleteProgram(ID);
}

void SHADER::Compile(std::string a_vertexShaderSource, std::string a_fragmentShaderSource) {
	GLuint vertShader = createShader(GL_VERTEX_SHADER, a_vertexShaderSource);
	GLuint fragShader = createShader(GL_FRAGMENT_SHADER, a_fragmentShaderSource);
	this->ID = glCreateProgram();
	glAttachShader(this->ID, vertShader);
	glAttachShader(this->ID, fragShader);
	glLinkProgram(this->ID);
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}
void SHADER::Use() {
	glUseProgram(this->ID);
}
void SHADER::SetMat4(const glm::mat4& a_matrix, const char* a_name) {
	GLint location = glGetUniformLocation(this->ID, a_name);
	glUniformMatrix4fv(location, 1, GL_FALSE, &a_matrix[0][0]);
}