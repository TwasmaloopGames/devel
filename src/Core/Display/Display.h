//block gaurds <3
#ifndef DISPLAY_H
#define DISPLAY_H

/*if pragma once support then use it in addition to include guard*/
#if defined(_pragma_once_support)
#    pragma once
#endif

//Include some sick libraries d00de
#include <GL/glew.h>
#include <stdio.h>
#include <SDL2/SDL.h>

//Rename some datatypes to be readable by user programming dis crap...
typedef SDL_Window Window;
typedef SDL_GLContext Context;

class Display
{
public:
    //ctor to be used for a base function for error checking...
    Display();

    //Initialize variables and libraries to be used in conjunction with this class.
    void init_resources();
    //Free all mess made by this class...
    void free_resources();

    //Creating the frame and glcontext in which OGL can be rendered to...
    void CreateWindow(int width, int height, char* title);
    //This update method is strictly for the use in this Display only...
    //it should only update anything that is directly related to this class...
    void Update();
    //This input method if temp; however, at this current point it makes the window
    //able to be closed and not freeze on startup...
    void Input();
    //Resized glViewport based on current window size...
    void ResizeWindow();
    //Swaping the buffers to be able to update multiple frames at runtime to display images...
    void SwapBuffers();
    //Cleaning up the mess this class makes...
    void CleanUp();

    //Check to see if the window has not been requested to be closed...
    bool isRunning();

    //dtor, used to cleanup class once has been finished being used...
    virtual ~Display();
private:
    Window* win;
    Context con;

    int WIDTH, HEIGHT;

    int flags;
    bool m_running;
};

#endif // DISPLAY_H
