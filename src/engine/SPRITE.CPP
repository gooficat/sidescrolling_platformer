#include "engine/SPRITE.HPP"


SPRITE::SPRITE(glm::ivec2 a_spriteSize, glm::ivec2 a_sheetSize, SHADER* a_shader, TEXTURE* a_sheet) :
	MODEL(QUAD_PRIMITIVE, a_shader, a_sheet), spriteSize(a_spriteSize), sheetSize(a_sheetSize) {
   this->spriteId = 0;
	this->spriteScale = (glm::vec2)this->sheetSize;
   this->transform.scale = {
      a_spriteSize.x, a_spriteSize.y, 1.0f
   };
	
}

void SPRITE::Render() {
   this->shader->Use();
   this->texture->Use();
   glm::ivec2 spriteOffset = {
      (this->spriteId % this->sheetSize.x) * this->spriteScale.x,
      ( this->spriteId / this->sheetSize.x) * this->spriteScale.y
   };
   glm::mat4 matrix = this->transform.GetMatrix();
   shader->SetIVec2(spriteOffset, "sheetPosition");
   shader->SetVec2(this->spriteScale, "spriteScale");
   shader->SetMat4(matrix, "model");
   this->mesh->Draw();
}

SPRITE::~SPRITE() {

}

void SPRITE::Update(double, SCENE*) {
}