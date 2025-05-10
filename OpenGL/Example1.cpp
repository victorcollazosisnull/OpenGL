#include "Example1.h"
#include "IncludeGL.h"
#include "Esfera.h"
#include "Cuadrado.h"
#include "Cubo.h"
#include "Piramide.h"
#include "Circulo.h"
#include "Triangulo.h"
#include <iostream>
Example1::Example1()
{
	esfera = new Esfera();
	cuadrado = new Cuadrado();
	cubo = new Cubo();
	piramide = new Piramide();
	circulo = new Circulo();
	triangulo = new Triangulo();
	((Esfera*)esfera)->color.SetColor(1, 0, 0);
	((Cuadrado*)cuadrado)->color.SetColor(0, 1, 0);
	((Cubo*)cubo)->color.SetColor(1, 1, 0);
	((Piramide*)piramide)->color.SetColor(0, 0, 1);
	((Circulo*)circulo)->color.SetColor(0, 1, 1);
	((Triangulo*)triangulo)->color.SetColor(1, 1, 1);
}


void Example1::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

	//MostrarMenu();
}
void Example1::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Example::DrawAxis(10);
	//comentar
		//DrawPoint();
		//DrawLine();
		//DrawColoredLine();
		//DrawLineStrip();
		//DrawAxesXY();
		//DrawAxesXYZ();
		DrawGridXZ(10.0f, 20);
		//DrawFiguras();
	glFlush();
	
}
void Example1::DrawPoint()
{
	glPointSize(10.0f);
	glBegin(GL_POINTS);

	    glColor3f(1.0f, 0.0f, 0.0f);
	    glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();
}

void Example1::DrawLine()
{
	glLineWidth(5.0f);
	glBegin(GL_LINES);

	    glColor3f(0.0f, 0.0f, 1.0f);
	    glVertex3f(-0.5f, -0.5f, 0.0f);
	    glVertex3f(0.5f, 0.5f, 0.0f);

	glEnd();
}

void Example1::DrawColoredLine()
{
	glLineWidth(3.0f);
	glBegin(GL_LINES);

	    glColor3f(1.0f, 0.0f, 0.0f); 
		glVertex3f(-1.0f, 0.0f, 0.0f);
	    glColor3f(0.0f, 1.0f, 0.0f); 
		glVertex3f(1.0f, 0.0f, 0.0f);

	glEnd();
}

void Example1::DrawLineStrip()
{
	glLineWidth(2.0f);
	glBegin(GL_LINE_STRIP);

	    glColor3f(1.0f, 1.0f, 0.0f);
	    glVertex3f(-1.0f, -1.0f, 0.0f);
	    glVertex3f(-0.5f, 0.5f, 0.0f);
	    glVertex3f(0.0f, -0.5f, 0.0f);
	    glVertex3f(0.5f, 0.5f, 0.0f);
	    glVertex3f(1.0f, -1.0f, 0.0f);

	glEnd();
}

void Example1::DrawAxesXY()
{
	glLineWidth(2.0f);
	glBegin(GL_LINES);

	    glColor3f(1.0f, 0.0f, 0.0f); 
	    glVertex3f(-2.0f, 0.0f, 0.0f);
	    glVertex3f(2.0f, 0.0f, 0.0f);

	    glColor3f(0.0f, 1.0f, 0.0f); 
	    glVertex3f(0.0f, -2.0f, 0.0f);
	    glVertex3f(0.0f, 2.0f, 0.0f);

	glEnd();
}

void Example1::DrawAxesXYZ()
{
	glLineWidth(2.0f);
	glBegin(GL_LINES);

	    glColor3f(1.0f, 0.0f, 0.0f); 
	    glVertex3f(-2.0f, 0.0f, 0.0f);
	    glVertex3f(2.0f, 0.0f, 0.0f);

	    glColor3f(0.0f, 1.0f, 0.0f); 
	    glVertex3f(0.0f, -2.0f, 0.0f);
	    glVertex3f(0.0f, 2.0f, 0.0f);

	    glColor3f(0.0f, 0.0f, 1.0f); 
	    glVertex3f(0.0f, 0.0f, -2.0f);
	    glVertex3f(0.0f, 0.0f, 2.0f);

	glEnd();
}

void Example1::DrawGridXZ(float size, int divisions)
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

void Example1::DrawFiguras()
{
	//((Esfera*)esfera)->Draw();
	//((Cuadrado*)cuadrado)->Draw();
	//((Cubo*)cubo)->Draw();
	//((Piramide*)piramide)->Draw();
	//((Circulo*)circulo)->Draw();
	//((Triangulo*)triangulo)->Draw();
	switch (indexFigura)
	{
	case 1:
		((Esfera*)esfera)->Draw();
		break;
	case 2:
		((Cuadrado*)cuadrado)->Draw();
		break;
	case 3:
		((Cubo*)cubo)->Draw();
		break;
	case 4:
		((Piramide*)piramide)->Draw();
		break;
	case 5:
		((Circulo*)circulo)->Draw();
		break;
	case 6:
		((Triangulo*)triangulo)->Draw();
		break;
	}
}

void Example1::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key)
	{
	case '1':
		indexFigura = 1; 
		break;
	case '2':
		indexFigura = 2; 
		break;
	case '3':
		indexFigura = 3; 
		break;
	case '4':
		indexFigura = 4; 
		break;
	case '5':
		indexFigura = 5; 
		break;
	case '6':
		indexFigura = 6; 
		break;
	default:
		std::cout << "Es del 1 al 6 nomas :)\n";
		return;
	}
	glutPostRedisplay();
	MostrarMenu();
}
void Example1::MostrarMenu()
{
	system("CLS");  

	std::cout << "=====================\n";
	std::cout << "      VJCR MENU :)       \n";
	std::cout << "=====================\n";
	std::cout << "1 Esfera    " << (indexFigura == 1 ? "(X)" : "( )") << "\n";
	std::cout << "2 Cuadrado  " << (indexFigura == 2 ? "(X)" : "( )") << "\n";
	std::cout << "3 Cubo      " << (indexFigura == 3 ? "(X)" : "( )") << "\n";
	std::cout << "4 Piramide  " << (indexFigura == 4 ? "(X)" : "( )") << "\n";
	std::cout << "5 Circulo   " << (indexFigura == 5 ? "(X)" : "( )") << "\n";
	std::cout << "6 Triangulo " << (indexFigura == 6 ? "(X)" : "( )") << "\n";
	std::cout << "=====================\n";
	std::cout << "Usa los numeros 1-6 para cambiar de figura\n";

	switch (indexFigura)
	{
	case 1:
		std::cout << "Esfera: Redondas como un mango\n";
		break;
	case 2:
		std::cout << "Cuadrado: Me recuerda a geometry dash, el real vicio\n";
		break;
	case 3:
		std::cout << "Cubo: Minecraft es lo unico que se me viene a la mente\n";
		break;
	case 4:
		std::cout << "Piramide: Los aliens no construyeron las piramides\n";
		break;
	case 5:
		std::cout << "Circulo: Recuerdos duros de dibujo digital\n";
		break;
	case 6:
		std::cout << "Triangulo: Los iluminatis te observan\n";
		break;
	}

	std::cout << "=====================\n";
}

void Example1::Idle()
{

}