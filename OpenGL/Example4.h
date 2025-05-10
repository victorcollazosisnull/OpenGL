#pragma once
#include "Example.h"
#include "Light.h"
class Example4 : public Example
{
public:
	Example4();
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	void InitLight();
	void InitMaterial();
	void DrawGridXZ(float size, int divisions);
	void DrawGround(float size);
	float angle;

	Light* luz;
};

