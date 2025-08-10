#include "include/Mesh.h"

VertexArray& Mesh::getVA()
{
    return m_VA;
}


IndexBuffer& Mesh::getIB()
{
    return m_IB;
}


Shader& Mesh::getShader()
{
    return m_Shader;
}