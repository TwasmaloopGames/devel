#include "MainComponent.h"

MainComponent::MainComponent()
{
    /** Initialize all resources needed before
        program starts                      */
    display.init_resources();
    render.init_resources();

    /** After initialized use functions that
        furthur complement initialized
        resources                           */
    display.CreateWindow(800,600,"");
}

MainComponent::~MainComponent()
{
    /** Remove resources in reverse order
        in which they were created.         */
    render.free_resources();
    display.free_resources();
}

void MainComponent::Start()
{
    /** Run the main loop of the
        core engine.                        */
    Run();
}

    /** Function called when stopping the
        threading process of the engine.    */
void MainComponent::Stop()
{

}

/// All loop releated stuff for rending to be done here
void MainComponent::Run()
{
    while(display.isRunning())
    {
        render.ClearBuffers();
        render.ClearColor(0,0,0,1);
        display.Update();

        /** RENDER HERE */
        //render.DrawTest();


        display.SwapBuffers();
    }
}
