#include "Window.hpp"

int main(int argc, char *argv[]){
	
	const int SCREEN_WIDTH = 64*20;
	const int SCREEN_HEIGHT = 64*10;

	Window win(SCREEN_WIDTH, SCREEN_HEIGHT);

	bool gQuit = false;
	while(!gQuit){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				gQuit = true;
			}
		}
		// draw
		SDL_GL_SwapWindow(win.win);
	}
	return 0;
}