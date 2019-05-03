#include "menu.h"

static int m_free(menu *m)
{
	m->test = 0; //del
	return 1;
}

int menu_loop(game *g)
{
	menu m;

	//m_init(g, &m);
	while (g->status != EXIT)
	{
		printf("Menu Loop\nMouseX : %d, MouseY : %d\n", g->mse.x, g->mse.y);
		g->status = m_events(g);
		//m_update(&m, g);
		m_render(g, &m);
		
		if (g->status == PLAY)
		{
			//m_free(&m);
			//play(g);
			//m_init(g, &m);
		}
		SDL_Delay(1);
	}
	m_free(&m);

	return 1;
}
