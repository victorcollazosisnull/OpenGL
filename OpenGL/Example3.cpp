#include "Example3.h"
#include "IncludeGL.h"
#include "Vector3D.h"
#include <iostream>
Example3::Example3() 
{
	camera = nullptr;
	pyramidPosition = Vector3D(0.0f, 0.0f, 0.0f);
}
void Example3::init()
{
	tpsCamera = new TPSCamera();
	camera = new CameraFPS();  // Inicializamos la cámara
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Color de fondo negro
	glClearDepth(1.0);

	glMatrixMode(GL_PROJECTION);  // Cambiamos a la matriz de proyección
	glLoadIdentity();  // Restablecemos la matriz de proyección
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);  // Definimos la perspectiva de la cámara

	glMatrixMode(GL_MODELVIEW);  // Regresamos a la matriz de modelo y vista
	pyramidPosition = Vector3D(0.0f, 0.0f, 0.0f);
	camera->transform.translate(Vector3D(15, 15, 15));
	camera->init();
}

void Example3::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	switch (indexFigura)
	{
	case 1:
		esfera.Draw();
		break;
	case 2:
		cubo.Draw();
		break;
	case 3:
		piramide.Draw();
		break;
	default:
		break;
	}

	glPopMatrix();

	glFlush();

	//camera->updateCamera();
	//tpsCamera->follow(pyramidPosition);  // La cámara sigue la pirámide
	//tpsCamera->updateCamera();
	//DrawGridXZ(10.0f, 20);
	//DrawTransformedPyramid(2.0f);

	//glFlush();
}

void Example3::KeyboardFunc(unsigned char key, int X, int Y)
{
	if (key >= '1' && key <= '3')
	{
		indexFigura = key - '0';
		MostrarMenu(); 
	}
	//camera->KeyboardFunc(key, X, Y);

	//switch (key)
	//{
	//case 'i':  
	//	pyramidPosition.z -= 1.0f;
	//	break;
	//case 'k':  
	//	pyramidPosition.z += 1.0f;
	//	break;
	//case 'j':  
	//	pyramidPosition.x -= 1.0f;
	//	break;
	//case 'l':  
	//	pyramidPosition.x += 1.0f;
	//	break;
	//}

	glutPostRedisplay();
}

void Example3::Idle()
{
	
}
void Example3::DrawGridXZ(float size, int divisions)
{
	glLineWidth(1.0f);
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_LINES);

	float step = size / divisions;
	float halfSize = size / 2.0f;

	for (int i = 0; i <= divisions; i++)
	{
		float pos = -halfSize + i * step;

		glVertex3f(-halfSize, 0.0f, pos);
		glVertex3f(halfSize, 0.0f, pos);

		glVertex3f(pos, 0.0f, -halfSize);
		glVertex3f(pos, 0.0f, halfSize);
	}

	glEnd();
}
void Example3::DrawTransformedPyramid(float size)
{
	glPushMatrix();

	glTranslatef(pyramidPosition.x, pyramidPosition.y, pyramidPosition.z);
	Example3::DrawAxis(size * 1.5f);

	glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, size, 0.0f);
		glVertex3f(-size, -size, size);
		glVertex3f(size, -size, size);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, size, 0.0f);
		glVertex3f(size, -size, size);
		glVertex3f(size, -size, -size);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, size, 0.0f);
		glVertex3f(size, -size, -size);
		glVertex3f(-size, -size, -size);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, size, 0.0f);
		glVertex3f(-size, -size, -size);
		glVertex3f(-size, -size, size);

	glEnd();
	glPopMatrix();
}
bool mousePressed = false;
void Example3::MouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		mousePressed = (state == GLUT_DOWN);
	}
}

void Example3::MostrarMenu()
{
	std::cout << "\n=====================\n";
	std::cout << "      MENU FIGURAS   \n";
	std::cout << "=====================\n";
	std::cout << "1 - Esfera\n";
	std::cout << "2 - Cubo\n";
	std::cout << "3 - Pirámide\n";
	std::cout << "Presiona una tecla (1-3) para cambiar de figura\n";
	std::cout << "Figura actual: ";

	switch (indexFigura)
	{
	case 1:
		std::cout << "Esfera\n";
		break;
	case 2:
		std::cout << "Cubo\n";
		break;
	case 3:
		std::cout << "Pirámide\n";
		break;
	default:
		std::cout << "Ninguna\n";
		break;
	}
}

void Example3::MouseMotion(int x, int y)
{
	if (!mousePressed) return;

	static int lastX = x;
	static int lastY = y;

	float deltaX = x - lastX;
	float deltaY = y - lastY;

	camera->MouseRotate(deltaX, deltaY);

	lastX = x;
	lastY = y;
}