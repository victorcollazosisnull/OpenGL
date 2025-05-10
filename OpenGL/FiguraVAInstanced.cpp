#include "FiguraVAInstanced.h"

FiguraVAInstanced::FiguraVAInstanced()
    : vboVertices(0), vboColors(0), vao(0), vertexCount(0), instanceCount(10) // dibuja 10 instancias por defecto
{
}

FiguraVAInstanced::~FiguraVAInstanced() {
    glDeleteBuffers(1, &vboVertices);
    glDeleteBuffers(1, &vboColors);
    glDeleteVertexArrays(1, &vao);
}
void FiguraVAInstanced::InitBuffers() {
    // Define los datos de los vértices y colores
    vertexCount = 3; // Número de vértices por figura
    instanceCount = 10; // Número de instancias a dibujar

    GLfloat* vertices = new GLfloat[vertexCount * 3]; // 3 valores por vértice (x, y, z)
    GLfloat* colors = new GLfloat[vertexCount * 3]; // 3 valores por color (r, g, b)

    // Asignar valores de vértices
    vertices[0] = 0.0f; vertices[1] = 1.0f; vertices[2] = 0.0f; // Vértice 1
    vertices[3] = -1.0f; vertices[4] = -1.0f; vertices[5] = 0.0f; // Vértice 2
    vertices[6] = 1.0f; vertices[7] = -1.0f; vertices[8] = 0.0f; // Vértice 3

    // Asignar valores de colores
    colors[0] = 1.0f; colors[1] = 0.0f; colors[2] = 0.0f; // Rojo
    colors[3] = 0.0f; colors[4] = 1.0f; colors[5] = 0.0f; // Verde
    colors[6] = 0.0f; colors[7] = 0.0f; colors[8] = 1.0f; // Azul

    // Crear un VAO (Vertex Array Object)
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Crear y cargar el VBO para los vértices
    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    // Crear y cargar el VBO para los colores
    glGenBuffers(1, &vboColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboColors);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), colors, GL_STATIC_DRAW);

    // Configurar las arrays de vértices y colores
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // Vértices
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // Colores

    glEnableVertexAttribArray(0); // Habilitar el atributo de vértices
    glEnableVertexAttribArray(1); // Habilitar el atributo de colores

    // Desvincular los buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Desvincular el VAO
    glBindVertexArray(0);

    // Limpiar la memoria
    delete[] vertices;
    delete[] colors;
}
void FiguraVAInstanced::Draw() {
    glBindVertexArray(vao);
    glDrawArraysInstanced(GL_TRIANGLES, 0, vertexCount, instanceCount);
    glBindVertexArray(0);
}