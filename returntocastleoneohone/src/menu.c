/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   menu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 14:38:54 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 19:58:45 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

static int m_render(t_game *g, t_menu *m)
{
	SDL_SetRenderDrawColor(g->sdl.r,0,0,0,255);
	SDL_RenderClear(g->sdl.r);

	//actual render
	SDL_RenderCopy(g->sdl.r, m->btn,
			&(m->btn_play), &(SDL_Rect){SCR_W / 4, SCR_H / 3 + 00, SCR_W / 2, 200});
	SDL_RenderCopy(g->sdl.r, m->btn,
			&(m->btn_options), &(SDL_Rect){SCR_W / 4, SCR_H / 3 + 250, SCR_W / 2, 200});
	SDL_RenderCopy(g->sdl.r, m->btn,
			&(m->btn_exit), &(SDL_Rect){SCR_W / 4, SCR_H / 3 + 500, SCR_W / 2, 200});

	SDL_RenderPresent(g->sdl.r);
	return (1);
}

static void m_init_assets(t_game *g, t_menu *m)
{
	SDL_Surface *tmp;
 
	tmp = SDL_LoadBMP("./assets/assets.bmp");
	m->btn = SDL_CreateTextureFromSurface(g->sdl.r, tmp);
	SDL_FreeSurface(tmp);
	m->btn_play = (SDL_Rect){0, 0, 100, 40};
	m->btn_options = (SDL_Rect){0, 40, 100, 40};
	m->btn_exit = (SDL_Rect){0, 80, 100, 40};
}

static int m_init(t_game *g, t_menu *m)
{
	if (g->g_state == LOADING)
		m_init_assets(g, m);
	
	return (1);
}

int menu(t_game *g)
{
	t_menu m;

	m_init(g, &m);

	while (g->g_state != EXIT)
	{
		g->g_state = m_events(g);
		//m_update(&m, g);
		m_render(g, &m);
		if (g->g_state == PLAY)
		{
			//m_free(&m);
			//play(g);
			//m_init(&m);
		}
		SDL_Delay(1);
	}
	//m_free(m);
	return (1);
}
