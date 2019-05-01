#ifndef GENERIC_H_INCLUDED
#define GENERIC_H_INCLUDED

//Generic data that is used EVERYWHERE in the program.

/* ***** INCLUDES *********************************** */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>


/* ***** STRUCTS *********************************** */
typedef struct game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    uint16_t screenSizeWidth;
    uint16_t screenSizeHeight;
    uint8_t status;
} game;
//

//SDL data (window, renderer, etc...)
//Generic data (Keyboard, mouse, etc...)


/* ***** ENUMS *********************************** */
//Game state ? (e.g. INIT, MAIN_MENU, GAME, INGAME_MENU, etc...)


/* ***** GLOBALS *********************************** */
//None needed yet, maybe some kind of errno will be needed later


#endif //GENERIC_H_INCLUDED