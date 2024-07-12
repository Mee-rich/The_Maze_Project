#include "../headers/header.h"

static SDL_Renderer *renderer;
static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
static SDL_Window *window;

SDL_DisplayMode display_mode;

/**
 * startWindow - This Initializes the window to display the maze
 * Return: True if successful, otherwise False
 */
bool startWindow(void)
{
	int fullScreenWidth, fullScreenHeight;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (false);
	}
	SDL_GetCurrentDisplayMode(0, &display_mode);
	fullScreenWidth = display_mode.w;
	fullScreenHeight = display_mode.h;
	window = SDL_CreateWindow(                                                         NULL,                                                                      SDL_WINDOWPOS_CENTERED,                                                    SDL_WINDOWPOS_CENTERED,
                fullScreenWidth,
                fullScreenHeight,
                SDL_WINDOW_BORDERLESS
        );
	if (!window)
	{
		fprintf(stderr, "Error creating SDL window.\n");
		return (false);
	}
	renderer = SDL_CreateRenderer(window, -1, 1);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	/* Total amount of memory to contain color buffer */
	colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);
	/* create SDL_Texture to display the color buffer */
	colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	return (true);
}


/**
 * destroy_Window - destroy window when the game is over
 */
void destroy_Window(void)
{
	free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/**
 * clear_ColorBuffer - clears the buffer for every frame
 * @color: color buffer
 */
void clear_ColorBuffer(color_t color)
{
	int i;

	for (i=0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		colorBuffer[i] = color;
}

/**
 * render_ColorBuffer - render the buffer for every frame
 */

void render_ColorBuffer(void)
{
	SDL_UpdateTexture(
			colorBufferTexture,
			NULL,
			colorBuffer,
			(int)(SCREEN_WIDTH * sizeof(color_t))
	);
	SDL_RenderCopy(renderer,
			colorBufferTexture,
			NULL,
			NULL);
	SDL_RenderPresent(renderer);
}


/**
 * draw_Pixel - Color assign to each pixel
 * @x: x coordinate
 * @y: y coordinate
 * @color: pixel color
 */
void draw_Pixel(int x, int y, color_t color)
{
	colorBuffer[(SCREEN_WIDTH *y) + x] = color;
}
