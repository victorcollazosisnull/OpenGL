#include "CuadradoVertexArray.h"

CuadradoVertexArray::CuadradoVertexArray()
{
    vertexCount = 6; // 2 tri�ngulos * 3 v�rtices
    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    // V�rtices del cuadrado
    GLfloat quadVertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    // Copiamos los v�rtices
    memcpy(vertices, quadVertices, sizeof(quadVertices));

    // Asignamos color verde a todos los v�rtices
    for (int i = 0; i < vertexCount; i++) {
        colors[i * 3 + 0] = 0.0f; // R
        colors[i * 3 + 1] = 1.0f; // G
        colors[i * 3 + 2] = 0.0f; // B
    }
}

void CuadradoVertexArray::InitBuffers()
{
    vertexCount = 6;

    GLfloat verts[] = {
        -1,-1,0,   1,-1,0,   1,1,0,
        -1,-1,0,   1,1,0,  -1,1,0
    };

    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    for (int i = 0; i < vertexCount * 3; ++i) {
        vertices[i] = verts[i];
        colors[i] = 0.5f + 0.5f * (i % 3);  // degradado simple
    }
}
