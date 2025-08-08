#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H


#include <glad/glad.h>

#include "errors.h"


class VertexArray
{
private:
    unsigned int m_ID;

public:
    VertexArray();
    ~VertexArray();

    unsigned int getID() const;

    void Bind() const;
    void Unbind() const;
    void Delete() const;
    void LinkAttrib(unsigned int layout, unsigned int count, unsigned int type, std::ptrdiff_t stride, const void* offset) const;
};



#endif