#include "menu.h"

int m_render(game *g, menu *m)
{
	(void)g;
	(void)m;

	SDL_SetRenderDrawColor(g->ren,0,0,0,255);
	SDL_RenderClear(g->ren);

	SDL_RenderPresent(g->ren);
	return 1;
}
