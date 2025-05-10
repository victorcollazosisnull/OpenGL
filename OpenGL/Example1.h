#pragma once
#include "Example.h"
#include "Figura.h"
class Example1 : public Example
{
	Figura* esfera;
	Figura* cuadrado;
	Figura* cubo;
	Figura* piramide;
	Figura* circulo;
	Figura* triangulo;
	int indexFigura = 1;

public:
	Example1();

	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	void DrawPoint();
	void DrawLine();
	void DrawColoredLine();
	void DrawLineStrip();
	void DrawAxesXY();
	void DrawAxesXYZ();
	void DrawGridXZ(float size, int divisions);

	void DrawFiguras();

	void MostrarMenu();
};

