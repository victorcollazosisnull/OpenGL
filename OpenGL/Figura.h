#pragma once
#include "Color.h"
#include "IncludeGL.h" 

class Figura
{
protected:
    GLuint texture; 

public:
    Color color;

    Figura(); 

    virtual void Draw() = 0;

    virtual void LoadTexture(GLuint newTexture);
    virtual void ApplyTexture();
};