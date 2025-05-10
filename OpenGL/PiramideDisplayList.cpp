#include "PiramideDisplayList.h"

PiramideDisplayList::PiramideDisplayList() {
    InitBuffers();  // Inicializar buffers y generar Display List
}

void PiramideDisplayList::InitBuffers() {
    displayList = glGenLists(1);  // Generar un Display List

    glNewList(displayList, GL_COMPILE);  // Comenzar a compilar el Display List

    GLfloat vertices[] = {
        // Base
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,

         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,

        // Lados (4 triángulos)
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         0.0f,  1.0f,  0.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         0.0f,  1.0f,  0.0f,

         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,
         0.0f,  1.0f,  0.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
         0.0f,  1.0f,  0.0f
    };

    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,  // Rojo
        0.0f, 1.0f, 0.0f,  // Verde
        0.0f, 0.0f, 1.0f,  // Azul
        0.0f, 1.0f, 1.0f,  // Cian
        1.0f, 1.0f, 0.0f,  // Amarillo
        1.0f, 0.0f, 1.0f   // Magenta
    };

    // Habilitar los arrays de vértices y colores
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0, 18);  // Dibujar la pirámide

    glEndList();  // Terminar la compilación del Display List
}
