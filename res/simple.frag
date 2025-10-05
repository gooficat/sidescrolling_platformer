#version 330 core

precision lowp float;

out vec4 fragColor;

in vec2 texPos;

uniform sampler2D ourTexture;

void main() {
	fragColor = texture(ourTexture, texPos);
}