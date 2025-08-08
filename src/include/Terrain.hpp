#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "PerlinNoise.h"
#include "Renderer.h"


class Terrain : public Mesh
{
private:
    int meshHeight;
    int meshWidth;

    float heightScale = 10.0;
    glm::mat4 m_Model;

public:
    Terrain(int height, int width);

    void genVertices() override;
    void genIndices() override;
    void render(glm::mat4& view, glm::mat4& projection) override;
};

#endif