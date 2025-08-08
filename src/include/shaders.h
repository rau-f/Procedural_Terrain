#ifndef SHADERS_H
#define SHADERS_H


#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "errors.h"


std::string getFileContent(const char* fileName);


class Shader
{
private:
    unsigned int m_ID;

public:
    Shader() {}
    ~Shader() {}

    unsigned int getID() const;

    void CreateShader(const char* vertexShaderFile, const char* fragShaderFile);
    void Bind() const;
    void Unbind() const;
    void Delete() const;
    void CompileStatus(unsigned int shader);
    
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3); // SET COLOR
    void SetUniform1i(const std::string& name, int value);  // SET TEXTURE
    void SetUniform1f(const std::string& name, float value);    // PER VERTEX
    void SetMat4(const std::string& name, float* value);    // SET MVP
    void SetVec3(const std::string& name, const float* value);
    void SetInt(const std::string& name, const int value);  // SET SKYBOX
    
    int GetUniformLocation(const std::string& name);
};


#endif
