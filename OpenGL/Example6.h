#pragma once
#include "Example.h"
#include <GL/glew.h>
#include <GL/glut.h> 
class Example6 : public Example
{
public:
	Example6();
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	GLuint displayListID;
};

