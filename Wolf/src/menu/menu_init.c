#include "menu.h"

int m_init(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;
	
	//Init variables
	m->m_status = MENU_TITLE;
	m->menuAssets = NULL;

	//Loading the assets texture
	SDL_Surface *tmp = SDL_LoadBMP(MENU_ASSETS_PATH);
	if (tmp == NULL) {
		g->err.errorCode = ERROR_LOADBMP_FAILURE;
		g->err.type = ERROR_TYPE_SDL;
		g->err.isFatal = true;
		updateFileInfoError(g, __LINE__, __FILE__);
		onError(g);
		return 0;
	}
	m->menuAssets = SDL_CreateTextureFromSurface(g->ren, tmp);
	SDL_FreeSurface(tmp);
	if (m->menuAssets == NULL) {
		g->err.errorCode = ERROR_LOADTEXTURE_FAILURE;
		g->err.type = ERROR_TYPE_SDL;
		g->err.isFatal = true;
		updateFileInfoError(g, __LINE__, __FILE__);
		onError(g);
		return 0;
	}

	//Loading the buttons from the texture
	int currentY = 0;
	m->btn_play_src = (SDL_Rect) {
		.x = 0,
		.y = currentY,
		.w = MENU_BTN_W,
		.h = MENU_BTN_H
	};
	currentY += MENU_BTN_H;
	m->btn_opt_src = (SDL_Rect) {
		.x = 0,
		.y = currentY,
		.w = MENU_BTN_W,
		.h = MENU_BTN_H
	};
	currentY += MENU_BTN_H;
	m->btn_exit_src = (SDL_Rect) {
		.x = 0,
		.y = currentY,
		.w = MENU_BTN_W,
		.h = MENU_BTN_H
	};
	currentY += MENU_BTN_H;

	return 1;
}
