#include "play.h"
#include "../utils/utils.h"

int play_loop(game *g)
{
	printf("Entering Play loop\n");

	play p;

	p_init(g, &p);
	while (g->status == PLAY)
	{
		//debug
		/*
		printf("Play loop (esc to exit)\n");
		printf("w = %d, s = %d, okup = %d, okback = %d\n", g->kbd.w, g->kbd.s,
				check_action(g, g->actions.moveForward), check_action(g, g->actions.moveBackward));
		printf("moveup = %d, moveback = %d\n", g->actions.moveForward, g->actions.moveBackward);
		*/

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
			//pm_init();
			while (g->status == PLAY_MENU) {
				//pm_update();
				//pm_render();

				//TODO
				printf("ingame menu opening\n");
				SDL_Delay(500);
				printf("returning to menu loop\n");
				g->status = MAIN_MENU;
				SDL_Delay(1);
			}
		}
	}
	//p_free(&p);
	return 1;
}
