#include "Figura.h"

Figura::Figura()
{
	color.SetColor(1, 1, 1);
}

void Figura::LoadTexture(GLuint newTexture) {
    texture = newTexture;
}

void Figura::ApplyTexture() {
    if (texture != 0) {
        glBindTexture(GL_TEXTURE_2D, texture);
    }
}