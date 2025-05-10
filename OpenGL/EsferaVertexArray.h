#pragma once
#include "FiguraVertexArray.h"
#include <cmath>
#include <corecrt_math.h>
class EsferaVertexArray : public FiguraVertexArray
{
public:
    EsferaVertexArray(int slices = 20, int stacks = 20);
    virtual void InitBuffers() override;
};

