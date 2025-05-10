#include "FiguraDisplayList.h"

FiguraDisplayList::FiguraDisplayList() {
    displayList = 0; // Inicializar en 0, se generará al crear el Display List
}

FiguraDisplayList::~FiguraDisplayList() {
    if (displayList != 0) {
        glDeleteLists(displayList, 1); // Borrar el Display List cuando se destruya el objeto
    }
}
void FiguraDisplayList::InitBuffers() {
    // Aquí creamos el Display List. Solo necesitamos hacerlo una vez al iniciar la figura.
    displayList = glGenLists(1); // Crear un Display List

    if (displayList != 0) {
        glNewList(displayList, GL_COMPILE); // Comienza la compilación del Display List

        // Aquí agregamos los comandos OpenGL que definen la figura.
        // Por ejemplo, podemos usar glBegin / glEnd o comandos específicos de OpenGL
        glBegin(GL_TRIANGLES);  // Esto es solo un ejemplo, necesitas definir tu figura aquí

        // Aquí, por ejemplo, podríamos agregar los vértices y colores de la figura:
        glVertex3f(0.0f, 1.0f, 0.0f); // Vértice 1
        glVertex3f(-1.0f, -1.0f, 0.0f); // Vértice 2
        glVertex3f(1.0f, -1.0f, 0.0f); // Vértice 3

        glEnd();

        glEndList(); // Finaliza la compilación del Display List
    }
}
void FiguraDisplayList::Draw() {
    if (displayList != 0) {
        glCallList(displayList); // Llamar al Display List para dibujar la figura
    }
}