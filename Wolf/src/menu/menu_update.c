#include "menu.h"
#include "../utils/utils.h"

int m_update(game *g, menu *m)
{
	//Init btns to default state
	m->btn_play_src.x = 0;
	m->btn_opt_src.x = 0;
	m->btn_exit_src.x = 0;

	//Updating btn to hover state if needed
	if (collide_dot_rect(g->mse.pos, m->btn_play_dst))
		m->btn_play_src.x = MENU_BTN_W;
	if (collide_dot_rect(g->mse.pos, m->btn_opt_dst))
		m->btn_opt_src.x = MENU_BTN_W;
	if (collide_dot_rect(g->mse.pos, m->btn_exit_dst))
		m->btn_exit_src.x = MENU_BTN_W;

	//Click event
	if (g->mse.leftBtn) {
		//Clicked play btn

		//Clicked options btn

		//Clicked exit btn
		if (collide_dot_rect(g->mse.pos, m->btn_exit_dst))
			g->status = EXIT;
	}

	return g->status;
}
