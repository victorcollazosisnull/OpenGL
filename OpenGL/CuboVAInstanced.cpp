#include "CuboVAInstanced.h"

CuboVAInstanced::CuboVAInstanced() {
    vertexCount = 36; // 12 triángulos x 3 vértices
    instanceCount = 10; // número de copias del cubo
    InitBuffers();
}

void CuboVAInstanced::InitBuffers() {
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

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // VBO de vértices
    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);

    // VBO de colores
    glGenBuffers(1, &vboColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboColors);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
    glColorPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindVertexArray(0);
}