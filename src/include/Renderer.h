#pragma once

#if !defined(RENDERER_H)
#define RENDERER_H


#include <glad/glad.h>
#include "errors.h"
#include "shaders.h"
#include "VertexArray.h"
#include "IndexBuffer.h"


class Renderer
{
public:
    void Clear() const;
    void Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const;
};


#endif
