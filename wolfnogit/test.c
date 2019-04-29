/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 12:18:55 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 14:07:04 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./SDL2.framework/Headers/SDL.h"
#include <stdio.h>



#define SCR_W 1000
#define SCR_H 1000

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		return -1;
	}

	SDL_Window* pWindow = NULL;
	pWindow = SDL_CreateWindow("Random stuff", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
	if(!pWindow)
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());

	SDL_Renderer *pRenderer = NULL;
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	if(!pRenderer)
		fprintf(stderr,"Erreur de création du renderer: %s\n",SDL_GetError());

	int loop = 1;
	while (loop)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
				loop = 0;

		SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
		SDL_RenderClear(pRenderer);



		SDL_SetRenderDrawColor(pRenderer,255,255,255,255);
		SDL_Rect srcRect;
		srcRect.x = 10;
		srcRect.y = 10;
		srcRect.h = 200;
		srcRect.w = 200;
		SDL_RenderFillRect(pRenderer,&srcRect);

		SDL_Rect srcRect;
		srcRect.h = 200;
		srcRect.w = 200;


		SDL_SetRenderDrawColor(pRenderer,255,255,255,0);
		srcRect.y = 800;
		for (int j = 800 ; j < 830 ; j++)
			for (int i = 0 ; i < 200 ; i++)
				srcRect.x = i, srcRect.y = j;


		SDL_RenderPresent(pRenderer);

		SDL_Delay(1);
	}
	SDL_Quit();
	return 0;
}
