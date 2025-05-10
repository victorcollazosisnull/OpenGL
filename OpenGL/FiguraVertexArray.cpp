#include "FiguraVertexArray.h"

FiguraVertexArray::FiguraVertexArray()
    : vertices(nullptr), colors(nullptr), vertexCount(0) {
}

FiguraVertexArray::~FiguraVertexArray() {
    if (vertices) delete[] vertices;
    if (colors) delete[] colors;
}
void FiguraVertexArray::InitBuffers() {
    // Aquí debes definir los datos de los vértices y colores
    // Como ejemplo, si tu figura tiene 3 vértices, lo puedes hacer así:
    vertexCount = 3;

    // Reservamos memoria para los arrays de vértices y colores
    vertices = new GLfloat[vertexCount * 3]; // 3 valores por vértice (x, y, z)
    colors = new GLfloat[vertexCount * 3]; // 3 valores por color (r, g, b)

    // Asignamos los valores de los vértices (como ejemplo)
    vertices[0] = 0.0f; vertices[1] = 1.0f; vertices[2] = 0.0f; // Vértice 1
    vertices[3] = -1.0f; vertices[4] = -1.0f; vertices[5] = 0.0f; // Vértice 2
    vertices[6] = 1.0f; vertices[7] = -1.0f; vertices[8] = 0.0f; // Vértice 3

    // Asignamos los valores de color (como ejemplo)
    colors[0] = 1.0f; colors[1] = 0.0f; colors[2] = 0.0f; // Color para Vértice 1 (Rojo)
    colors[3] = 0.0f; colors[4] = 1.0f; colors[5] = 0.0f; // Color para Vértice 2 (Verde)
    colors[6] = 0.0f; colors[7] = 0.0f; colors[8] = 1.0f; // Color para Vértice 3 (Azul)

    // Ahora inicializamos los buffers de OpenGL
    GLuint vboVertices, vboColors;

    // Crea el buffer para los vértices
    glGenBuffers(1, &vboVertices);
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    // Crea el buffer para los colores
    glGenBuffers(1, &vboColors);
    glBindBuffer(GL_ARRAY_BUFFER, vboColors);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(GLfloat), colors, GL_STATIC_DRAW);

    // Después de cargar los buffers, puedes desconectar los buffers de OpenGL
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void FiguraVertexArray::Draw() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}