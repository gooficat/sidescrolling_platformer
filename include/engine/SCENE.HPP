#ifndef SCENE_HPP
#define SCENE_HPP

#include "ENGINE/NODE.HPP"

#include <vector>

class SCENE
{
 private:
   /* data */
 public:
   SCENE(/* args */);
   ~SCENE();

   std::vector<NODE*> nodes;

   virtual void Update(double a_deltaTime);
   virtual void Render();
};

#endif