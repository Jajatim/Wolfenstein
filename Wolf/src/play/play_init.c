#include "play.h"

int p_init(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;

	//TODO : add map loading here
	
	//Player infos
	p->moveSpeed = 0.002;
	p->rotSpeed = 0.002;
	p->pos = (vec2) {
		.x = 8.0,
		.y = 8.0
	};
	p->dir = (vec2) {
		.x = -1.0,
		.y = 0.0
	};
	p->plane = (vec2) {
		.x = 0.0,
		.y = 0.66
	};

	return 1;
}
