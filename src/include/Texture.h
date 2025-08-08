#if !defined(TEXTURE_H)
#define TEXTURE_H


#include <string>
#include <glad/glad.h>
#include "stb_image.h"
#include "errors.h"


class Texture
{
private:
    unsigned int m_ID;
    std::string m_FilePath;
    unsigned char* m_LocalBuffer;
    int m_Width, m_Height, m_BPP;

public:
    Texture(std::string path);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int getWidth() const { return m_Width; }
    inline int getHeight() const { return m_Height; }
};


#endif // TEXTURE_H
