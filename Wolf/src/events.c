/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 16:31:29 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 19:11:44 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "generic.h"

int m_events(game *g)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return EXIT;
		else if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				if (g->status == PLAY_MENU)
					return PLAY;
				else if (g->status == PLAY)
					return PLAY_MENU;
			}
		}
		else if (e.type == SDL_KEYUP)
		{

		}
	}
	return (g->status);
}
