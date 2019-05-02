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
			g->mse.x=e.motion.x;
			g->mse.y=e.motion.y;
		}


		/* MOUSE CLIC */

	}
	return (g->status);
}
