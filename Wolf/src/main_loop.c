#include "menu/menu.h"
#include "play/play.h"
#include "utils/utils.h"

//TODO : move to appropriate .c file if needed
void change_state(game *g, menu *m, play *p) {
	switch(g->status) {
		case PLAY:
			//Exits menu state
			m_free(m);

			//Inits play state
			//g->init = &p_init;
			p_init(g, m, p);

			//Init timers & functions pointers
			g->update = &p_update;
			g->updateDelta = 0;
			g->updateTimer = P_UPDATE_TIMER;
			g->render = &p_render;
			g->renderDelta = 0;
			g->renderTimer = P_RENDER_TIMER;
			break;
		
		case MAIN_MENU:
			//Exits play state
			//TODO

			//Inits menu state
			//g->init = &p_init;
			m_init(g, m, p);

			//Init timers & functions pointers
			g->update = &m_update;
			g->updateDelta = 0;
			g->updateTimer = M_UPDATE_TIMER;
			g->render = &m_render;
			g->renderDelta = 0;
			g->renderTimer = M_RENDER_TIMER;
			break;
	}
}

int game_loop(game *g, menu *m, play *p)
{
	//TODO : as init is not in the loop, having this function pointer is useless...
	//g->init(g, m, p);

	//Init timer (need to init the static var)
	timer();

	//Game loop, runs unti exit
	while (g->status != EXIT)
	{
		//State change detector
		g->status_last = g->status;

		//Timer handling
		uint32_t deltaTime = timer();
		g->updateDelta += deltaTime;
		g->renderDelta += deltaTime;

		//Handling the events
		events(g);
        
		//Updating when needed
		if (g->updateDelta >= g->updateTimer) {
			g->update(g, m, p);
			g->updateDelta = 0;
		}

		//Rendering when needed
		if (g->renderDelta >= g->renderTimer) {
			g->render(g, m, p);
			g->renderDelta = 0;
		}
		
		//Game state changed, updating what's needed
		if (g->status_last != g->status)
			change_state(g, m, p);

		SDL_Delay(1);
	}
	return 1;
}