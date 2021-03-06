#ifndef GENERIC_STRUCT_H_INCLUDED
#define GENERIC_STRUCT_H_INCLUDED


/* ***** STRUCTS *********************************** */

typedef struct error {
	uint8_t errorCode;
	char *name;
	char *description;
	char * fileName;
	uint16_t fileLine;
	_Bool isFatal;
	uint8_t type;
} error_t;

typedef struct pos2d {
	int x;
	int y;
} pos2d;

typedef struct mouse {
	pos2d pos;
	_Bool leftBtn;
	_Bool rightBtn;
} mouse;

typedef struct keyboard {
	_Bool a;
	_Bool e;
	_Bool d;
	_Bool q;
	_Bool s;
	_Bool w;
	_Bool z;
} keyboard;

typedef struct actions {
	int moveForward;
	int moveBackward;
	int moveLeft;
	int moveRight;
	int turnLeft;
	int turnRight;
} actions;


typedef enum m_status {
	MENU_TITLE,
	MENU_OPTIONS
} menu_status;

typedef struct menu {
	/* General menu info */
	menu_status m_status;

	/* Textures */
	SDL_Texture *menuAssets;

	/* Btn infos */
	SDL_Rect btn_play_src;
	SDL_Rect btn_play_dst;
	SDL_Rect btn_opt_src;
	SDL_Rect btn_opt_dst;
	SDL_Rect btn_exit_src;
	SDL_Rect btn_exit_dst;
} menu;

typedef struct map {
    uint8_t version; //TODO : Keep or delete ?
    uint8_t h;
    uint8_t w;
    uint8_t **map;
} map_t;

typedef struct vec2 {
	double x;
	double y;
} vec2;

typedef struct play {
	/* Player infos */
	double moveSpeed;
	double rotSpeed;
	vec2 pos;
	vec2 dir;
	vec2 plane;

	/* Map */
	map_t map;
} play;


typedef struct game {
	/* SDL & Window infos */
	SDL_Window *win;
	SDL_Renderer *ren;
	uint16_t screenW;
	uint16_t screenH;

	/* Game general infos */
	uint8_t status_last;
	uint8_t status;

	/* Main loop management */
	int (*init)(struct game *g, menu *m, play *p);
	int (*update)(struct game *g, menu *m, play *p);
	int (*render)(struct game *g, menu *m, play *p);
	uint32_t updateTimer;
	uint32_t renderTimer;
	uint32_t updateDelta;
	uint32_t renderDelta;

	/* User input */
	keyboard kbd;
	mouse mse;
	actions actions;

	/* Error management */
	error_t err;
} game;


#endif //GENERIC_STRUCT_H_INCLUDED