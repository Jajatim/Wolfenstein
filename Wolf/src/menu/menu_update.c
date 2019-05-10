#include "menu.h"
#include "../utils/utils.h"

static int m_update_title(game *g, menu *m)
{
	//Init btns to default state
	m->btn_play_src.x = 0;
	m->btn_opt_src.x = 0;
	m->btn_exit_src.x = 0;

	//Updating btn to hover state if needed
	if (collide_dot_rect(g->mse.pos, m->btn_play_dst))
		m->btn_play_src.x = MENU_BTN_W;
	else if (collide_dot_rect(g->mse.pos, m->btn_opt_dst))
		m->btn_opt_src.x = MENU_BTN_W;
	else if (collide_dot_rect(g->mse.pos, m->btn_exit_dst))
		m->btn_exit_src.x = MENU_BTN_W;

	//Click event
	if (g->mse.leftBtn) {
		//Clicked play btn
		if (collide_dot_rect(g->mse.pos, m->btn_play_dst))
			g->status = PLAY;

		//Clicked options btn
		else if (collide_dot_rect(g->mse.pos, m->btn_opt_dst))
			m->m_status = MENU_OPTIONS;

		//Clicked exit btn
		else if (collide_dot_rect(g->mse.pos, m->btn_exit_dst))
			g->status = EXIT;

		g->mse.leftBtn = 0;
	}

	return g->status;
}


static int m_update_options(game *g, menu *m)
{
	//Init btns to default state
	m->btn_exit_src.x = 0;

	//Updating btn to hover state if needed
	if (collide_dot_rect(g->mse.pos, m->btn_exit_dst))
		m->btn_exit_src.x = MENU_BTN_W;

	//Click event
	if (g->mse.leftBtn) {
		//Clicked exit btn
		if (collide_dot_rect(g->mse.pos, m->btn_exit_dst))
			m->m_status = MENU_TITLE;

		g->mse.leftBtn = 0;
	}

	return g->status;
}


int m_update(game *g, menu *m)
{
	switch (m->m_status) {
		case MENU_TITLE:
			g->status = m_update_title(g, m);
			break;
		case MENU_OPTIONS:
			g->status = m_update_options(g, m);
			break;
		default:
			//TODO : Error
			fprintf(stderr, "Wrong menu status\n");
			exit(1);
	}
	return g->status;
}
