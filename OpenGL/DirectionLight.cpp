#include "DirectionLight.h"
#include <GL/glut.h>

void DirectionLight::init()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	GLfloat light_position[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_color[] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);

	glShadeModel(GL_SMOOTH); 

	GLfloat material_diffuse[] = { 1.0,1.0,1.0,1.0 };
	GLfloat material_specular[] = {1.0,1.0,1.0,1.0};
	GLfloat material_shininess[]{ 50.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
}
