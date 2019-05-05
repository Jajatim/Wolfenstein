#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../generic.h"

#define MENU_ASSETS_PATH "../resources/m_assets.bmp"
#define MENU_BTN_H 40
#define MENU_BTN_W 100

typedef struct menu {
	uint32_t deltaTime;
    uint32_t renderTimer;
	SDL_Texture *menuAssets;
	SDL_Rect btn_play;
	//SDL_Rect btn_play_hover;
	SDL_Rect btn_opt;
	//SDL_Rect btn_opt_hover;
	SDL_Rect btn_exit;
	//SDL_Rect btn_exit_hover;
} menu;

int menu_loop(game *g);
int m_init(game *g, menu *m);
int m_update(game *g, menu *m);
int m_render(game *g, menu *m);
int m_events(game *g);

#endif //MENU_H_INCLUDED
