#include "menu.h"
#include "../play/play.h"
#include "../utils/utils.h"


static int m_free(menu *m)
{
	SDL_DestroyTexture(m->menuAssets);
	return 1;
}


int menu_loop(game *g)
{
	menu m;

	m_init(g, &m);
	while (g->status != EXIT)
	{
		//debug
		/*
		printf("Menu Loop\nMouseX : %d, MouseY : %d\n", g->mse.pos.x, g->mse.pos.y);
		printf("Timers : delta %d | update %d | render %d\n", m.deltaTime, m.updateTimer, m.renderTimer);
		*/

		//Timer handling
		m.deltaTime = timer(m.deltaTime);
		m.updateTimer += m.deltaTime;
		m.renderTimer += m.deltaTime;

		//Filling the events
		g->status = events(g);

		//Updating every M_UPDATE_TIMER ms
		if (m.updateTimer >= M_UPDATE_TIMER) {
			g->status = m_update(g, &m);
			m.updateTimer = 0;
		}

		//Renders every M_RENDER_TIMER ms
		if (m.renderTimer >= M_RENDER_TIMER) {
			m_render(g, &m);
			m.renderTimer = 0;
		}

		//Launching the game, exiting the menu
		if (g->status == PLAY)
		{
			//m_free(&m); //To delete if menu is light, to do otherwise
			play_loop(g);
			m.m_status = MENU_TITLE;
			//m_init(g, &m); //To do if m_free() is called before the play loop
		}
		SDL_Delay(1);
	}
	m_free(&m);

	return 1;
}
