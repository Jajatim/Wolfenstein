#include "menu.h"

static int m_update_title(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;
	
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
		if (collide_dot_rect(g->mse.pos, m->btn_play_dst)) {
			g->status = PLAY;

			//TODO : move to game state change function 
			//TODO : How to manage state change init function ?
			g->init = &p_init;
			p_init(g, m, p); //Needs call cause loop won't return to init state... what to do ?

			g->update = &p_update;
			g->updateDelta = 0;
			g->updateTimer = P_UPDATE_TIMER;

			g->render = &p_render;
			g->renderDelta = 0;
			g->renderTimer = P_RENDER_TIMER;
		}

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


static int m_update_options(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;
	
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


int m_update(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;
	
	switch (m->m_status) {
		case MENU_TITLE:
			g->status = m_update_title(g, m, p);
			break;
		case MENU_OPTIONS:
			g->status = m_update_options(g, m, p);
			break;
		default:
			//TODO : Error
			fprintf(stderr, "Wrong menu status\n");
			exit(1);
	}
	return g->status;
}
