#include "Display.h"

Display::Display()
{
    win = NULL;
    con = NULL;

    flags = SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE;
}

Display::~Display()
{
    CleanUp();
}

void Display::init_resources()
{
    printf("init_resources(Display)\n");
    SDL_Init(SDL_INIT_EVERYTHING);
    printf("    - SDL_Init(%d)\n", SDL_INIT_EVERYTHING);
}

void Display::free_resources()
{
    printf("free_resources(Display)\n");
    SDL_Init(NULL);
    printf("    - SDL_Init(%d)\n", SDL_Init(NULL));
}

void Display::CreateWindow(int width, int height, char* title)
{
    this->WIDTH = width;
    this->HEIGHT = height;

    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if(win==NULL)
    {

    }

    printf("Window creation succesful...\n");

    con = SDL_GL_CreateContext(win);
    if(con==NULL)
    {

    }

    printf("GLContext creation succesful...\n");

    m_running = true;
    printf("Display running(%d)\n", m_running);
}

void Display::Update()
{
    Input();
    ResizeWindow();
}

void Display::Input()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT)
        {
            m_running = false;
        }
    }
}

void Display::CleanUp()
{
    SDL_GL_DeleteContext(con);
    SDL_DestroyWindow(win);
}

bool Display::isRunning()
{
    return m_running;
}

void Display::SwapBuffers()
{
    SDL_GL_SwapWindow(win);
}

void Display::ResizeWindow()
{
    SDL_GetWindowSize(win, &WIDTH, &HEIGHT);
    glViewport(0,0,WIDTH,HEIGHT);
}
