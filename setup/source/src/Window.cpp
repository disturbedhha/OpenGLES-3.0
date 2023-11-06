#include "Window.hpp"

Window::Window(const int Width, const int Height){
    
    std::cout << "Parameter constructor called" << std::endl;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0){
        std::cout << "Error initialize SDL: \n" << SDL_GetError();
    }

    // Before we create our window, specify OpenGL version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

    win = SDL_CreateWindow("OpenGLES",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            Width,
                            Height,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if(!win){
        std::cout << "Error initialize window: \n" << SDL_GetError();
    }

    // OpenGLES setup context
    context = SDL_GL_CreateContext(win);

    gladLoadGLES2Loader(SDL_GL_GetProcAddress);
}

Window::~Window(){
    std::cout << "Destructor called" << std::endl;
    SDL_DestroyWindow(win);
    SDL_Quit();
}
