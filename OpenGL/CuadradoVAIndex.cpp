#include "CuadradoVAIndex.h"

CuadradoVAIndex::CuadradoVAIndex()
{
    vertexCount = 4;
    indexCount = 6;  // Dos triángulos para el cuadrado

    vertices = new GLfloat[vertexCount * 3]{
        -1.0f, -1.0f, 0.0f,  // Vértice 1
         1.0f, -1.0f, 0.0f,  // Vértice 2
         1.0f,  1.0f, 0.0f,  // Vértice 3
        -1.0f,  1.0f, 0.0f   // Vértice 4
    };

    colors = new GLfloat[vertexCount * 3]{
        1.0f, 0.0f, 0.0f,  // Color rojo
        0.0f, 1.0f, 0.0f,  // Color verde
        0.0f, 0.0f, 1.0f,  // Color azul
        1.0f, 1.0f, 0.0f   // Color amarillo
    };

    indices = new GLuint[indexCount]{
        0, 1, 2,  // Triángulo 1
        0, 2, 3   // Triángulo 2
    };
}
void CuadradoVAIndex::InitBuffers() {
    vertexCount = 4;
    indexCount = 6;

    vertices = new GLfloat[vertexCount * 3]{
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    colors = new GLfloat[vertexCount * 3]{
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        1, 1, 0
    };

    indices = new GLuint[indexCount]{
        0, 1, 2,
        2, 3, 0
    };
}
