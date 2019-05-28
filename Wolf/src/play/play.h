#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include "../generic.h"
#include "../menu/menu.h"



int play_loop(game *g);
int p_init(game *g, menu *m, play *p);
int p_update(game *g, menu *m, play *p);
int p_render(game *g, menu *m, play *p);

int p_engine(game *g, play *p);

int check_action(game *g, int action);

#endif //PLAY_H_INCLUDED
