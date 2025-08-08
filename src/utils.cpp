#include "include/utils.hpp"

//             POSITION                       UP                        YAW   PITCH
Camera camera(glm::vec3(0.0f, 4.5f, 20.0f), glm::vec3(0.0f, 0.25f, 0.0f), -5.0f, 30.0f);



void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    static float lastX = 800 / 2;
    static float lastY = 600 / 2;
    static bool  firstMouse = true;

    if (firstMouse)
    {
        lastX = float(xpos);
        lastY = float(ypos);
        firstMouse = false;
        return;
    }

    float xOffset = float(xpos) - lastX;
    float yOffset = lastY - float(ypos);

    lastX = float(xpos);
    lastY = float(ypos);

    camera.mouseInput(xOffset, yOffset);
}


void process_input(GLFWwindow* window, float& deltaTime, float& lastFrame)
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.keyBoardInput(GLFW_KEY_W, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.keyBoardInput(GLFW_KEY_A, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.keyBoardInput(GLFW_KEY_S, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.keyBoardInput(GLFW_KEY_D, deltaTime);
}
