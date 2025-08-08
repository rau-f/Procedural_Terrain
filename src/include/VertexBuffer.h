#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>
#include <vector>

#include "errors.h"

struct Vertex;

class VertexBuffer
{
private:
    unsigned int m_ID;

public:
    VertexBuffer();
    ~VertexBuffer();

    unsigned int getID() const;

    void Bind() const;
    void setBufferData(const std::vector<Vertex> vertices, std::ptrdiff_t size);
    void setBufferData(float* vertices, std::ptrdiff_t size);
    void Unbind() const;
    void Delete() const;
};



#endif