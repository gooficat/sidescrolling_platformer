#ifndef GAME_HPP
#define GAME_HPP

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <cstdint>
#include <iostream>
#include <vector>

#include "stb_image.h"

#include "ENGINE/NODE.HPP"
#include "ENGINE/SCENE.HPP"

namespace GAME
{
extern double targetFrameTime;
extern bool running;

extern std::vector<SCENE*> scenes;
extern uint16_t currentScene;

extern GLFWwindow* window;

extern bool keys[512];
extern bool leftMouseDown;
extern bool rightMouseDown;

extern double mouseX, mouseY;

int Init(uint16_t a_width, uint16_t a_height);
void Run(uint16_t a_FPS);
void Terminate();
};  // namespace GAME

#endif