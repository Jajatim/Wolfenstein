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

			switch(e.key.keysym.sym) {
				case a:
					g->kbd.w = 1;
					g->kbd.alpha[22] = 1; //22 is 'w' - 'a'
					break;
				case SDLK_s:
					g->kbd.s = 1;
					g->kbd.alpha[18] = 1; //18 is 's' - 'a'
					break;
				case SDLK_a:
					g->kbd.a = 1;
					g->kbd.alpha[0] = 1; //0 is 'a' - 'a'
					break;
				case SDLK_d:
					g->kbd.d = 1;
					g->kbd.alpha[3] = 1; //3 is 'd' - 'a'
					break;
				case SDLK_q:
					g->kbd.q = 1;
					g->kbd.alpha[16] = 1; //16 is 'q' - 'a'
					break;
				case SDLK_e:
					g->kbd.e = 1;
					g->kbd.alpha[4] = 1; //4 is 'e' - 'a'
					break;
				case SDLK_z:
					g->kbd.z = 1;
					g->kbd.alpha[25] = 1; //25 is 'z' - 'a'
					break;
			}
		}


		/* KEY RELEASED */
		else if (e.type == SDL_KEYUP)
		{
			switch(e.key.keysym.sym) {
				case SDLK_w:
					g->kbd.w = 0;
					g->kbd.alpha[22] = 0; //22 is 'w' - 'a'
					break;
				case SDLK_s:
					g->kbd.s = 0;
					g->kbd.alpha[18] = 0; //18 is 's' - 'a'
					break;
				case SDLK_a:
					g->kbd.a = 0;
					g->kbd.alpha[0] = 0; //0 is 'a' - 'a'
					break;
				case SDLK_d:
					g->kbd.d = 0;
					g->kbd.alpha[3] = 0; //3 is 'd' - 'a'
					break;
				case SDLK_q:
					g->kbd.q = 0;
					g->kbd.alpha[16] = 0; //16 is 'q' - 'a'
					break;
				case SDLK_e:
					g->kbd.e = 0;
					g->kbd.alpha[4] = 0; //4 is 'e' - 'a'
					break;
				case SDLK_z:
					g->kbd.z = 0;
					g->kbd.alpha[25] = 0; //25 is 'z' - 'a'
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
