/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:51:24 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 17:29:54 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "generic.h"
#include "menu/menu.h"



static void g_free(game *g)
{
	if (g->window != NULL){
		SDL_DestroyWindow(g->window);
		g->window = NULL;
	}

	if (g->renderer != NULL){
		SDL_DestroyRenderer(g->renderer);
		g->renderer = NULL;
	}
}



static int g_init(game *g)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0 ) {
		fprintf(sterr, "SDL initialisation failed: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	g->win = SDL_CreateWindow(WIN_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, g->screenW, g->screenH, SDL_WINDOW_SHOWN);
	if (!g->win) {
		fprintf(stderr, "Window creation failed: %s\n",SDL_GetError());
		return 1;
	}

	g->ren = SDL_CreateRenderer(g->win, -1, 0);
	if (!g->ren) {
		fprintf(stderr, "Renderer creation failed: %s\n",SDL_GetError());
		return 1;
	}

	g->status = INIT;

	return 0;
}


int test(); //del

int main(int argc, char **argv)
{
	argv[0][0] += argc * 0; //del
	printf("Printing main\n"); //del
	test(); //del

	game g;

	if (g_init(&g))
		; //TODO : gestion err
	menu_loop(&g);
	//g_free(&g);

	return EXIT_SUCCESS;
}
