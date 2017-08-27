int map[22][19]={
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{2,4,2,2,1,2,2,2,1,2,1,2,2,2,1,2,2,4,2},
	{2,1,2,2,1,2,2,2,1,2,1,2,2,2,1,2,2,1,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{2,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,2},
	{2,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,2},
	{2,2,2,2,1,2,2,2,0,2,0,2,2,2,1,2,2,2,2},
	{0,0,0,2,1,2,0,0,0,0,0,0,0,2,1,2,0,0,0},
	{2,2,2,2,1,2,0,2,2,0,2,2,0,2,1,2,2,2,2},
	{0,0,0,0,1,0,0,2,0,0,0,2,0,0,1,0,0,0,0},
	{2,2,2,2,1,2,0,2,2,2,2,2,0,2,1,2,2,2,2},
	{0,0,0,2,1,2,0,0,0,0,0,0,0,2,1,2,0,0,0},
	{2,2,2,2,1,2,0,2,2,2,2,2,0,2,1,2,2,2,2},
	{2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{2,1,2,2,1,2,2,2,1,2,1,2,2,2,1,2,2,1,2},
	{2,4,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,4,2},
	{2,2,1,2,1,2,1,2,2,2,2,2,1,2,1,2,1,2,2},
	{2,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,2},
	{2,1,2,2,2,2,2,2,1,2,1,2,2,2,2,2,2,1,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

#include "pacman.h"

static void	initDefault(t_pacman *pacman, int *stop)
{
	*stop = 0;
	pacman->pause = 0;
	pacman->score = 0;
	pacman->eat = 0;
	pacman->pacMove = (t_pos){0, 0};
	pacman->ghostRedMove = (t_pos){0, 0};
	pacman->ghostPinkMove = (t_pos){0, 0};
	pacman->ghostBlueMove = (t_pos){0, 0};
	pacman->ghostYellowMove = (t_pos){0, 0};
	
	pacman->pac = (t_pos){17, 20};
	
	pacman->ghostRed = (t_pos){9, 10};
	pacman->ghostYellow = (t_pos){10, 10};
	pacman->ghostBlue = (t_pos){1, 4};
	pacman->ghostPink = (t_pos){16, 4};
	
	
	pacman->pacImageUp = IMG_Load("image/pacmanUp.png");
	pacman->pacImageDown = IMG_Load("image/pacmanDown.png");
	pacman->pacImageLeft = IMG_Load("image/pacmanLeft.png");
	pacman->pacImageRight = IMG_Load("image/pacmanRight.png");
	pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageLeft);
	
	pacman->ghostRedImage = IMG_Load("image/red.png");
	pacman->ghostRedTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->ghostRedImage);
	
	pacman->ghostBlueImage = IMG_Load("image/Blue.png");
	pacman->ghostBlueTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->ghostBlueImage);
	
	pacman->ghostYellowImage = IMG_Load("image/yellow.png");
	pacman->ghostYellowTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->ghostYellowImage);
	
	pacman->ghostPinkImage = IMG_Load("image/pink.png");
	pacman->ghostPinkTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->ghostPinkImage);
	
	pacman->ghostEatImage = IMG_Load("image/ghost.png");
	pacman->ghostEatTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->ghostEatImage);
}

int main(void)
{
	int			stop;
	t_pacman		*pacman;
	static int	ghost = 0;
	
	pacman = (t_pacman *)malloc(sizeof(t_pacman));
	
	sdlInit(pacman);
	initDefault(pacman, &stop);
	putPacman(pacman);
	drawMap(pacman);
	
	while (!stop)
	{
		while (SDL_PollEvent(&(pacman->sdl.e)))
		{
			if (pacman->sdl.e.type == SDL_QUIT ||
				pacman->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
			else if (pacman->sdl.e.type == SDL_KEYUP)
			{
				if (pacman->sdl.e.key.keysym.sym == SDLK_SPACE)
					pacman->pause = (pacman->pause == 1) ? 0 : 1;
				else  if (pacman->sdl.e.key.keysym.sym == SDLK_SPACE)
				{
					map[4][4] = 3;
					drawMap(pacman);
				}
				else if (pacman->sdl.e.key.keysym.sym == SDLK_UP)
					pacman->pacMove = (t_pos){0, -1};
				else if (pacman->sdl.e.key.keysym.sym == SDLK_DOWN)
					pacman->pacMove = (t_pos){0, 1};
				else if (pacman->sdl.e.key.keysym.sym == SDLK_RIGHT)
					pacman->pacMove = (t_pos){1, 0};
				else if (pacman->sdl.e.key.keysym.sym == SDLK_LEFT)
					pacman->pacMove = (t_pos){-1, 0};
			}
		}
		if (pacman->pause == 0)
		{
			sdlRenderClear(pacman);
			putPacman(pacman);
			drawMap(pacman);
			if (ghost++ % 2)
			{
				putGhostRed(pacman);
				putGhostYellow(pacman);
			}
			else
			{
				putGhostBlue(pacman);
				putGhostPink(pacman);
			}
			if (pacman->eat != 0)
				pacman->eat--;
			
			
			SDL_RenderPresent(pacman->sdl.renderer);
			SDL_Delay(250);
		}

		
	}
	
	

	

//	sdlDestroy(pacman);
	return 0;
}
