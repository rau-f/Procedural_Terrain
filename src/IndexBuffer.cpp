#include "include/IndexBuffer.h"


IndexBuffer::IndexBuffer()
{
    GLCall(glGenBuffers(1, &m_ID));
}

IndexBuffer::~IndexBuffer()
{
}


unsigned int IndexBuffer::getID() const
{
    return m_ID;
}


int IndexBuffer::getCount() const
{
    return count;
}


void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
}


void IndexBuffer::setIndexData(const std::vector<unsigned int> indices, std::ptrdiff_t size)
{
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), GL_STATIC_DRAW));
    count = indices.size();
}


void IndexBuffer::setIndexData(unsigned int* indices, std::ptrdiff_t size)
{
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW));
    count = sizeof(indices) / sizeof(unsigned int);
}


void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}


void IndexBuffer::Delete() const
{
    GLCall(glDeleteBuffers(1, &m_ID));
}