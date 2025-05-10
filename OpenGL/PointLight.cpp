#include "PointLight.h"
#include <GL/glut.h>

void PointLight::init()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	GLfloat light_position[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_color[] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

	glShadeModel(GL_SMOOTH);
}
