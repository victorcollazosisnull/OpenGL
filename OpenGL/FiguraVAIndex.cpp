#include "FiguraVAIndex.h"

FiguraVAIndex::FiguraVAIndex() : vertices(nullptr), colors(nullptr), indices(nullptr), vertexCount(0), indexCount(0) {}

FiguraVAIndex::~FiguraVAIndex() {
    delete[] vertices;
    delete[] colors;
    delete[] indices;
}
void FiguraVAIndex::InitBuffers() {
    // Definir los datos de los vértices, colores e índices (ejemplo con un triángulo)
    vertexCount = 3;
    indexCount = 3;

    // Reservar memoria para los vértices, colores e índices
    vertices = new GLfloat[vertexCount * 3]; // 3 valores por vértice (x, y, z)
    colors = new GLfloat[vertexCount * 3];   // 3 valores por color (r, g, b)
    indices = new GLuint[indexCount];        // Índices para los vértices

    // Asignar valores de vértices
    vertices[0] = 0.0f; vertices[1] = 1.0f; vertices[2] = 0.0f; // Vértice 1
    vertices[3] = -1.0f; vertices[4] = -1.0f; vertices[5] = 0.0f; // Vértice 2
    vertices[6] = 1.0f; vertices[7] = -1.0f; vertices[8] = 0.0f; // Vértice 3

    // Asignar valores de colores
    colors[0] = 1.0f; colors[1] = 0.0f; colors[2] = 0.0f; // Rojo
    colors[3] = 0.0f; colors[4] = 1.0f; colors[5] = 0.0f; // Verde
    colors[6] = 0.0f; colors[7] = 0.0f; colors[8] = 1.0f; // Azul

    // Asignar valores de índices (usamos un triángulo)
    indices[0] = 0; // Vértice 1
    indices[1] = 1; // Vértice 2
    indices[2] = 2; // Vértice 3

    // Crear y cargar los buffers de OpenGL
    GLuint vboVertices, vboColors, eboIndices;

    // Crear el buffer para los vértices
    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    // Crear el buffer para los colores
    glGenBuffers(1, &vboColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboColors);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), colors, GL_STATIC_DRAW);

    // Crear el buffer para los índices
    glGenBuffers(1, &eboIndices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboIndices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(GLuint), indices, GL_STATIC_DRAW);

    // Desvincular buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void FiguraVAIndex::Draw() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}