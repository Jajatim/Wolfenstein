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

#if defined(__unix__)
#include <signal.h>
#endif

#include <SDL2/SDL.h>


/* ***** STRUCTS *********************************** */
#include "generic_struct.h"


/* ***** LOCAL INCLUDES *********************************** */
#include "map.h"
#include "error.h"


/* ***** DEFINES *********************************** */
#define WIN_NAME "Wolfenstein"
#define M_UPDATE_TIMER 8
#define M_RENDER_TIMER 33
#define P_UPDATE_TIMER 4
#define P_RENDER_TIMER 16

#define COUNT_OF(ptr) (sizeof(ptr)/sizeof(ptr[0]))


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
	ERROR_LOADTEXTURE_FAILURE,
	ERROR_LOADMAP_FAILURE,
	ERROR_SIGNAL // Unix Only
};

enum enum_error_type {
	ERROR_TYPE_GAME,
	ERROR_TYPE_SDL,
	ERROR_TYPE_ERRNO
};

/* ***** GLOBALS *********************************** */
//None needed yet, maybe some kind of errno will be needed later

game *getGame(game *toSet);

#endif //GENERIC_H_INCLUDED
