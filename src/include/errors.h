#ifndef ERRORS_H
#define ERRORS_H


#include <glad/glad.h>
#include <iostream>


#define ASSERT(x) if(!(x)) { \
    __builtin_trap(); \
}


#define GLCall(x) GLClearError(); \
    x; \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__)) \


void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);



#endif