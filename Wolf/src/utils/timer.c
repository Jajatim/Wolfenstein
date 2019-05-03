#include "utils.h"

uint32_t timer(uint32_t deltaTime) {
    uint32_t currentTick = SDL_GetTicks();
    static uint32_t lastTick = 0;

    //First time here will return 0 and initialize the timer
    if (lastTick == 0)
        lastTick = currentTick;

    deltaTime = currentTick - lastTick;
    lastTick = currentTick;

    return deltaTime;
}
