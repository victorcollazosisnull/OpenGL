#include <Windows.h>
#include "IncludeGL.h"
#include "Example.h"
#include "Example7.h"
#include <iostream>
using namespace std;
Example* _Example;

void Render()
{
	((Example7*)_Example)->Render();
}
void KeyboardFunc(unsigned char key, int X, int Y )
{
	((Example7*)_Example)->KeyboardFunc(key,  X,  Y);
	glutPostRedisplay(); 
}
void reSize(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 10000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Idle()
{
	((Example7*)_Example)->Idle();
}


void init(void)
{
	_Example = new Example7(); 
	((Example7*)_Example)->init();
}
int main(int argc, char** argv)
{
	GLuint width = 550;
	GLuint heigth = 550;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(width, heigth);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("VJCR");

	glewInit(); 

	init();
	
	glutDisplayFunc(Render);
	glutIdleFunc(Idle);

	glutKeyboardFunc(KeyboardFunc);

	glutReshapeFunc(reSize);

	/*glutMouseFunc([](int button, int state, int x, int y) {
		((Example7*)_Example)->MouseButton(button, state, x, y);
		});

	// Detecta movimiento con botones presionados (por ejemplo, mientras arrastrás)
	glutMotionFunc([](int x, int y) {
		((Example7*)_Example)->MouseMotion(x, y);
		});
		*/
	glutMainLoop();
	
	return 0;
}
