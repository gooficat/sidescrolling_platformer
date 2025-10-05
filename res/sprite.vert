#version 330 core

precision lowp float;

layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec2 a_tex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform ivec2 spriteOffset;
uniform vec2 spriteScale;

out vec2 texPos;

void main() {
	gl_Position = projection * view * model * vec4(a_pos, 1.0f);
	texPos = a_tex / spriteScale;
}