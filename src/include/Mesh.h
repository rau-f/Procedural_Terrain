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


class Mesh
{
protected:
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
    virtual void genNormals() = 0;
    virtual void sendToGPU() = 0;
    
    VertexArray& getVA();
    IndexBuffer& getIB();
    Shader& getShader();
};


#endif