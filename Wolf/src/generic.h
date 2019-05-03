#ifndef GENERIC_H_INCLUDED
#define GENERIC_H_INCLUDED

//Generic data that is used EVERYWHERE in the program.

/* ***** INCLUDES *********************************** */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "../resources/SDL2/SDL.h"
//Add if else for linux users so it adds : #include <SDL2/SDL.h> instead


/* ***** DEFINES *********************************** */
#define WIN_NAME "Wolfenstein"
#define M_RENDER_TIMER 33


/* ***** STRUCTS *********************************** */
typedef struct mouse {
	int x;
	int y;
	int leftBtn;
	int rightBtn;
} mouse;

typedef struct keyboard {
	int w;
	int a;
	int s;
	int d;
	int q;
	int e;
} keyboard;

typedef struct game {
	/* SDL & Window infos */
    SDL_Window *win;
    SDL_Renderer *ren;
    uint16_t screenW;
    uint16_t screenH;

	/* Game general infos */
    uint8_t status;

	/* User input */
	keyboard kbd;
	mouse mse;

	/* Error management */
	int err;
} game;


/* ***** ENUMS *********************************** */
enum game_state {
	INIT,
	MAIN_MENU,
	PLAY,
	PLAY_MENU,
	EXIT
};


/* ***** GLOBALS *********************************** */
//None needed yet, maybe some kind of errno will be needed later


#endif //GENERIC_H_INCLUDED
