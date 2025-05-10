#pragma once
#include "Example.h"
#include "CameraFPS.h"
#include "TPSCamera.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Piramide.h"
class Example3 :public Example
{
	int lastMouseX = -1;
	int lastMouseY = -1;
	int indexFigura = 0;
	Cubo cubo;
	Esfera esfera;
	Piramide piramide;

public:

	Example3();
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	void DrawGridXZ(float size, int divisions);
	void DrawTransformedPyramid(float size);
	void MouseMotion(int x, int y);
	void MouseButton(int button, int state, int x, int y);

	CameraFPS* camera;
	TPSCamera* tpsCamera;

	Vector3D pyramidPosition;

	void MostrarMenu();
};

