#pragma once
#include "Example.h"
class Example2 :public Example
{
public:
	Example2();

	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	void DrawAxis(float distance);
	void DrawGrids();
	void DrawTransformedPoint(float x, float y, float z, float translateX, float translateY, float translateZ);
	void DrawTransformedLines();
	void DrawTransformedXYAxis();
	void DrawTransformedPointWithAxes(float x, float y, float z, float translateX, float translateY, float translateZ);
	void DrawTransformedCube(float size, float translateX, float translateY, float translateZ);

	void DrawTransformedSphere(float radius, float translateX, float translateY, float translateZ);
	void DrawTransformedPyramid(float size, float translateX, float translateY, float translateZ);
	void DrawTransformedSquare(float size, float translateX, float translateY, float translateZ);
	void DrawTransformedRectangle(float width, float height, float translateX, float translateY, float translateZ);
	void DrawTransformedCircle(float radius, float translateX, float translateY, float translateZ);
};

