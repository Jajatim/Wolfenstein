#include "menu.h"

int m_events(game *g)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		/* WINDOW CLOSED */
		if (e.type == SDL_QUIT)
			return (EXIT);


		/* KEY PRESSED */
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				if (g->status == PLAY_MENU)
					return (PLAY);
				else if (g->status == PLAY)
					return (PLAY_MENU);
			}
		}


		/* KEY RELEASED */
		else if (e.type == SDL_KEYUP)
		{

		}


		/* MOUSE MOTION */
		else if (e.type == SDL_MOUSEMOTION) {
			g->mse.pos.x=e.motion.x;
			g->mse.pos.y=e.motion.y;
		}


		/* MOUSE CLIC */
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			switch(e.button.button) {
				case SDL_BUTTON_LEFT:
					g->mse.leftBtn = 1;
					break;
				case SDL_BUTTON_RIGHT:
					g->mse.rightBtn = 1;
					break;
			}
		}

		/* MOUSE UNCLIC */
		else if (e.type == SDL_MOUSEBUTTONUP) {
			switch(e.button.button) {
				case SDL_BUTTON_LEFT:
					g->mse.leftBtn = 0;
					break;
				case SDL_BUTTON_RIGHT:
					g->mse.rightBtn = 0;
					break;
			}
		}
	}
	return (g->status);
}
