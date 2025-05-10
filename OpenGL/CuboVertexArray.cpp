#include "CuboVertexArray.h"

CuboVertexArray::CuboVertexArray()
{
    vertexCount = 36; // 12 triángulos * 3 vértices
    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    // Vértices del cubo (similar al código anterior)
    GLfloat cubeVertices[] = {
        // Cara frontal
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        // Cara trasera
        -0.5f, -0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,

         // Cara izquierda
         -0.5f, -0.5f, -0.5f,
         -0.5f, -0.5f,  0.5f,
         -0.5f,  0.5f,  0.5f,
         -0.5f, -0.5f, -0.5f,
         -0.5f,  0.5f,  0.5f,
         -0.5f,  0.5f, -0.5f,

         // Cara derecha
          0.5f, -0.5f, -0.5f,
          0.5f,  0.5f, -0.5f,
          0.5f,  0.5f,  0.5f,
          0.5f, -0.5f, -0.5f,
          0.5f,  0.5f,  0.5f,
          0.5f, -0.5f,  0.5f,

          // Cara superior
          -0.5f,  0.5f, -0.5f,
          -0.5f,  0.5f,  0.5f,
           0.5f,  0.5f,  0.5f,
          -0.5f,  0.5f, -0.5f,
           0.5f,  0.5f,  0.5f,
           0.5f,  0.5f, -0.5f,

           // Cara inferior
           -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
           -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
           -0.5f, -0.5f,  0.5f
    };

    // Copiamos los vértices
    memcpy(vertices, cubeVertices, sizeof(cubeVertices));

    // Asignamos colores por cara
    for (int i = 0; i < vertexCount; i += 6) {
        float r = (i / 6) % 2 == 0 ? 1.0f : 0.5f;
        float g = ((i / 6) / 2) % 2 == 0 ? 1.0f : 0.5f;
        float b = ((i / 6) / 4) % 2 == 0 ? 1.0f : 0.5f;

        for (int j = 0; j < 6; j++) {
            colors[(i + j) * 3 + 0] = r;
            colors[(i + j) * 3 + 1] = g;
            colors[(i + j) * 3 + 2] = b;
        }
    }
}
void CuboVertexArray::InitBuffers()
{
    vertexCount = 36;

    GLfloat cubeVerts[] = {
        // Frente
        -1,-1, 1,   1,-1, 1,   1, 1, 1,
        -1,-1, 1,   1, 1, 1,  -1, 1, 1,
        // Atrás
        -1,-1,-1,  -1, 1,-1,   1, 1,-1,
        -1,-1,-1,   1, 1,-1,   1,-1,-1,
        // Izquierda
        -1,-1,-1,  -1,-1, 1,  -1, 1, 1,
        -1,-1,-1,  -1, 1, 1,  -1, 1,-1,
        // Derecha
         1,-1,-1,   1, 1,-1,   1, 1, 1,
         1,-1,-1,   1, 1, 1,   1,-1, 1,
         // Arriba
         -1, 1,-1,  -1, 1, 1,   1, 1, 1,
         -1, 1,-1,   1, 1, 1,   1, 1,-1,
         // Abajo
         -1,-1,-1,   1,-1,-1,   1,-1, 1,
         -1,-1,-1,   1,-1, 1,  -1,-1, 1
    };

    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    for (int i = 0; i < vertexCount * 3; ++i) {
        vertices[i] = cubeVerts[i];
        colors[i] = (i % 3 == 0) ? 1.0f : (i % 3 == 1 ? 0.5f : 0.2f);
    }
}
