#include "CuboDisplayList.h"

CuboDisplayList::CuboDisplayList() {
    InitBuffers();  // Inicializar los buffers y generar el Display List
}

void CuboDisplayList::InitBuffers() {
    displayList = glGenLists(1);  // Generar un Display List

    glNewList(displayList, GL_COMPILE);  // Comenzar a compilar el Display List

    // Definir los vértices y colores del cubo
    GLfloat vertices[] = {
        // Cara trasera
        -1, -1, -1,  1, -1, -1,  1,  1, -1,
         1,  1, -1, -1,  1, -1, -1, -1, -1,
         // Cara delantera
         -1, -1,  1,  1, -1,  1,  1,  1,  1,
          1,  1,  1, -1,  1,  1, -1, -1,  1,
          // Cara izquierda
          -1, -1, -1, -1,  1, -1, -1,  1,  1,
          -1,  1,  1, -1, -1,  1, -1, -1, -1,
          // Cara derecha
           1, -1, -1,  1,  1, -1,  1,  1,  1,
           1,  1,  1,  1, -1,  1,  1, -1, -1,
           // Cara superior
           -1,  1, -1,  1,  1, -1,  1,  1,  1,
            1,  1,  1, -1,  1,  1, -1,  1, -1,
            // Cara inferior
            -1, -1, -1,  1, -1, -1,  1, -1,  1,
             1, -1,  1, -1, -1,  1, -1, -1, -1
    };

    GLfloat colors[] = {
        // Colores por vértice (repetido 36 veces)
        1, 0, 0,  1, 1, 0,  0, 1, 0,
        0, 1, 0,  0, 1, 1,  1, 0, 1,

        1, 0, 0,  1, 1, 0,  0, 1, 0,
        0, 1, 0,  0, 1, 1,  1, 0, 1,

        1, 0, 0,  1, 1, 0,  0, 1, 0,
        0, 1, 0,  0, 1, 1,  1, 0, 1,

        1, 0, 0,  1, 1, 0,  0, 1, 0,
        0, 1, 0,  0, 1, 1,  1, 0, 1,

        1, 0, 0,  1, 1, 0,  0, 1, 0,
        0, 1, 0,  0, 1, 1,  1, 0, 1,

        1, 0, 0,  1, 1, 0,  0, 1, 0,
        0, 1, 0,  0, 1, 1,  1, 0, 1
    };

    // Habilitar el uso de los arrays de vértices y colores
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0, 36);  // Dibujar los vértices

    glEndList();  // Terminar la compilación del Display List
}