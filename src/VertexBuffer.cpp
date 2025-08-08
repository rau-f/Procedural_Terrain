#include "include/VertexBuffer.h"
#include "include/Mesh.h"


VertexBuffer::VertexBuffer()
{
    GLCall(glGenBuffers(1, &m_ID));
}

VertexBuffer::~VertexBuffer()
{
}


void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
}


void VertexBuffer::setBufferData(const std::vector<Vertex> vertices, std::ptrdiff_t size)
{
    Bind();
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, vertices.data(), GL_STATIC_DRAW));
}


void VertexBuffer::setBufferData(float* vertices, std::ptrdiff_t size)
{
    Bind();
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW));
}


void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}


void VertexBuffer::Delete() const
{
    GLCall(glDeleteBuffers(1, &m_ID));
}