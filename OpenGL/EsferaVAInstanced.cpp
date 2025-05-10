#include "EsferaVAInstanced.h"
#include <cmath>
#include <vector>
#define M_PI 3.14159265358979323846
EsferaVAInstanced::EsferaVAInstanced() {
    vertexCount = 0;
    instanceCount = 5;  // Cantidad de instancias visibles
    InitBuffers();  // Asegúrate de que este método es llamado desde la clase derivada
}

EsferaVAInstanced::~EsferaVAInstanced() {
    glDeleteBuffers(1, &vboVertices);
    glDeleteBuffers(1, &vboColors);
    glDeleteVertexArrays(1, &vao);
}

void EsferaVAInstanced::InitBuffers() {
    const int stacks = 10;
    const int slices = 10;
    const float radius = 1.0f;

    std::vector<GLfloat> sphereVertices;
    std::vector<GLfloat> sphereColors;

    for (int i = 0; i <= stacks; ++i) {
        float phi = i * M_PI / stacks;
        for (int j = 0; j <= slices; ++j) {
            float theta = j * 2.0f * M_PI / slices;

            float x = radius * sinf(phi) * cosf(theta);
            float y = radius * cosf(phi);
            float z = radius * sinf(phi) * sinf(theta);

            sphereVertices.push_back(x);
            sphereVertices.push_back(y);
            sphereVertices.push_back(z);

            sphereColors.push_back((x + 1) / 2.0f);
            sphereColors.push_back((y + 1) / 2.0f);
            sphereColors.push_back((z + 1) / 2.0f);
        }
    }

    vertexCount = static_cast<int>(sphereVertices.size() / 3);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, sphereVertices.size() * sizeof(GLfloat), sphereVertices.data(), GL_STATIC_DRAW);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);

    glGenBuffers(1, &vboColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboColors);
    glBufferData(GL_ARRAY_BUFFER, sphereColors.size() * sizeof(GLfloat), sphereColors.data(), GL_STATIC_DRAW);
    glColorPointer(3, GL_FLOAT, 0, 0);
    glEnableClientState(GL_COLOR_ARRAY);

    glBindVertexArray(0);
}