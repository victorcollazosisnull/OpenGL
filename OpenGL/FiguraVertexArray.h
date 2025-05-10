#pragma once
#include "Figura.h"
#include "IncludeGL.h"
class FiguraVertexArray : public Figura
{
protected:
    GLfloat* vertices;
    GLfloat* colors;
    int vertexCount;

public:
    FiguraVertexArray();
    virtual ~FiguraVertexArray();
    virtual void InitBuffers() = 0;
    virtual void Draw() override;
};