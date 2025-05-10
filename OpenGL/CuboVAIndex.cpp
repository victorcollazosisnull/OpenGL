#include "CuboVAIndex.h"

CuboVAIndex::CuboVAIndex() {
    vertexCount = 8;
    indexCount = 36;

    vertices = new GLfloat[24]{
        -1, -1, -1,  1, -1, -1,  1,  1, -1,  -1,  1, -1,
        -1, -1,  1,  1, -1,  1,  1,  1,  1,  -1,  1,  1
    };

    colors = new GLfloat[24]{
        1, 0, 0,  1, 1, 0,  0, 1, 0,  0, 1, 1,
        0, 0, 1,  1, 0, 1,  1, 1, 1,  0, 0, 0
    };

    indices = new GLuint[36]{
        0, 1, 2,  2, 3, 0,  // back
        4, 5, 6,  6, 7, 4,  // front
        0, 4, 7,  7, 3, 0,  // left
        1, 5, 6,  6, 2, 1,  // right
        3, 2, 6,  6, 7, 3,  // top
        0, 1, 5,  5, 4, 0   // bottom
    };
}

void CuboVAIndex::InitBuffers()
{
    vertexCount = 8;
    indexCount = 36;

    vertices = new GLfloat[vertexCount * 3]{
        -0.5, -0.5, -0.5, // 0
         0.5, -0.5, -0.5, // 1
         0.5,  0.5, -0.5, // 2
        -0.5,  0.5, -0.5, // 3
        -0.5, -0.5,  0.5, // 4
         0.5, -0.5,  0.5, // 5
         0.5,  0.5,  0.5, // 6
        -0.5,  0.5,  0.5  // 7
    };

    colors = new GLfloat[vertexCount * 3]{
        1, 0, 0,  0, 1, 0,  0, 0, 1,  1, 1, 0,
        1, 0, 1,  0, 1, 1,  1, 1, 1,  0.5, 0.5, 0.5
    };

    indices = new GLuint[indexCount]{
        0, 1, 2, 2, 3, 0, // back
        4, 5, 6, 6, 7, 4, // front
        0, 4, 7, 7, 3, 0, // left
        1, 5, 6, 6, 2, 1, // right
        3, 2, 6, 6, 7, 3, // top
        0, 1, 5, 5, 4, 0  // bottom
    };
}
