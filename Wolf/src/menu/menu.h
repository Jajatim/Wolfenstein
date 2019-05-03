#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "../generic.h"

typedef struct menu {
	uint32_t deltaTime;
    uint32_t renderTimer;
} menu;

int menu_loop(game *g);
int m_init(game *g, menu *m);
int m_update(game *g, menu *m);
int m_render(game *g, menu *m);
int m_events(game *g);

#endif //MENU_H_INCLUDED
