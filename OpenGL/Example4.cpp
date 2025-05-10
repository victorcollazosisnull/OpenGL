#include "Example4.h"
#include "IncludeGL.h"
#include "SpotLight.h"
#include "DirectionLight.h"
#include "PointLight.h"
Example4::Example4()
{
}

void Example4::init()
{
	glEnable(GL_DEPTH_TEST); 
	InitLight();
	InitMaterial(); 
	//glShadeModel(GL_FLAT); 
	glShadeModel(GL_SMOOTH);
	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	angle = 0.0f;

	luz = new SpotLight();  
	luz = new DirectionLight();    
	luz = new PointLight();    
	luz->init();
}

void Example4::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 2.0, 5.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	//DrawGridXZ(10.0f, 20);
	DrawGround(10.0f);

	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	GLfloat celeste[] = { 0.4f, 0.8f, 1.0f, 1.0f }; 
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, celeste);

	glutSolidCube(2.0);

	glPopMatrix();

	glutSwapBuffers();
}

void Example4::KeyboardFunc(unsigned char key, int X, int Y)
{
}

void Example4::Idle()
{
	angle += 0.3f;
	if (angle > 360.0f)
		angle -= 360.0f;

	glutPostRedisplay();
}
void Example4::InitLight()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_ambient[] = { 0.2f,0.2f,0.2f,1.0f };
	GLfloat light_diffuse[] = { 0.8f,0.8f,0.8f,1.0f };
	GLfloat light_specular[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat light_position[] = { 2.0f,2.0f,2.0f,1.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
void Example4::InitMaterial()
{
	GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
	GLfloat mat_shinisess[]{ 50.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shinisess);
}
void Example4::DrawGridXZ(float size, int divisions)
{
	glDisable(GL_LIGHTING);

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

	glEnable(GL_LIGHTING);
}
void Example4::DrawGround(float size)
{
	glDisable(GL_LIGHTING);

	glColor3f(0.5f, 0.5f, 0.5f); 

	glBegin(GL_QUADS);
	glVertex3f(-size, -1.0f, -size); 
	glVertex3f(size, -1.0f, -size);   
	glVertex3f(size, -1.0f, size);    
	glVertex3f(-size, -1.0f, size);  
	glEnd();

	glEnable(GL_LIGHTING);
}