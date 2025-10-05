#include "COLLISION.HPP"

namespace COLLISION
{
	
bool AABB_Point(float px, float py, float x, float y, float w, float h) {
   if (
         px >= x &&
         px <= x + w &&
         py >= y &&
         py <= y + h
      ) {
      return true;
   }
   return false;
}



} // namespace COLLISION
