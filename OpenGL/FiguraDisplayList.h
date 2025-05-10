#pragma once
#include "Figura.h"
#include "IncludeGL.h"
class FiguraDisplayList : public Figura
{
protected:
    GLuint displayList;

public:
    FiguraDisplayList();
    virtual ~FiguraDisplayList();

    virtual void InitBuffers() = 0; 
    virtual void Draw() override;
};

