#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "MODEL.HPP"
#include "PRIMITIVES.HPP"

#include "GAME.HPP"

class SPRITE : public MODEL
{
private:
	glm::ivec2 spriteSize, sheetSize;
	glm::vec2 spriteScale;
public:
	size_t spriteId;
	SPRITE(glm::ivec2 a_spriteSize, glm::ivec2 a_sheetSize, SHADER* a_shader, TEXTURE* a_sheet);
	void Render();
	void Update(double a_deltaTime, SCENE*);
	~SPRITE();
};


#endif