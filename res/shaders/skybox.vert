#version 330 core

layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    mat4 rotView = mat4(mat3(u_View));
    vec4 pos = u_Projection * rotView * vec4(aPos, 1.0f);
    gl_Position = pos.xyww;
    TexCoords = vec3(aPos.x, aPos.y, aPos.z);
}