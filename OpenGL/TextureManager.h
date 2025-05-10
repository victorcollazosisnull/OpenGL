#pragma once
#include "BMPTextureLoader.h"
#include <map>
#include <string>

class TextureManager {
private:
    std::map<int, GLuint> textures;

public:
    TextureManager() {}

    GLuint LoadTextureBMP(int textureIndex, const char* fileName) 
    {
        BMPTextureLoader loader;
        GLuint texture = loader.LoadBMP(fileName);
        textures[textureIndex] = texture;
        return texture;
    }

    GLuint GetTexture(int index) const 
    {
        auto it = textures.find(index);
        if (it != textures.end()) {
            return it->second;
        }
        return 0;
    }

    void BindTexture(int index) const 
    {
        GLuint texture = GetTexture(index);
        if (texture != 0) {
            glBindTexture(GL_TEXTURE_2D, texture);
        }
    }
};