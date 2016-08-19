#include "RenderOpenGL.h"

RenderOpenGL::RenderOpenGL()
{
    err = NULL;
}

RenderOpenGL::~RenderOpenGL()
{
    //dtor
}

void RenderOpenGL::init_resources()
{
    printf("init_resources(RenderOpenGL)\n");
    glewExperimental = true;
    printf("    - glewExperimental = %d\n", glewExperimental);
    err = glewInit();
    if(err!=GLEW_OK)
    {

    }

    /* Enable Z depth testing so objects closest to the viewpoint are in front of objects further away */
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    ClearBuffers();
    ClearColor(0,0,0,1);
}

void RenderOpenGL::free_resources()
{
    printf("free_resources(RenderOpenGL)\n");
    err = NULL;
    printf("    - glewInit(%d)\n", err);
}

void RenderOpenGL::ClearBuffers()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void RenderOpenGL::ClearColor(float red, float green, float blue, float alpha)
{
    glClearColor(red,green,blue,alpha);
}
