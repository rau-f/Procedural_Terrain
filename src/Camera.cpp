#include "include/Camera.hpp"
#include <Camera.hpp>
#include <GLFW/glfw3.h>
#include <iostream>


Camera::Camera (glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), Right(glm::vec3(1.0f, 0.0f, 0.0f)),
    WorldUp(up), Yaw(yaw), Pitch(pitch), Speed(3.5f), Sensivity(0.1f)
{
    Position = position;
    UpdateCamera();
}


Camera::~Camera()
{
}


void Camera::keyBoardInput(unsigned int direction, float deltaTime)
{
    float velocity = Speed * deltaTime;

    if (direction == GLFW_KEY_W)
        Position += Front * velocity;
    if (direction == GLFW_KEY_A)
        Position -= Right * velocity;
    if (direction == GLFW_KEY_D)
        Position += Right * velocity;
    if (direction == GLFW_KEY_S)
        Position -= Front * velocity;
}


void Camera::mouseInput(float xOffset, float yOffset)
{
    xOffset *= Sensivity;
    yOffset *= Sensivity;

    Yaw += xOffset;
    Pitch += yOffset;

    if(Pitch > 89.0f)
        Pitch = 89.0f;
    if(Pitch < -89.0f)
        Pitch = -89.0f;

    UpdateCamera();
}


glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}


void Camera::UpdateCamera()
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);

    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}