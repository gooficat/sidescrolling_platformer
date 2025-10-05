#ifndef NODE_HPP
#define NODE_HPP

#include <glm/glm.hpp>
#include <vector>

#include "engine/PREDEF.HPP"

#include "engine/TRANSFORM.HPP"

struct NODE
{
   virtual void Update(double a_deltaTime, SCENE* a_parent);
   virtual void Render();
   NODE();
};

struct SPATIAL : public NODE
{
	TRANSFORM transform;
   virtual void Update(double a_deltaTime, SCENE* a_parent);
   virtual void Render();
   SPATIAL();
};


#endif