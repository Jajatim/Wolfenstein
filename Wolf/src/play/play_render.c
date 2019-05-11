#include "play.h"

int p_render(game *g, play *p)
{
	(void)p;
	(void)g;

	//Clear renderer
	SDL_SetRenderDrawColor(g->ren,0,0,0,255);
	SDL_RenderClear(g->ren);

	//Calling the engine
	p_engine(g, p);

	//Put Renderer to screen
	SDL_RenderPresent(g->ren);

	return 1;
}
