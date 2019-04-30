#include "utils.h"

Uint32 timer(Uint32 deltaTime) {
    Uint32 currentTick = SDL_GetTicks();
    static Uint32 lastTick = 0;

    //First time here will return 0 and initialize the timer
    if (lastTick == 0)
        lastTick = currentTick;

    deltaTime = currentTick - lastTick;
    lastTick = currentTick;

    return deltaTime;
}