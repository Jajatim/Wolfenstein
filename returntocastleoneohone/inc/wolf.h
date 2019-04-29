/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/18 13:51:23 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 19:16:52 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

//temp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//fin temp



#include "SDL.h"


/* *** ENUMS ************************************************************************* */
enum e_gstate
{
	LOADING = 0,
	MAIN_MENU,
	PLAY,
	PLAY_MENU,
	EXIT
};


/* *** STRUCTS *********************************************************************** */
typedef struct s_sdl
{
	SDL_Window *w;
	int w_ok;
	SDL_Renderer *r;
	int r_ok;
} t_sdl;

typedef struct s_k
{
	int w;
	int a;
	int s;
	int d;
	int up;
	int left;
	int down;
	int right;
	int space;
} t_k;

typedef struct s_game
{
	t_sdl sdl;
	int g_state;
} t_game;

typedef struct s_menu
{
	SDL_Texture *btn;
	SDL_Rect btn_play;
	SDL_Rect btn_options;
	SDL_Rect btn_exit;
} t_menu;


/* *** DEFINES *********************************************************************** */
# define WIN_NAME "Window Name"
# define SCR_W 1920
# define SCR_H 1080

int menu(t_game *g);
int m_events(t_game *g);

#endif
