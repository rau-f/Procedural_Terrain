#include "include/Mesh.h"


void Mesh::genNormals()
{
    for (int i = 0; i < m_Indices.size(); i += 3)
    {
        unsigned int i0 = m_Indices[i + 0];
        unsigned int i1 = m_Indices[i + 1];
        unsigned int i2 = m_Indices[i + 2];

        Vertex &v0 = m_Vertices[i0];
        Vertex &v1 = m_Vertices[i1];
        Vertex &v2 = m_Vertices[i2];

        glm::vec3 edge1 = v1.position - v0.position;
        glm::vec3 edge2 = v2.position - v0.position;
        glm::vec3 faceNormal = glm::normalize(glm::cross(edge1, edge2));

        v0.normal += faceNormal;
        v1.normal += faceNormal;
        v2.normal += faceNormal;
    }

    for (auto& v : m_Vertices)
        v.normal = glm::normalize(v.normal);
}


void Mesh::sendToGPU()
{
    m_VA.Bind();
    m_VB.Bind();
    m_IB.Bind();

    m_VB.setBufferData(m_Vertices, m_Vertices.size() * sizeof(Vertex));
    m_IB.setIndexData(m_Indices, m_Indices.size() * sizeof(unsigned int));

    m_VA.LinkAttrib(0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
    // m_VA.LinkAttrib(1, 3, GL_FLOAT, sizeof(Vertex), (void*) (sizeof(glm::vec3)));
    // m_VA.LinkAttrib(2, 2, GL_FLOAT, sizeof(Vertex), (void*) (sizeof(glm::vec3)));
    m_VA.LinkAttrib(3, 3, GL_FLOAT, sizeof(Vertex), (void*) (sizeof(glm::vec3)));

    m_VB.Unbind();
    m_VA.Unbind();
    m_IB.Unbind();
}


std::vector<Vertex>& Mesh::getVertices()
{
    return m_Vertices;
}


std::vector<unsigned int>& Mesh::getIndices()
{
    return m_Indices;
}


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