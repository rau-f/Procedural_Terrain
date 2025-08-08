#ifndef CAMERA_HPP
#define CAMERA_HPP


#include <glm/glm.hpp>


class Camera
{
private:
    float Yaw;
    float Pitch;
    float Speed;
    float Sensivity;

public:
    Camera() {}
    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
    ~Camera();

    glm::mat4 GetViewMatrix();
    void keyBoardInput(unsigned int direction, float deltaTime);
    void mouseInput(float xOffset, float yOffset);
    void UpdateCamera();
    
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Right;
    glm::vec3 Up;
    glm::vec3 WorldUp;
};





















































































#include <glm/gtc/matrix_transform.hpp>

#endif