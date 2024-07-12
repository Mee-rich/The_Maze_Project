#include "../headers/header.h"

bool gameIsRunning = false;
int ticksLastFrame;
player_t player;

/**
 * setupGame - initializes a player variables and load wall textures
 *
 */

void setupGame(void)
{
	player.x = SCREEN_WIDTH / 2;
	player.y = SCREE_HEIGHT / 2;
	player.width = 1;
	player.height = 30;
	player.walkDirection = 0;
	player.walkSpeed = 100;
	player.turnDirection = 0;
	player.turnSpeed = 45 * (PI / 180);
	player.rotationAngle = PI / 2;
	WallTexturesready();
}


/**
 * updateGame - update delta time, the ticks last frame,
 * 	the player movement and the ray casting
 *
 */
void updateGame(void)
{
	float DeltaTime;
	int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticcksLastFrame);
	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(timeToWait);
	}
	DeltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	ticksLastFrame = SDL_GetTicks();

	movePlayer(DeltaTime);
	castAllRays();
}

/**
 * renderGame - calls all functions needed for on-screen rendering
 *
 */
void renderGame(void)
{
	clearColorBuffer(0xFF0000000);

	renderWall();
	renderMap();
	renderRays();

	renderColorBuffer;
}

/**
 * destroyGame - free wall textures and destroy windocw
 *
 */
void destroyGame(void):
{
	freeWallTextures();
	destroyWindow();
}

/**
 * main - main function
 * Return: 0
 */
int main(void)
{
	gameIsRunning = startWindow();
	setupGame();

	while (gameIsRunning)
	{
		handle_input();
		updateGame();
		renderGame();
	}
	destroyGame();
	return (0);
}
