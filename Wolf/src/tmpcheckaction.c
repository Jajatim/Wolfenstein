#include "generic.h"

//Takes an action, and returns 1 if that action is currently active
// e.g. if move forward is set to 'w' and the 'w' key is pressed, returns 1, else returns 0


int check_action(game *g, int action)
{
	switch (action) {
		case SDLK_q:
			if (g->kbd.q) return 1;
			break;
		case SDLK_w:
			if (g->kbd.w) return 1;
			break;
		case SDLK_e:
			if (g->kbd.e) return 1;
			break;
		case SDLK_a:
			if (g->kbd.a) return 1;
			break;
		case SDLK_s:
			if (g->kbd.s) return 1;
			break;
		case SDLK_d:
			if (g->kbd.d) return 1;
			break;
	}
	return 0;
}
