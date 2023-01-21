#include "SDL.h"
#include "SDL_opengl.h"
#include <cassert>

int main(int argc, char* argv[]) {
  assert(SDL_Init(SDL_INIT_VIDEO));

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  SDL_Window* window = SDL_CreateWindow("Meson-SDL-OpenGL", 0, 0, 800, 600, SDL_WINDOW_OPENGL);
  assert(window != nullptr); 

  SDL_GLContext context = SDL_GL_CreateContext(window);
  glViewport(0, 0, 800, 600);
  glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

  bool isRunning = true;
  while (isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            break;
        default:
            break;
        }
    }
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  
  SDL_Quit();

  return 0;
}