#include "PiramideVertexArray.h"

PiramideVertexArray::PiramideVertexArray()
{
    vertexCount = 18; // 6 triángulos * 3 vértices
    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    // Vértices de la pirámide
    GLfloat pyramidVertices[] = {
        // Base (2 triángulos)
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        // 4 caras laterales
        // Cara frontal
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.0f,  0.5f,  0.0f,

         // Cara trasera
         -0.5f, -0.5f, -0.5f,
          0.0f,  0.5f,  0.0f,
          0.5f, -0.5f, -0.5f,

          // Cara izquierda
          -0.5f, -0.5f, -0.5f,
          -0.5f, -0.5f,  0.5f,
           0.0f,  0.5f,  0.0f,

           // Cara derecha
            0.5f, -0.5f, -0.5f,
            0.0f,  0.5f,  0.0f,
            0.5f, -0.5f,  0.5f
    };

    // Copiamos los vértices
    memcpy(vertices, pyramidVertices, sizeof(pyramidVertices));

    // Asignamos colores por cara
    // Base
    for (int i = 0; i < 6; i++) {
        colors[i * 3 + 0] = 1.0f; // R
        colors[i * 3 + 1] = 0.0f; // G
        colors[i * 3 + 2] = 0.0f; // B
    }

    // Cara frontal
    for (int i = 6; i < 9; i++) {
        colors[i * 3 + 0] = 0.0f; // R
        colors[i * 3 + 1] = 1.0f; // G
        colors[i * 3 + 2] = 0.0f; // B
    }

    // Cara trasera
    for (int i = 9; i < 12; i++) {
        colors[i * 3 + 0] = 0.0f; // R
        colors[i * 3 + 1] = 0.0f; // G
        colors[i * 3 + 2] = 1.0f; // B
    }

    // Cara izquierda
    for (int i = 12; i < 15; i++) {
        colors[i * 3 + 0] = 1.0f; // R
        colors[i * 3 + 1] = 1.0f; // G
        colors[i * 3 + 2] = 0.0f; // B
    }

    // Cara derecha
    for (int i = 15; i < 18; i++) {
        colors[i * 3 + 0] = 1.0f; // R
        colors[i * 3 + 1] = 0.0f; // G
        colors[i * 3 + 2] = 1.0f; // B
    }
}

void PiramideVertexArray::InitBuffers()
{
    vertexCount = 18;

    GLfloat verts[] = {
        // Base
        -1,-1,-1,  1,-1,-1,  1,-1,1,
        -1,-1,-1,  1,-1,1,  -1,-1,1,
        // Lados
        -1,-1,-1,  1,-1,-1,  0,1,0,
         1,-1,-1,   1,-1,1,  0,1,0,
         1,-1,1,  -1,-1,1,  0,1,0,
        -1,-1,1,  -1,-1,-1, 0,1,0
    };

    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    for (int i = 0; i < vertexCount * 3; ++i) {
        vertices[i] = verts[i];
        colors[i] = (i % 3 == 0) ? 1.0f : (i % 3 == 1 ? 0.3f : 0.7f);
    }
}
