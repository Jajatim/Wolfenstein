#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../generic.h"

#define MENU_ASSETS_PATH "resources/assets/m_assets.bmp"
#define MENU_BTN_H 50
#define MENU_BTN_W 100

typedef enum m_status {
	MENU_TITLE,
	MENU_OPTIONS
} menu_status;

typedef struct menu {
	/* General menu info */
	menu_status m_status;

	/* Timers */
	uint32_t deltaTime;
	uint32_t updateTimer;
    uint32_t renderTimer;

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

int menu_loop(game *g);
int m_init(game *g, menu *m);
int m_update(game *g, menu *m);
int m_render(game *g, menu *m);

#endif //MENU_H_INCLUDED
