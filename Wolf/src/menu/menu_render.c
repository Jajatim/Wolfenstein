#include "menu.h"

int m_render(game *g, menu *m)
{
	(void)g;
	(void)m;

	//Clear renderer
	SDL_SetRenderDrawColor(g->ren,0,0,0,255);
	SDL_RenderClear(g->ren);

	//TODO : How to handle mousover on buttons ?

	//TODO : Finalize main menu so we can finalize btn pos or we can do it the changeable way... (with stuff like : btnNb, etc...)
	//Buttons general infos
	const int btnNb = 3;
	const int topPadding = 100;
	const int midPadding = 25;
	const int botPadding = 100;

	//Readying buttons printing on screen
	int curY = topPadding;
	SDL_Rect dst;
	dst.w = g->screenW / 2;
	dst.h = (g->screenH - (topPadding + midPadding + botPadding) - (btnNb - 1) * midPadding) / btnNb ;
	dst.x = g->screenW / 4;

	//Printing btn play
	dst.y = curY;
	m->btn_play_dst = dst;
	SDL_RenderCopy(g->ren, m->menuAssets, &(m->btn_play_src), &dst);
	curY += midPadding + dst.h;

	//Printing btn options
	dst.y = curY;
	m->btn_opt_dst = dst;
	SDL_RenderCopy(g->ren, m->menuAssets, &(m->btn_opt_src), &dst);
	curY += midPadding + dst.h;

	//Printing btn exit
	dst.y = curY;
	m->btn_exit_dst = dst;
	SDL_RenderCopy(g->ren, m->menuAssets, &(m->btn_exit_src), &dst);
	curY += midPadding + dst.h;

	//Put Renderer to screen
	SDL_RenderPresent(g->ren);
	return 1;
}
