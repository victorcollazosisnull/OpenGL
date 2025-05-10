#include "PiramideVAInstanced.h"
#include <cmath>
#include <vector>
PiramideVAInstanced::PiramideVAInstanced() {
    vertexCount = 0;
    instanceCount = 5;  // Número de instancias visibles
    InitBuffers();      // Inicializar los buffers de datos
}

void PiramideVAInstanced::InitBuffers() {
    // Vértices para una pirámide 3D
    std::vector<GLfloat> pyramidVertices = {
        // Base
        -0.5f, -0.5f, -0.5f,  // Vértice 1
         0.5f, -0.5f, -0.5f,  // Vértice 2
         0.5f, -0.5f,  0.5f,  // Vértice 3
        -0.5f, -0.5f,  0.5f,  // Vértice 4
        // Punta de la pirámide
         0.0f,  0.5f,  0.0f   // Vértice 5
    };

    std::vector<GLfloat> pyramidColors = {
        1.0f, 0.0f, 0.0f,  // Rojo
        0.0f, 1.0f, 0.0f,  // Verde
        0.0f, 0.0f, 1.0f,  // Azul
        1.0f, 1.0f, 0.0f,  // Amarillo
        1.0f, 0.0f, 1.0f   // Magenta
    };

    vertexCount = static_cast<int>(pyramidVertices.size() / 3);  // Número de vértices

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