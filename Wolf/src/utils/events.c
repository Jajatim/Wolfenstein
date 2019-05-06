#include "utils.h"

int events(game *g)
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

			if (e.type == SDL_KEYDOWN) {
				switch(e.key.keysym.sym) {
					case SDLK_w:
						g->kbd.w = 1;
						break;
					case SDLK_s:
						g->kbd.s = 1;
						break;
					case SDLK_a:
						g->kbd.a = 1;
						break;
					case SDLK_d:
						g->kbd.d = 1;
						break;
					case SDLK_q:
						g->kbd.q = 1;
						break;
					case SDLK_e:
						g->kbd.e = 1;
						break;
				}
			}
		}


		/* KEY RELEASED */
		else if (e.type == SDL_KEYUP)
		{
				switch(e.key.keysym.sym) {
					case SDLK_w:
						g->kbd.w = 0;
						break;
					case SDLK_s:
						g->kbd.s = 0;
						break;
					case SDLK_a:
						g->kbd.a = 0;
						break;
					case SDLK_d:
						g->kbd.d = 0;
						break;
					case SDLK_q:
						g->kbd.q = 0;
						break;
					case SDLK_e:
						g->kbd.e = 0;
						break;
				}
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
