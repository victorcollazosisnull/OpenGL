#include "Example5.h"
#include "Color.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include <stdio.h>
#include "BMPTextureLoader.h"
Example5::Example5()
    : shape(nullptr), _TextureLoader(nullptr), texture(0), pos(0.0f, 0.0f, 0.0f), rotationAngle(0.0f), scaleX(1.0f), scaleY(1.0f), scaleZ(1.0f)
{
}
void Example5::init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);

    shape = new Triangulo(); //INSERTAR FIGURAS

    textureManager.LoadTextureBMP(0, "./textures/opengl.bmp");
    textureManager.LoadTextureBMP(1, "./textures/TexturesCom_Ground_ForestMoss02_1x1_512_albedo.bmp");
    textureManager.LoadTextureBMP(2, "./textures/wallBMP.bmp");
    shape->LoadTexture(textureManager.GetTexture(textureIndex));
    //_TextureLoader = new BMPTextureLoader();
    //texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./textures/TexturesCom_Ground_ForestMoss02_1x1_512_albedo.bmp");
    //shape->LoadTexture(texture);
}

void Example5::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    DrawShape();

    glutSwapBuffers();
}

void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
    float movementSpeed = 0.1f;  
    float rotationSpeed = 5.0f; 
    float scaleSpeed = 0.1f;   

    switch (key) {
    case 'w':  
        pos.y += movementSpeed;
        break;
    case 's': 
        pos.y -= movementSpeed;
        break;
    case 'a':  
        pos.x -= movementSpeed;
        break;
    case 'd':  
        pos.x += movementSpeed;
        break;
    case 'q':  
        pos.z += movementSpeed;
        break;
    case 'e':  
        pos.z -= movementSpeed;
        break;

    case 'r':  
        rotationAngle += rotationSpeed;
        break;
    case 'f':  
        rotationAngle -= rotationSpeed;
        break;

    case 'z':  
        scaleX -= scaleSpeed;
        break;
    case 'x':  
        scaleX += scaleSpeed;
        break;
    case 'c':  
        scaleY -= scaleSpeed;
        break;
    case 'v':  
        scaleY += scaleSpeed;
        break;
    case 'b':  
        scaleZ -= scaleSpeed;
        break;
    case 'n': 
        scaleZ += scaleSpeed;
        break;
    case '1':
        textureIndex = 0;  
        shape->LoadTexture(textureManager.GetTexture(textureIndex));
        break;
    case '2':
        textureIndex = 1; 
        shape->LoadTexture(textureManager.GetTexture(textureIndex));
        break;
    case '3':
        textureIndex = 2;  
        shape->LoadTexture(textureManager.GetTexture(textureIndex));
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

void Example5::Idle()
{
}

void Example5::DrawShape()
{
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glPushMatrix();
    textureManager.BindTexture(textureIndex);

    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
    glScalef(scaleX, scaleY, scaleZ);

    shape->Draw(); 

    glPopMatrix();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D);
}

