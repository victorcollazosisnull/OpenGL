#include "EsferaVertexArray.h"
#include <cmath>
#define M_PI 3.14159265358979323846
EsferaVertexArray::EsferaVertexArray(int slices, int stacks)
{
    vertexCount = slices * stacks * 6;
    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    // Generamos los vértices de la esfera
    const float PI = 3.14159265359f;
    int vertexIndex = 0;

    for (int i = 0; i < stacks; i++) {
        float phi1 = PI * float(i) / float(stacks);
        float phi2 = PI * float(i + 1) / float(stacks);

        for (int j = 0; j < slices; j++) {
            float theta1 = 2.0f * PI * float(j) / float(slices);
            float theta2 = 2.0f * PI * float(j + 1) / float(slices);

            // 4 vértices del quad
            float x1 = sin(phi1) * cos(theta1);
            float y1 = cos(phi1);
            float z1 = sin(phi1) * sin(theta1);

            float x2 = sin(phi1) * cos(theta2);
            float y2 = cos(phi1);
            float z2 = sin(phi1) * sin(theta2);

            float x3 = sin(phi2) * cos(theta2);
            float y3 = cos(phi2);
            float z3 = sin(phi2) * sin(theta2);

            float x4 = sin(phi2) * cos(theta1);
            float y4 = cos(phi2);
            float z4 = sin(phi2) * sin(theta1);

            // Primer triángulo
            vertices[vertexIndex++] = x1 * 0.5f;
            vertices[vertexIndex++] = y1 * 0.5f;
            vertices[vertexIndex++] = z1 * 0.5f;

            vertices[vertexIndex++] = x2 * 0.5f;
            vertices[vertexIndex++] = y2 * 0.5f;
            vertices[vertexIndex++] = z2 * 0.5f;

            vertices[vertexIndex++] = x3 * 0.5f;
            vertices[vertexIndex++] = y3 * 0.5f;
            vertices[vertexIndex++] = z3 * 0.5f;

            // Segundo triángulo
            vertices[vertexIndex++] = x1 * 0.5f;
            vertices[vertexIndex++] = y1 * 0.5f;
            vertices[vertexIndex++] = z1 * 0.5f;

            vertices[vertexIndex++] = x3 * 0.5f;
            vertices[vertexIndex++] = y3 * 0.5f;
            vertices[vertexIndex++] = z3 * 0.5f;

            vertices[vertexIndex++] = x4 * 0.5f;
            vertices[vertexIndex++] = y4 * 0.5f;
            vertices[vertexIndex++] = z4 * 0.5f;
        }
    }

    // Asignamos colores azules a todos los vértices
    for (int i = 0; i < vertexCount * 3; i += 3) {
        colors[i + 0] = 0.0f; // R
        colors[i + 1] = 0.0f; // G
        colors[i + 2] = 1.0f; // B
    }
}

void EsferaVertexArray::InitBuffers()
{
    int slices = 20;
    int stacks = 20;
    vertexCount = slices * stacks * 6; // 2 triángulos por cuadrito

    vertices = new GLfloat[vertexCount * 3];
    colors = new GLfloat[vertexCount * 3];

    int idx = 0;
    for (int i = 0; i < stacks; ++i) {
        float phi1 = (float)i / stacks * M_PI;
        float phi2 = (float)(i + 1) / stacks * M_PI;

        for (int j = 0; j < slices; ++j) {
            float theta1 = (float)j / slices * 2 * M_PI;
            float theta2 = (float)(j + 1) / slices * 2 * M_PI;

            // 2 triángulos por cuadrado
            float x1 = sin(phi1) * cos(theta1);
            float y1 = cos(phi1);
            float z1 = sin(phi1) * sin(theta1);

            float x2 = sin(phi2) * cos(theta1);
            float y2 = cos(phi2);
            float z2 = sin(phi2) * sin(theta1);

            float x3 = sin(phi2) * cos(theta2);
            float y3 = cos(phi2);
            float z3 = sin(phi2) * sin(theta2);

            float x4 = sin(phi1) * cos(theta2);
            float y4 = cos(phi1);
            float z4 = sin(phi1) * sin(theta2);

            // Triángulo 1
            vertices[idx * 3 + 0] = x1; vertices[idx * 3 + 1] = y1; vertices[idx * 3 + 2] = z1;
            colors[idx * 3 + 0] = 1; colors[idx * 3 + 1] = 0; colors[idx * 3 + 2] = 0;
            idx++;

            vertices[idx * 3 + 0] = x2; vertices[idx * 3 + 1] = y2; vertices[idx * 3 + 2] = z2;
            colors[idx * 3 + 0] = 0; colors[idx * 3 + 1] = 1; colors[idx * 3 + 2] = 0;
            idx++;

            vertices[idx * 3 + 0] = x3; vertices[idx * 3 + 1] = y3; vertices[idx * 3 + 2] = z3;
            colors[idx * 3 + 0] = 0; colors[idx * 3 + 1] = 0; colors[idx * 3 + 2] = 1;
            idx++;

            // Triángulo 2
            vertices[idx * 3 + 0] = x3; vertices[idx * 3 + 1] = y3; vertices[idx * 3 + 2] = z3;
            colors[idx * 3 + 0] = 0; colors[idx * 3 + 1] = 0; colors[idx * 3 + 2] = 1;
            idx++;

            vertices[idx * 3 + 0] = x4; vertices[idx * 3 + 1] = y4; vertices[idx * 3 + 2] = z4;
            colors[idx * 3 + 0] = 1; colors[idx * 3 + 1] = 1; colors[idx * 3 + 2] = 0;
            idx++;

            vertices[idx * 3 + 0] = x1; vertices[idx * 3 + 1] = y1; vertices[idx * 3 + 2] = z1;
            colors[idx * 3 + 0] = 1; colors[idx * 3 + 1] = 0; colors[idx * 3 + 2] = 0;
            idx++;
        }
    }
}
