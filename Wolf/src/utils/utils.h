#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "../generic.h"

/*
Returns the time spent since the last call.
Relies on SDL_GetTick().
*/
Uint32 timer(Uint32 deltaTime);

#endif //UTILS_H_INCLUDED