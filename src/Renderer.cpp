#include "include/Renderer.h"


void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}


void Renderer::Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const
{
    va.Bind();
    ib.Bind();

    GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, 0));

    va.Unbind();
    ib.Unbind();
    shader.Unbind();
}