#version 330 core

layout (location = 0) in vec3 position;
// layout (location = 1) in vec3 color;
// layout (location = 2) in vec2 texCoord;
layout (location = 3) in vec3 aNormal;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

out float v_Height;
out vec3 v_Normal;
out vec3 v_FragPos;

void main()
{
    v_Height = position.y * 0.1;
    vec4 worldPos = u_Model * vec4(position, 1.0f);
    v_FragPos = worldPos.xyz;
    v_Normal = mat3(transpose(inverse(u_Model))) * aNormal;
    gl_Position = u_Projection * u_View * worldPos;
}