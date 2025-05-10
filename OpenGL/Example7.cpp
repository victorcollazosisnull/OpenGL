#include "Example7.h"
#include "IncludeGL.h"
#include "Figura.h"

void Example7::init()
{
    glEnable(GL_DEPTH_TEST);

    // Define color de fondo
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Configura proyección
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    EsferaDisplayList* esfera = dynamic_cast<EsferaDisplayList*>(arrayObjectDisplayList[0]);
    if (esfera) {
        esfera->Draw();
    }

    arrayObjectDisplayList[0] = new EsferaDisplayList();
    arrayObjectDisplayList[1] = new CuboDisplayList();
    arrayObjectDisplayList[2] = new PiramideDisplayList();
    arrayObjectDisplayList[3] = new CuadradoDisplayList();

    // Vertex Array Simple
    arrayObjectVertexSimple[0] = new EsferaVertexArray();
    arrayObjectVertexSimple[1] = new CuboVertexArray();
    arrayObjectVertexSimple[2] = new PiramideVertexArray();
    arrayObjectVertexSimple[3] = new CuadradoVertexArray();

    // Vertex Array con Índices
    arrayObjectVertexIndex[0] = new EsferaVAIndex();
    arrayObjectVertexIndex[1] = new CuboVAIndex();
    arrayObjectVertexIndex[2] = new PiramideVAIndex();
    arrayObjectVertexIndex[3] = new CuadradoVAIndex();

    // Vertex Array Instanciado
    arrayObjectVertexInstanced[0] = new EsferaVAInstanced();
    arrayObjectVertexInstanced[1] = new CuboVAInstanced();
    arrayObjectVertexInstanced[2] = new PiramideVAInstanced();
    arrayObjectVertexInstanced[3] = new CuadradoVAInstanced();
}

void Example7::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    // Dibuja las figuras usando Display List
    for (int i = 0; i < 4; ++i) {
        if (arrayObjectDisplayList[i] != nullptr) {
            glPushMatrix();
            arrayObjectDisplayList[i]->Draw();
            glPopMatrix();
        }
    }

    glFlush();
}

void Example7::KeyboardFunc(unsigned char key, int X, int Y)
{
    if (key == 27) // ESC
        exit(0);
}

void Example7::Idle()
{
    // Podrías actualizar variables aquí
    // Y solicitar un redibujo
    // glutPostRedisplay(); // Descomenta si usas GLUT
}