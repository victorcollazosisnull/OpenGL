#include "EsferaDisplayList.h"

EsferaDisplayList::EsferaDisplayList() {
    InitBuffers();  // Inicializar buffers y generar Display List
}

void EsferaDisplayList::InitBuffers() {
    displayList = glGenLists(1);  // Generar un Display List

    glNewList(displayList, GL_COMPILE);  // Comenzar a compilar el Display List

    // Aqu� puedes definir los v�rtices y colores para la esfera. 
    // A continuaci�n, un ejemplo simple de c�mo generar una esfera utilizando tri�ngulos.

    const int slices = 30;  // Cantidad de segmentos horizontales
    const int stacks = 30;  // Cantidad de segmentos verticales

    GLfloat radius = 1.0f;

    GLfloat* vertices = new GLfloat[slices * stacks * 9]; // 3 v�rtices por tri�ngulo (x, y, z)
    GLfloat* colors = new GLfloat[slices * stacks * 9];   // Colores de cada v�rtice

    // L�gica de generaci�n de los v�rtices de la esfera aqu�

    // Deshabilitamos los arrays de v�rtices y colores despu�s de dibujar
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0, slices * stacks * 3);  // Dibujar la esfera

    glEndList();  // Terminar la compilaci�n del Display List

    delete[] vertices;
    delete[] colors;
}