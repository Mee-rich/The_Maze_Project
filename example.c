//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main( int argc, char* args[] )
{
	//The window we'll be rendering to 
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screeSurface = NULL;

	//Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDPOW_SHOWN );
		if( window == NULL)
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
