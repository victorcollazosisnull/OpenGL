#include "EsferaDisplayList.h"

EsferaDisplayList::EsferaDisplayList() {
    InitBuffers();  // Inicializar buffers y generar Display List
}

void EsferaDisplayList::InitBuffers() {
    displayList = glGenLists(1);  // Generar un Display List

    glNewList(displayList, GL_COMPILE);  // Comenzar a compilar el Display List

    // Aquí puedes definir los vértices y colores para la esfera. 
    // A continuación, un ejemplo simple de cómo generar una esfera utilizando triángulos.

    const int slices = 30;  // Cantidad de segmentos horizontales
    const int stacks = 30;  // Cantidad de segmentos verticales

    GLfloat radius = 1.0f;

    GLfloat* vertices = new GLfloat[slices * stacks * 9]; // 3 vértices por triángulo (x, y, z)
    GLfloat* colors = new GLfloat[slices * stacks * 9];   // Colores de cada vértice

    // Lógica de generación de los vértices de la esfera aquí

    // Deshabilitamos los arrays de vértices y colores después de dibujar
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0, slices * stacks * 3);  // Dibujar la esfera

    glEndList();  // Terminar la compilación del Display List

    delete[] vertices;
    delete[] colors;
}