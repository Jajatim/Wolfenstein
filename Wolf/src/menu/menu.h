#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../generic.h"
#include "../play/play.h"
#include "../utils/utils.h"

#define MENU_ASSETS_PATH "resources/assets/m_assets.bmp"
#define MENU_BTN_H 50
#define MENU_BTN_W 100

//int menu_loop(game *g);
int m_init(game *g, menu *m, play *p);
int m_update(game *g, menu *m, play *p);
int m_render(game *g, menu *m, play *p);
int m_free(menu *m);

#endif //MENU_H_INCLUDED
