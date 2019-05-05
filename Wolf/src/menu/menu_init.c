#include "menu.h"
#include "../utils/utils.h"

int m_init(game *g, menu *m)
{
	//Init variables
	m->deltaTime = 0;
	m->renderTimer = 0;
	m->menuAssets = NULL;
	//m->btn_play = (SDL_Rect){0, 0, 0, 0};
	//m->btn_opt = (SDL_Rect){0, 0, 0, 0};
	//m->btn_exit = (SDL_Rect){0, 0, 0, 0};

	//Init timer (need to init the static var)
	timer(m->deltaTime);

	//Loading the assets texture
	SDL_Surface *tmp = SDL_LoadBMP(MENU_ASSETS_PATH);
	if (tmp == NULL) {
		g->err.errorCode = ERROR_LOADBMP_FAILURE;
		g->err.type = ERROR_TYPE_SDL;
		g->err.isFatal = true;
		onError(g);
		return 0;
	}
	m->menuAssets = SDL_CreateTextureFromSurface(g->ren, tmp);
	SDL_FreeSurface(tmp);
	if (m->menuAssets == NULL) {
		g->err.errorCode = ERROR_LOADTEXTURE_FAILURE;
		g->err.type = ERROR_TYPE_SDL;
		g->err.isFatal = true;
		onError(g);
		return 0;
	}

	//Loading the buttons from the texture
	int currentY = 0;
	m->btn_play = (SDL_Rect) {
		.x = 0,
		.y = currentY,
		.w = MENU_BTN_W,
		.h = MENU_BTN_H
	};
	currentY += MENU_BTN_H;
	m->btn_opt = (SDL_Rect) {
		.x = 0,
		.y = currentY,
		.w=MENU_BTN_W,
		.h=MENU_BTN_H
	};
	currentY += MENU_BTN_H;
	m->btn_exit = (SDL_Rect) {
		.x = 0,
		.y = currentY,
		.w = MENU_BTN_W,
		.h = MENU_BTN_H
	};
	currentY += MENU_BTN_H;

	return 1;
}
