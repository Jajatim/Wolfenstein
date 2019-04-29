/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:51:24 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 19:32:41 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf.h"

/*
int play(t_game *g)
{
	t_play p;

	p_init(&p);

	while(!p.quit)
	{
		events(g);
		timer(&p);
		update(&p);
		render(p);
	}
	p_free(p);
	return (1);
}

int menu(t_game *g)
{
	t_menu m;

	m_init(&m);

	while (!m.quit)
	{
		events(&g);
		update(&m);
		render(m);

		if (g.play)
		{
			play(g);
			m_init(&m);
		}
	}
	m_free(m);
	return (1);
}
*/

static void g_free(t_game *g)
{
	if (g->sdl.w_ok)
		SDL_DestroyWindow(g->sdl.w);
	if (g->sdl.r_ok)
		SDL_DestroyRenderer(g->sdl.r);
}

static int g_init(t_game *g)
{
	g->sdl.w = SDL_CreateWindow(WIN_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
	g->sdl.w_ok = 1;
	if (!g->sdl.w && !(g->sdl.w_ok = 0))
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());

	g->sdl.r = SDL_CreateRenderer(g->sdl.w, -1, 0);
	g->sdl.r_ok = 1;
	if (!g->sdl.r && !(g->sdl.r_ok = 0))
		fprintf(stderr,"Erreur de création du renderer: %s\n",SDL_GetError());
	
	if (!g->sdl.w_ok || !g->sdl.r_ok)
		return (1);
	
	g->g_state = LOADING;
	return (0);
}

int main()
{
	t_game g;

	if (g_init(&g))
		; //TODO : err
	menu(&g);
	g_free(&g);
}
