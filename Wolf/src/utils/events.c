#include "utils.h"

void events(game *g)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		/* WINDOW CLOSED */
		if (e.type == SDL_QUIT)
			g->status = EXIT;


		/* KEY PRESSED */
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			//TODO temporary goes back to menu when escape is pressed
				if (g->status == PLAY)
					g->status = MAIN_MENU;
			//TODO when adding play menu
			/*
			{
				if (g->status == PLAY_MENU)
					g->status = PLAY;
				else if (g->status == PLAY)
					g->status = PLAY_MENU;
			}
			*/

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
				case SDLK_z:
					g->kbd.z = 1;
					break;
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
				case SDLK_z:
					g->kbd.z = 0;
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
}
