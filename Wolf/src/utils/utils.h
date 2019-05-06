#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "../generic.h"

/*
Returns the time spent since the last call.
Relies on SDL_GetTick().
*/
uint32_t timer(uint32_t deltaTime);

/*
Events manager
*/
int events(game *g);

/*
Collision detectors.
*/
int collide_dot_rect(pos2d dot, SDL_Rect rect);


#endif //UTILS_H_INCLUDED
