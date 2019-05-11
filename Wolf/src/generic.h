#ifndef GENERIC_H_INCLUDED
#define GENERIC_H_INCLUDED

//Generic data that is used EVERYWHERE in the program.

/* ***** INCLUDES *********************************** */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <assert.h>

#if defined(_WIN32)

#include <windows.h>

#endif

#include "../resources/SDL2/SDL.h"
#include "map.h"
//Add if else for linux users so it adds : #include <SDL2/SDL.h> instead

/* ***** DEFINES *********************************** */
#define WIN_NAME "Wolfenstein"
#define M_UPDATE_TIMER 8
#define M_RENDER_TIMER 33
#define P_UPDATE_TIMER 4
#define P_RENDER_TIMER 16

#define COUNT_OF(ptr) (sizeof(ptr)/sizeof(ptr[0]))


/* ***** STRUCTS *********************************** */

typedef struct error {
	uint8_t errorCode;
	char *name;
	char *description;
	_Bool isFatal;
	uint8_t type;
} error_t;

typedef struct pos2d {
	int x;
	int y;
} pos2d;

typedef struct mouse {
	pos2d pos;
	//int x;
	//int y;
	_Bool leftBtn;
	_Bool rightBtn;
} mouse;

typedef struct keyboard {
	_Bool w;
	_Bool a;
	_Bool s;
	_Bool d;
	_Bool q;
	_Bool e;
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
	error_t err;
} game;


/* ***** ENUMS *********************************** */
enum game_state {
	INIT,
	MAIN_MENU,
	PLAY,
	PLAY_MENU,
	EXIT
};

enum enum_error {
	ERROR_UNDEFINED,
	ERROR_SDL_INIT_FAILURE,
	ERROR_WINDOW_INIT_FAILURE,
	ERROR_RENDERER_INIT_FAILURE,
	ERROR_LOADBMP_FAILURE,
	ERROR_LOADTEXTURE_FAILURE
};

enum enum_error_type {
	ERROR_TYPE_GAME,
	ERROR_TYPE_SDL,
	ERROR_TYPE_ERRNO
};

/* ***** GLOBALS *********************************** */
//None needed yet, maybe some kind of errno will be needed later

//#include "main.h" // I put it here because otherwise he tells me he does not know game
#include "error.h"

#endif //GENERIC_H_INCLUDED
