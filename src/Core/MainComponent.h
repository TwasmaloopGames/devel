#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

/*if pragma once support then use it in addition to include guard*/
#if defined(_pragma_once_support)
#    pragma once
#endif

#include "Display.h"
#include "RenderOpenGL.h"

class MainComponent
{
    public:
        /** Default constructor */
        MainComponent();
        /** Default destructor */
        virtual ~MainComponent();
        /** Copy constructor
         *  \param other Object to copy from
         */

        void Start();
        void Stop();

        void Run();

        MainComponent(const MainComponent& other) {}
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        void operator=(const MainComponent& other) {}

    protected:

    private:
        Display display;
        RenderOpenGL render;
};

#endif // MAINCOMPONENT_H
