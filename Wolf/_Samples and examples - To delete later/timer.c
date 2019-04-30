#include "timer.h"

Uint32 Timer(Uint32 deltaTime) {
    Uint32 currentTick = SDL_GetTicks();
    static Uint32 lastTick = 0;

    if (lastTick == 0) {
        lastTick = currentTick;
        return 0;
    }

    deltaTime = currentTick - lastTick;
    lastTick = currentTick;

    return deltaTime;
}