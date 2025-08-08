#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H


#include <glad/glad.h>
#include <vector>

#include "errors.h"


class IndexBuffer
{
private:
    unsigned int m_ID;
    int count;

public:
    IndexBuffer();
    ~IndexBuffer();

    unsigned int getID() const;
    int getCount() const;

    void Bind() const;
    void setIndexData(const std::vector<unsigned int> indices, std::ptrdiff_t size);
    void setIndexData(unsigned int* indices, std::ptrdiff_t size);
    void Unbind() const;
    void Delete() const;
};


#endif