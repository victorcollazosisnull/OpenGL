#pragma once
#include "Figura.h"
#include "IncludeGL.h"
class FiguraVAInstanced : public Figura
{
protected:
    GLuint vao;
    GLuint vboVertices;
    GLuint vboColors;
    int vertexCount;
    int instanceCount;

public:
    FiguraVAInstanced();
    virtual ~FiguraVAInstanced();

    virtual void Draw() override;

    virtual void InitBuffers() = 0;
};