#include "FiguraDisplayList.h"

FiguraDisplayList::FiguraDisplayList() {
    displayList = 0; // Inicializar en 0, se generar� al crear el Display List
}

FiguraDisplayList::~FiguraDisplayList() {
    if (displayList != 0) {
        glDeleteLists(displayList, 1); // Borrar el Display List cuando se destruya el objeto
    }
}
void FiguraDisplayList::InitBuffers() {
    // Aqu� creamos el Display List. Solo necesitamos hacerlo una vez al iniciar la figura.
    displayList = glGenLists(1); // Crear un Display List

    if (displayList != 0) {
        glNewList(displayList, GL_COMPILE); // Comienza la compilaci�n del Display List

        // Aqu� agregamos los comandos OpenGL que definen la figura.
        // Por ejemplo, podemos usar glBegin / glEnd o comandos espec�ficos de OpenGL
        glBegin(GL_TRIANGLES);  // Esto es solo un ejemplo, necesitas definir tu figura aqu�

        // Aqu�, por ejemplo, podr�amos agregar los v�rtices y colores de la figura:
        glVertex3f(0.0f, 1.0f, 0.0f); // V�rtice 1
        glVertex3f(-1.0f, -1.0f, 0.0f); // V�rtice 2
        glVertex3f(1.0f, -1.0f, 0.0f); // V�rtice 3

        glEnd();

        glEndList(); // Finaliza la compilaci�n del Display List
    }
}
void FiguraDisplayList::Draw() {
    if (displayList != 0) {
        glCallList(displayList); // Llamar al Display List para dibujar la figura
    }
}