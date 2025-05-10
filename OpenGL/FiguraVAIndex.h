#pragma once
#include "Figura.h"
#include "IncludeGL.h"
class FiguraVAIndex : public Figura
{
protected:
    GLfloat* vertices;
    GLfloat* colors;
    GLuint* indices;
    int vertexCount;
    int indexCount;

public:
    FiguraVAIndex();
    virtual ~FiguraVAIndex();
    virtual void InitBuffers() = 0;
    virtual void Draw() override;
};

