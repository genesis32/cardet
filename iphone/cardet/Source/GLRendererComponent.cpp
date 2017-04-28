#include "Common.h"
#include "ImageCache.h"
#include "GLRendererComponent.h"
#include "GameTable.h"
#include "Sprite.h"

namespace cardet
{

  GLRendererComponent::GLRendererComponent()
  {
    
  }
  
  GLRendererComponent::~GLRendererComponent()
  {
    
  }

  void GLRendererComponent::BeginScene()
  {
    glViewport(0, 0, 320, 460);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

  }

  void GLRendererComponent::EndScene()
  {

  }

  GLuint GLRendererComponent::LoadTexture(ImageId imageId)
  {
    ImageIdToGLTexMapIterator itr = _imageIdToGLMap.find(imageId);
    GLuint textureId;
    if(itr == _imageIdToGLMap.end())
      {
        imgdata_t const *imgdata = gImageCache.Get(imageId);

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgdata->width, imgdata->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgdata->pixels);

        _imageIdToGLMap[imageId] = textureId;
      }
    else
      {
        textureId = itr->second;
        glBindTexture(GL_TEXTURE_2D, textureId);
      }
    return textureId;
  }

  void GLRendererComponent::Shutdown()
  {
    // clear all data that takes up mucho memory!
  }

  void GLRendererComponent::Render(GameTable *table, Sprite *sprite)
  {
    LoadTexture(sprite->get_imageId());

    static const GLfloat squareVertices[] = {
      TransformXToWorld(0.0f), TransformYToWorld(0.0f), -0.5,
      TransformXToWorld(sprite->get_width()), TransformYToWorld(0.0f), -0.5,
      TransformXToWorld(0.0f), TransformYToWorld(sprite->get_height()), -0.5,
      TransformXToWorld(sprite->get_width()), TransformYToWorld(sprite->get_height()), -0.5
    };

    static const GLubyte squareColors[] = {
        0, 0,   0, 255,
        0,   255, 255, 255,
        0,     0,   0,   0,
        255,   0, 255, 255,
    };

    static const GLfloat texCoords[] = {
      0.0, 1.0,
      1.0, 1.0,
      0.0, 0.0,
      1.0, 0.0
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  }

  void GLRendererComponent::Render(GameCard *card, Sprite *sprite)
  {
    LoadTexture(sprite->get_imageId());

    static const GLfloat squareVertices[] = {
      TransformXToWorld(0.0f), TransformYToWorld(0.0f), -0.25,
      TransformXToWorld(sprite->get_width()), TransformYToWorld(0.0f), -0.25,
      TransformXToWorld(0.0f), TransformYToWorld(sprite->get_height()), -0.25,
      TransformXToWorld(sprite->get_width()), TransformYToWorld(sprite->get_height()), -0.25
    };

    static const GLubyte squareColors[] = {
        0, 0,   0, 255,
        0,   255, 255, 255,
        0,     0,   0,   0,
        255,   0, 255, 255,
    };

    static const GLfloat texCoords[] = {
      0.0, 1.0,
      1.0, 1.0,
      0.0, 0.0,
      1.0, 0.0
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, squareVertices);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);

    float xdist = TranslateXToWorld(0.0f, sprite->get_x()); 
    float ydist = TranslateYToWorld(0.0f, sprite->get_y());

    glPushMatrix();
    glTranslatef(xdist, ydist, 0.0f);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  }

}


