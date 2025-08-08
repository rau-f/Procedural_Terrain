#pragma once

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "shaders.h"


struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    // glm::vec2 texture;
    // glm::vec3 color;
};


class Mesh
{
protected:
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;

    VertexArray m_VA;
    VertexBuffer m_VB;
    IndexBuffer m_IB;
    Shader m_Shader;

public:
    Mesh() {}
    ~Mesh() {}

    virtual void genVertices() = 0;
    virtual void genIndices() = 0;
    virtual void render(glm::mat4& view, glm::mat4& projection) = 0;

    void genNormals();
    virtual void sendToGPU();

    std::vector<Vertex>& getVertices();
    std::vector<unsigned int>& getIndices();
    VertexArray& getVA();
    IndexBuffer& getIB();
    Shader& getShader();
};


#endif