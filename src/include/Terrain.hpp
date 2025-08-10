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


struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    // glm::vec2 texture;
    // glm::vec3 color;
};


class Terrain : public Mesh
{
private:
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;

    int meshHeight;
    int meshWidth;

    float heightScale = 10.0;
    glm::mat4 m_Model;

public:
    Terrain(int height, int width);

    void genVertices() override;
    void genIndices() override;
    void genNormals() override;
    void sendToGPU() override;
    void render(glm::mat4& view, glm::mat4& projection) override;

    std::vector<Vertex>& getVertices();
    std::vector<unsigned int>& getIndices();
};

#endif