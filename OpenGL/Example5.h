#pragma once
#include "Example.h"
#include "Figura.h"
#include "Vector3D.h"
#include "TextureLoader.h"
#include "Cubo.h";
#include "TextureManager.h" 
class Example5 : public Example
{
private:
    TextureManager textureManager;  
    Figura* shape;
    Vector3D pos;
    TextureLoader* _TextureLoader;
    GLuint texture;
    float rotationAngle;
    float scaleX, scaleY, scaleZ;
public:
    Example5();
    virtual void init()override;
    virtual void Render()override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
    virtual void Idle()override;
    void DrawShape();
    int textureIndex;
};