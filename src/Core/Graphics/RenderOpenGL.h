#ifndef RENDEROPENGL_H
#define RENDEROPENGL_H

/*if pragma once support then use it in addition to include guard*/
#if defined(_pragma_once_support)
#    pragma once
#endif

#include <GL/glew.h>
#include <stdio.h>

class RenderOpenGL
{
public:
    /** Default constructor */
    RenderOpenGL();

    void init_resources();
    void free_resources();

    void ClearBuffers();
    void ClearColor(float red, float green, float blue, float alpha);

    /** Default destructor */
    virtual ~RenderOpenGL();

private:
    GLenum err;
};

#endif // RENDEROPENGL_H
