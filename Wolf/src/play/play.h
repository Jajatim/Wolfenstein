#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include "../generic.h"

typedef struct vec2 {
	double x;
	double y;
} vec2;

typedef struct play {
	/* Timers */
	uint32_t deltaTime;
	uint32_t updateTimer;
	uint32_t renderTimer;

	/* Player infos */
	double moveSpeed;
	double rotSpeed;
	vec2 pos;
	vec2 dir;
	vec2 plane;
} play;


int play_loop(game *g);
int p_init(game *g, play *p);
int p_update(game *g, play *p);
int p_render(game *g, play *p);
int p_engine(game *g, play *p);

#endif //PLAY_H_INCLUDED
