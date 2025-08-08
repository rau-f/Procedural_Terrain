#include "include/VertexArray.h"


VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &m_ID));
    Bind();
}


VertexArray::~VertexArray()
{   
}


unsigned int VertexArray::getID() const
{
    return m_ID;
}


void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_ID));
}


void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}


void VertexArray::Delete() const 
{
    GLCall(glDeleteVertexArrays(1, &m_ID));
}


void VertexArray::LinkAttrib(unsigned int layout, unsigned int count, unsigned int type, std::ptrdiff_t stride, const void* offset) const
{
    GLCall(glEnableVertexAttribArray(layout));
    GLCall(glVertexAttribPointer(layout, count, type, GL_FALSE, stride, offset));
}