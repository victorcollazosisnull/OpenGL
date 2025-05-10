#include "PiramideVAIndex.h"

PiramideVAIndex::PiramideVAIndex()
{
    vertexCount = 5;  // 4 v�rtices de la base + 1 v�rtice para el �pice
    indexCount = 18;  // 6 tri�ngulos (4 caras laterales + 2 para la base)

    vertices = new GLfloat[vertexCount * 3]{
        // V�rtices de la base
        -1.0f, -1.0f, 0.0f,  // V�rtice 0 (base)
         1.0f, -1.0f, 0.0f,  // V�rtice 1 (base)
         1.0f,  1.0f, 0.0f,  // V�rtice 2 (base)
        -1.0f,  1.0f, 0.0f,  // V�rtice 3 (base)

        // V�rtice para el �pice
         0.0f,  0.0f, 2.0f   // V�rtice 4 (�pice)
    };

    colors = new GLfloat[vertexCount * 3]{
        1.0f, 0.0f, 0.0f,  // Color rojo
        0.0f, 1.0f, 0.0f,  // Color verde
        0.0f, 0.0f, 1.0f,  // Color azul
        1.0f, 1.0f, 0.0f,  // Color amarillo
        1.0f, 0.5f, 0.0f   // Color naranja (�pice)
    };

    indices = new GLuint[indexCount]{
        0, 1, 4,  // Cara 1
        1, 2, 4,  // Cara 2
        2, 3, 4,  // Cara 3
        3, 0, 4,  // Cara 4

        0, 1, 2,  // Base (tri�ngulo 1)
        0, 2, 3   // Base (tri�ngulo 2)
    };
}

void PiramideVAIndex::InitBuffers()
{
    vertexCount = 5;
    indexCount = 18;

    vertices = new GLfloat[vertexCount * 3]{
         0.0f,  0.5f,  0.0f,  // top
        -0.5f, -0.5f, -0.5f,  // back left
         0.5f, -0.5f, -0.5f,  // back right
         0.5f, -0.5f,  0.5f,  // front right
        -0.5f, -0.5f,  0.5f   // front left
    };

    colors = new GLfloat[vertexCount * 3]{
        1, 1, 1,
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        1, 1, 0
    };

    indices = new GLuint[indexCount]{
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 1,
        1, 2, 3,
        3, 4, 1
    };
}
