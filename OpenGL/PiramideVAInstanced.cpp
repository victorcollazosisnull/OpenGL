#include "PiramideVAInstanced.h"
#include <cmath>
#include <vector>
PiramideVAInstanced::PiramideVAInstanced() {
    vertexCount = 0;
    instanceCount = 5;  // N�mero de instancias visibles
    InitBuffers();      // Inicializar los buffers de datos
}

void PiramideVAInstanced::InitBuffers() {
    // V�rtices para una pir�mide 3D
    std::vector<GLfloat> pyramidVertices = {
        // Base
        -0.5f, -0.5f, -0.5f,  // V�rtice 1
         0.5f, -0.5f, -0.5f,  // V�rtice 2
         0.5f, -0.5f,  0.5f,  // V�rtice 3
        -0.5f, -0.5f,  0.5f,  // V�rtice 4
        // Punta de la pir�mide
         0.0f,  0.5f,  0.0f   // V�rtice 5
    };

    std::vector<GLfloat> pyramidColors = {
        1.0f, 0.0f, 0.0f,  // Rojo
        0.0f, 1.0f, 0.0f,  // Verde
        0.0f, 0.0f, 1.0f,  // Azul
        1.0f, 1.0f, 0.0f,  // Amarillo
        1.0f, 0.0f, 1.0f   // Magenta
    };

    vertexCount = static_cast<int>(pyramidVertices.size() / 3);  // N�mero de v�rtices

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, pyramidVertices.size() * sizeof(GLfloat), pyramidVertices.data(), GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);

    glGenBuffers(1, &vboColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboColors);
    glBufferData(GL_ARRAY_BUFFER, pyramidColors.size() * sizeof(GLfloat), pyramidColors.data(), GL_STATIC_DRAW);
    glColorPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindVertexArray(0);
}