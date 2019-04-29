/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   timer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 19:31:16 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 19:41:27 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "SDL.h"

//SDL_GetTicks() autorise ? Ou utiliser clock() ?

Uint32	get_time(void)
{
	static Uint32	last = 0;
	Uint32			current;
	Uint32			deltatime;

	current = SDL_GetTicks();
	deltatime = current - last;
	last = current;
	return (deltatime);
}
