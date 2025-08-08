#ifndef UTILS_H
#define UTILS_H


#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Camera.hpp"

extern Camera camera;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void process_input(GLFWwindow* window, float& deltaTime, float& lastFrame);

#endif