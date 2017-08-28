#include "pacman.h"

void putGhostPink(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			len = 5000;
	int			len2 = 0;
	
	pacman->ghostPinkMove = (t_pos){0, 0};
	
	
	map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 0] = tmpPos;
	
	if (map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] == 0 ||
		map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] == 1 ||
		map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] == 3 ||
		map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y + 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostPinkMove = (t_pos) {0, 1};
				tmpPos = map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0];
			}
	}
	
	if (map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] == 0 ||
		map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] == 1 ||
		map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] == 3 ||
		map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y - 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostPinkMove = (t_pos) {0, -1};
				tmpPos = map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0];
			}
	}
	
	if (map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] == 0 ||
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] == 1 ||
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] == 3 ||
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x + 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x + 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostPinkMove = (t_pos) {1, 0};
				tmpPos = map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1];
			}
	}
	
	if (map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] == 0 ||
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] == 1 ||
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] == 3 ||
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x - 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x - 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostPinkMove = (t_pos) {-1, 0};
				tmpPos = map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1];
			}
	}
	if (tmpPos == 3)
	{
		putTextMessage(pacman, "You lose");
		SDL_RenderPresent(pacman->sdl.renderer);
		SDL_Delay(1500);
		exit(0);
	}
	
	pacman->ghostPink.x += pacman->ghostPinkMove.x;
	pacman->ghostPink.y += pacman->ghostPinkMove.y;
	
	map[pacman->ghostPink.y][pacman->ghostPink.x] = 7;
	pacman->ghostPinkRect = (SDL_Rect){pacman->ghostPink.x * 30, pacman->ghostPink.y * 30, 30, 30};
}
