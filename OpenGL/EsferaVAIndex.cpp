#include "EsferaVAIndex.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
EsferaVAIndex::EsferaVAIndex()
{
    vertexCount = 1824;
    indexCount = 3624;

    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];
    indices = new GLuint[indexCount];

    int idx = 0;
    for (int i = 0; i < 180; i++) {
        float theta = i * M_PI / 180;  // Ángulo polar
        for (int j = 0; j < 360; j++) {
            float phi = j * M_PI / 180;  // Ángulo azimutal

            float x = sin(theta) * cos(phi);
            float y = sin(theta) * sin(phi);
            float z = cos(theta);

            vertices[idx++] = x;
            vertices[idx++] = y;
            vertices[idx++] = z;

            // Asignamos un color simple (por ejemplo, un gradiente)
            colors[idx - 3] = (x + 1) / 2;
            colors[idx - 2] = (y + 1) / 2;
            colors[idx - 1] = (z + 1) / 2;
        }
    }
}

void EsferaVAIndex::InitBuffers()
{
    const int slices = 20;
    const int stacks = 20;
    const float radius = 0.5f;

    vertexCount = (slices + 1) * (stacks + 1);
    indexCount = slices * stacks * 6;

    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];
    indices = new GLuint[indexCount];

    int idx = 0;
    for (int i = 0; i <= stacks; ++i) {
        float phi = M_PI * i / stacks;
        for (int j = 0; j <= slices; ++j) {
            float theta = 2 * M_PI * j / slices;

            float x = radius * sin(phi) * cos(theta);
            float y = radius * cos(phi);
            float z = radius * sin(phi) * sin(theta);

            int pos = (i * (slices + 1) + j) * 3;
            vertices[pos + 0] = x;
            vertices[pos + 1] = y;
            vertices[pos + 2] = z;

            colors[pos + 0] = (x + 0.5f);
            colors[pos + 1] = (y + 0.5f);
            colors[pos + 2] = (z + 0.5f);
        }
    }

    idx = 0;
    for (int i = 0; i < stacks; ++i) {
        for (int j = 0; j < slices; ++j) {
            int first = i * (slices + 1) + j;
            int second = first + slices + 1;

            indices[idx++] = first;
            indices[idx++] = second;
            indices[idx++] = first + 1;

            indices[idx++] = second;
            indices[idx++] = second + 1;
            indices[idx++] = first + 1;
        }
    }
}
