#include <iostream>
#ifndef NOT_WINDOWS
#include <windows.h>
HANDLE hConsole;
#define setConsoleLogColor(color) SetConsoleTextAttribute(hConsole, color)

#else
#define setConsoleLogColor(color)
#endif

#include "GAME.HPP"

#include "engine/CAMERA.HPP"
#include "engine/MODEL.HPP"
#include "engine/SPRITE.HPP"

#include "COLLISION.HPP"
#include "PRIMITIVES.HPP"

#define G_WIDTH 640
#define G_HEIGHT 480
#define G_FPS 20


class BUTTON : public MODEL {
   public:
      BUTTON(MESH* a_mesh, SHADER* a_shader, TEXTURE* a_texture) : MODEL(a_mesh, a_shader, a_texture) {}
      void (*onPress)();
      void Update(double a_deltaTime, SCENE* a_parent) {
         TRANSFORM& t = this->transform;
         if (COLLISION::AABB_Point(
            GAME::mouseX, GAME::mouseY,
            t.position.x - t.scale.x/2,
            t.position.y - t.scale.y/2,
            t.position.x + t.scale.x/2,
            t.position.y + t.scale.y/2
            ) &&
            GAME::leftMouseDown
         ) {
            this->onPress();
         }
         MODEL::Update(a_deltaTime, a_parent);
      }
      void Render() {
         MODEL::Render();
      }
   private:

};



int main() {
   #ifndef NOT_WINDOWS
      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   #endif

   
   setConsoleLogColor(FOREGROUND_RED);
   std::cout << "Hello!" << std::endl;
   setConsoleLogColor(FOREGROUND_BLUE);
   if (!GAME::Init(G_WIDTH, G_HEIGHT)) {
      std::cerr << "Failed to initialize game. Terminating." << std::endl;
      return 1;
   }

   INIT_PRIMITIVES();

   static SHADER simpleShader;
   simpleShader.Compile(
      "C:/Users/User/Documents/sidescrolling_platformer/res/simple.vert",
      "C:/Users/User/Documents/sidescrolling_platformer/res/simple.frag"
   );
   static SHADER spriteShader;
   spriteShader.Compile(
      "C:/Users/User/Documents/sidescrolling_platformer/res/sprite.vert",
      "C:/Users/User/Documents/sidescrolling_platformer/res/simple.frag"
   );

   static CAMERA overlayCamera(&simpleShader);
   overlayCamera.targetMode = false;
   overlayCamera.SetOrthographic(0, G_WIDTH, G_HEIGHT, 0, -100, 100);


   static TEXTURE tex("C:/Users/User/Documents/sidescrolling_platformer/res/Textures/voxescape09.png");
   
   static BUTTON startButton(QUAD_PRIMITIVE, &simpleShader, &tex);
   startButton.transform.position = {G_WIDTH/2.0f, G_HEIGHT-80.0f, -50.0f};
   startButton.transform.rotation = {0.0f, 0.0f, 0.0f};
   startButton.transform.scale = {160.0f, 40.0f, 1.0f};
   startButton.onPress = []() -> void {
      GAME::currentScene++;
   };
  
  

   static TEXTURE tex2("C:/Users/User/Documents/sidescrolling_platformer/res/knight.png");

   static SPRITE testSprite({70, 112}, {8, 5}, &spriteShader, &tex2);
   // testSprite.transform.scale = { 20, 20, 20 };
   testSprite.transform.position = {
      200, 150, 0
   };

   static CAMERA testCamera(&spriteShader);
   testCamera.targetMode = false;
   // testCamera.SetPerspective(60.0f, (float)G_WIDTH / (float)G_HEIGHT, 0.1f, 100.0f);
   testCamera.SetOrthographic(0, G_WIDTH, G_HEIGHT, 0, -100, 100);

   setConsoleLogColor(FOREGROUND_GREEN);
   static class MENUSCENE : public SCENE {
   public:
      MENUSCENE() {
         this->nodes.push_back(&overlayCamera);
         this->nodes.push_back(&startButton);
         // this->nodes.push_back(&model2);
         std::cout << "added nodes to menu scene..." << std::endl;
      }
      bool justPressed = false;
      void Update(double deltaTime) {
         if (GAME::keys[GLFW_KEY_W]) {
            testSprite.spriteId = (testSprite.spriteId + 1) % 16;
         }
         SCENE::Update(deltaTime);
      }
      void Render() {
         SCENE::Render();
      }
   } menuScene;

   
   static class PLAYTESTSCENE : public SCENE {
   public:
      PLAYTESTSCENE() {
         this->nodes.push_back(&testCamera);
         this->nodes.push_back(&testSprite);
         std::cout << "added nodes to test scene..." << std::endl;
      }
      void Update(double deltaTime) {
         SCENE::Update(deltaTime);
      }
      void Render() {
         SCENE::Render();
      }
   } playTestScene;

   

   GAME::scenes.push_back(&menuScene);
   GAME::scenes.push_back(&playTestScene);


   glClearColor(0.4f, 0.1f, 0.2f, 1.0f);
   GAME::currentScene = 0;
   // glfwSetInputMode(GAME::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

   GAME::Run(G_FPS);

   GAME::Terminate();
   setConsoleLogColor(0);
   return 0;
}