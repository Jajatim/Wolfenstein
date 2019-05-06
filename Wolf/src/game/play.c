#include "play.h"
#include "../utils/utils.h"

int p_init(game *g, play *p)
{
	(void)p;
	(void)g;

	p->moveSpeed = 0.002;
	p->rotSpeed = 0.002;
	p->pos = (vec2) {
		.x = 8.0,
		.y = 8.0
	};
	p->dir = (vec2) {
		.x = -1.0,
		.y = 0.0
	};
	p->plane = (vec2) {
		.x = 0.0,
		.y = 0.66
	};

	return 1;
}

int p_update(game *g, play *p)
{
	(void)p;
	(void)g;

	//Moving forward
	if (g->kbd.w)
	{
		p->pos.x += p->moveSpeed * p->dir.x * p->updateTimer;
		p->pos.y += p->moveSpeed * p->dir.y * p->updateTimer;
	}

	//Moving backwards
	if (g->kbd.s)
	{
		p->pos.x -= p->moveSpeed * p->dir.x * p->updateTimer;
		p->pos.y -= p->moveSpeed * p->dir.y * p->updateTimer;
	}

	//Rotating Right
	if (g->kbd.d)
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(-(p->rotSpeed * p->updateTimer)) - p->dir.y * sin(-(p->rotSpeed * p->updateTimer));
		p->dir.y = oldDirX * sin(-(p->rotSpeed * p->updateTimer)) + p->dir.y * cos(-(p->rotSpeed * p->updateTimer));
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(-(p->rotSpeed * p->updateTimer)) - p->plane.y * sin(-(p->rotSpeed * p->updateTimer));
		p->plane.y = oldPlaneX * sin(-(p->rotSpeed * p->updateTimer)) + p->plane.y * cos(-(p->rotSpeed * p->updateTimer));
	}

	//Rotating Left
	if (g->kbd.a)
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(p->rotSpeed * p->updateTimer) - p->dir.y * sin(p->rotSpeed * p->updateTimer);
		p->dir.y = oldDirX * sin(p->rotSpeed * p->updateTimer) + p->dir.y * cos(p->rotSpeed * p->updateTimer);
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(p->rotSpeed * p->updateTimer) - p->plane.y * sin(p->rotSpeed * p->updateTimer);
		p->plane.y = oldPlaneX * sin(p->rotSpeed * p->updateTimer) + p->plane.y * cos(p->rotSpeed * p->updateTimer);
	}

	//Strafing Left
	if (g->kbd.q)
	{
		p->pos.x -= p->dir.y * p->moveSpeed * p->updateTimer;
		p->pos.y -= -(p->dir.x) * p->moveSpeed * p->updateTimer;
	}

	//Strafing Right
	if (g->kbd.e)
	{
		p->pos.x += p->dir.y * p->moveSpeed * p->updateTimer;
		p->pos.y += -(p->dir.x) * p->moveSpeed * p->updateTimer;
	}

	return 1;
}

int p_render(game *g, play *p)
{
	(void)p;
	(void)g;

	//Clear renderer
	SDL_SetRenderDrawColor(g->ren,0,0,0,255);
	SDL_RenderClear(g->ren);

	//Calling the engine
	//TODO : Map is temporary until engine is redone
	p_engine(g, p);

	//Put Renderer to screen
	SDL_RenderPresent(g->ren);

	return 1;
}



int play_loop(game *g)
{
	printf("Entering Play loop\n");

	play p;

	p_init(g, &p);
	while (g->status == PLAY)
	{
		//debug
		printf("Play loop (esc to exit)\n");

		//Timer handling
		p.deltaTime = timer(p.deltaTime);
		p.updateTimer += p.deltaTime;
		p.renderTimer += p.deltaTime;

		//Filling the events
		g->status = events(g);

		//Updating every P_UPDATE_TIMER ms
		if (p.updateTimer >= P_UPDATE_TIMER) {
			p_update(g, &p);
			p.updateTimer = 0;
		}

		//Renders every P_RENDER_TIMER ms
		if (p.renderTimer >= P_RENDER_TIMER) {
			p_render(g, &p);
			p.renderTimer = 0;
		}

		//In game menu
		if (g->status == PLAY_MENU) {
			//TODO
			printf("ingame menu opening\n");
			SDL_Delay(500);
			printf("returning to menu loop\n");
			g->status = MAIN_MENU;
		}
		SDL_Delay(1);
	}
	//p_free(&p);
	return 1;
}
