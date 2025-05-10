#pragma once
#include "Example.h"
#include "Figura.h"
#include "EsferaVertexArray.h"
#include "CuboVertexArray.h"
#include "CuadradoVertexArray.h"
#include "PiramideVertexArray.h"
#include "EsferaDisplayList.h"
#include "CuboDisplayList.h"
#include "CuadradoDisplayList.h"
#include "PiramideDisplayList.h"
#include "CuboVAIndex.h"
#include "EsferaVAIndex.h"
#include "CuadradoVAIndex.h"
#include "PiramideVAIndex.h"
#include "CuboVAInstanced.h"
#include "EsferaVAInstanced.h"
#include "CuadradoVAInstanced.h"
#include "PiramideVAInstanced.h"
class Example7 : public Example
{
    Figura* arrayObjectDisplayList[5];
    Figura* arrayObjectVertexSimple[5];
    Figura* arrayObjectVertexIndex[5];
    Figura* arrayObjectVertexInstanced[5];

public:
    void init() override;
    void Render() override;
    void KeyboardFunc(unsigned char key, int X, int Y) override;
    void Idle() override;
};

