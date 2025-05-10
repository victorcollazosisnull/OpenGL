#pragma once
#include "FiguraVAInstanced.h"
class EsferaVAInstanced : public FiguraVAInstanced
{
public:
    EsferaVAInstanced();
    ~EsferaVAInstanced();

    void InitBuffers() override;
};

