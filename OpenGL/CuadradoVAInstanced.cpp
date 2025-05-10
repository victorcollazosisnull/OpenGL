#include "CuadradoVAInstanced.h"
#include <cmath>
#include <vector>
CuadradoVAInstanced::CuadradoVAInstanced() {
    vertexCount = 0;
    instanceCount = 5;  // N�mero de instancias visibles
    InitBuffers();      // Inicializar los buffers de datos
}

void CuadradoVAInstanced::InitBuffers() {
    // Definici�n de los v�rtices para un cuadrado 2D
    std::vector<GLfloat> squareVertices = {
        -0.5f, -0.5f, 0.0f,  // V�rtice 1
         0.5f, -0.5f, 0.0f,  // V�rtice 2
         0.5f,  0.5f, 0.0f,  // V�rtice 3
        -0.5f,  0.5f, 0.0f   // V�rtice 4
    };

    std::vector<GLfloat> squareColors = {
        1.0f, 0.0f, 0.0f,  // Rojo
        0.0f, 1.0f, 0.0f,  // Verde
        0.0f, 0.0f, 1.0f,  // Azul
        1.0f, 1.0f, 0.0f   // Amarillo
    };

    vertexCount = static_cast<int>(squareVertices.size() / 3);  // N�mero de v�rtices

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, squareVertices.size() * sizeof(GLfloat), squareVertices.data(), GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);

    glGenBuffers(1, &vboColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboColors);
    glBufferData(GL_ARRAY_BUFFER, squareColors.size() * sizeof(GLfloat), squareColors.data(), GL_STATIC_DRAW);
    glColorPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindVertexArray(0);
}