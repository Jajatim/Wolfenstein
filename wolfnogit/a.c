/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   a.c                                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sifouche <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 14:20:45 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 18:16:48 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./SDL2.framework/Headers/SDL.h"
#include <stdio.h>



#define SCR_W 1600
#define SCR_H 1200



typedef struct s_kbd
{
	int w;
	int a;
	int s;
	int d;
	int q;
	int e;
	int rain;
	int snow;
}               t_kbd;

Uint32 fTimer() {
	Uint32 currentTick = SDL_GetTicks();
	static Uint32 lastTick=0;
	Uint32 deltaTime = 0;
	if (lastTick == 0) {
		lastTick = currentTick;
		return 0;
	}
	deltaTime = currentTick - lastTick;
	lastTick = currentTick;

	return deltaTime;
}

int		get_events(t_kbd *k)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return (0);
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				return (0);
			else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
				k->w = 1;
			else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
				k->s = 1;
			else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
				k->d = 1;
			else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
				k->a = 1;
			else if (event.key.keysym.sym == SDLK_q)
				k->q = 1;
			else if (event.key.keysym.sym == SDLK_e)
				k->e = 1;
			else if (event.key.keysym.sym == SDLK_r)
				k->rain = 1;
			else if (event.key.keysym.sym == SDLK_t)
				k->snow = 1;
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
				k->w = 0;
			else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
				k->s = 0;
			else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
				k->d = 0;
			else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)
				k->a = 0;
			else if (event.key.keysym.sym == SDLK_q)
				k->q = 0;
			else if (event.key.keysym.sym == SDLK_e)
				k->e = 0;
			else if (event.key.keysym.sym == SDLK_r)
				k->rain = 0;
			else if (event.key.keysym.sym == SDLK_t)
				k->snow = 0;
		}
	}
	return (1);
}





typedef struct s_vec2
{
	double x;
	double y;
}				t_vec2;


#include <time.h>
int main(int argc, char** argv)
{
	srand (time(NULL));

	argv[0][0] += argc * 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		exit(1);
	}

	SDL_Window* pWindow = NULL;
	pWindow = SDL_CreateWindow("Random stuff", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
	if(!pWindow)
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());

	SDL_Renderer *pRenderer = NULL;
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	if(!pRenderer)
		fprintf(stderr,"Erreur de création du renderer: %s\n",SDL_GetError());

	Uint32 deltaTime = 0;
	Uint32 updateTimer = 0;
	Uint32 renderTimer = 0;
	t_kbd keyboard = {0};

	int map[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,1},
		{1,1,0,1,1,1,0,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};

	double moveSpeed = 0.05;//0.005;
	double rotSpeed = 0.05;//0.005;
	t_vec2 p_pos = {8.0, 8.0};
	t_vec2 p_dir = {-1.0, 0.0};
	t_vec2 plane = {0.0, 0.66};

	t_vec2 e_pos = {1, 1};
	t_vec2 e_dir = {-1.0, 0.0};

	int loop = 1;
	while (loop)
	{
		deltaTime = fTimer();

		loop = get_events(&keyboard);

		updateTimer += deltaTime;
		if (updateTimer > 4)
		{
			updateTimer = 0;
			if (keyboard.w)
			{
				p_pos.x += moveSpeed * p_dir.x;
				p_pos.y += moveSpeed * p_dir.y;
			}
			if (keyboard.s)
			{
				p_pos.x -= moveSpeed * p_dir.x;
				p_pos.y -= moveSpeed * p_dir.y;
			}
			if (keyboard.d)
			{
				double oldDirX = p_dir.x;
				p_dir.x = p_dir.x * cos(-rotSpeed) - p_dir.y * sin(-rotSpeed);
				p_dir.y = oldDirX * sin(-rotSpeed) + p_dir.y * cos(-rotSpeed);
				double oldPlaneX = plane.x;
				plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
				plane.y = oldPlaneX * sin(-rotSpeed) + plane.y * cos(-rotSpeed);
			}
			if (keyboard.a)
			{
				double oldDirX = p_dir.x;
				p_dir.x = p_dir.x * cos(rotSpeed) - p_dir.y * sin(rotSpeed);
				p_dir.y = oldDirX * sin(rotSpeed) + p_dir.y * cos(rotSpeed);
				double oldPlaneX = plane.x;
				plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
				plane.y = oldPlaneX * sin(rotSpeed) + plane.y * cos(rotSpeed);
			}
			if (keyboard.q)
			{
				p_pos.x -= p_dir.y * moveSpeed;
				p_pos.y -= -(p_dir.x) * moveSpeed;
			}
			if (keyboard.e)
			{
				p_pos.x += p_dir.y * moveSpeed;
				p_pos.y += -(p_dir.x) * moveSpeed;
			}
		}




		renderTimer += deltaTime;
		if (renderTimer > 16)
		{
			renderTimer = 0;
			SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
			SDL_RenderClear(pRenderer);

			for (int x = 0; x < SCR_W; x++)
			{
				//			printf("\e[1;1H\e[2J");
				double cameraX = 2 * x / (double)SCR_W - 1;

				t_vec2 ray;
				ray.x = p_dir.x + plane.x * cameraX;
				ray.y = p_dir.y + plane.y * cameraX;

				int mapx = (int)p_pos.x;
				int mapy = (int)p_pos.y;

				t_vec2 sidedst;

				t_vec2 deltadst;
				deltadst.x = 1 / ray.x;
				deltadst.x = (deltadst.x < 0) ? -(deltadst.x) : deltadst.x;
				deltadst.y = 1 / ray.y;
				deltadst.y = (deltadst.y < 0) ? -(deltadst.y) : deltadst.y;

				int stepx;
				int stepy;

				int hit = 0;
				int side;
				double walldst;

				if (ray.x < 0)
				{
					stepx = -1;
					sidedst.x = (p_pos.x - mapx) * deltadst.x;
				}
				else
				{
					stepx = 1;
					sidedst.x = (mapx + 1.0 - p_pos.x) * deltadst.x;
				}
				if (ray.y < 0)
				{
					stepy = -1;
					sidedst.y = (p_pos.y - mapy) * deltadst.y;
				}
				else
				{
					stepy = 1;
					sidedst.y = (mapy + 1.0 - p_pos.y) * deltadst.y;
				}

				while (!hit)
				{
					if (sidedst.x < sidedst.y)
					{
						sidedst.x += deltadst.x;
						mapx += stepx;
						side = 0;
					}
					else
					{
						sidedst.y += deltadst.y;
						mapy += stepy;
						side = 1;
					}

					if (map[mapx][mapy] > 0)
						hit = 1;
				}

				if (!side)
					walldst = (mapx - p_pos.x + (1 - stepx) / 2) / ray.x;
				else
					walldst = (mapy - p_pos.y + (1 - stepy) / 2) / ray.y;

				int lineHeight = (int)(SCR_H / walldst);

				int drawStart = -lineHeight / 2 + SCR_H / 2;
				if (drawStart < 0)
					drawStart = 0;
				int drawEnd = lineHeight / 2 + SCR_H / 2;
				if (drawEnd >= SCR_H)
					drawEnd = SCR_H - 1;

				if (side)
					SDL_SetRenderDrawColor(pRenderer,200,200,200,255);
				else
					SDL_SetRenderDrawColor(pRenderer,100,100,100,255);

				SDL_Rect srcRect;
				srcRect.x = x;
				srcRect.y = drawStart;
				srcRect.h = drawEnd - drawStart;
				srcRect.w = 1;
				SDL_RenderFillRect(pRenderer,&srcRect);

				srcRect.y = 0;
				srcRect.h = drawStart;
				SDL_SetRenderDrawColor(pRenderer,0,0,255,255);
				SDL_RenderFillRect(pRenderer,&srcRect);

				srcRect.y = drawEnd;
				srcRect.h = SCR_H - drawEnd;
				SDL_SetRenderDrawColor(pRenderer,50,50,50,255);
				SDL_RenderFillRect(pRenderer,&srcRect);
			}




			/* COMING NEXT : USELEFF STUFF */

			/* MAKE IT RAIN !!! */
			if (keyboard.rain)
			{
				SDL_SetRenderDrawColor(pRenderer,250,250,250,150);
				for (int i = 0 ; i < 200 ; i++)
				{
					SDL_Rect srcRect;
					srcRect.x = rand() % SCR_W;
					srcRect.y = rand() % SCR_H;
					srcRect.h = 30;
					srcRect.w = 1;
					SDL_RenderFillRect(pRenderer,&srcRect);
				}
			}


			/* LET IT SNOOOOOOW */
			if (keyboard.snow)
			{
				static int pos = -1;
				static SDL_Rect tsnow[200];
				if (pos == -1)
				{
					for (int i = 0 ; i < 200 ; i++)
					{
						tsnow[i].x = rand() % SCR_W;
						tsnow[i].y = rand() % SCR_H;
						tsnow[i].h = 5;
						tsnow[i].w = 5;
					}
				}
				pos++;
				SDL_SetRenderDrawColor(pRenderer,255,255,255,255);
				for (int i = 0 ; i < 200 ; i++)
				{
					if (pos % 5 == 0 && rand() % 3 == 0)
					{
						if (i % 2)
							tsnow[i].x-=2;
						else
							tsnow[i].x+=2;
					}
					if (tsnow[i].x <= 0)
						tsnow[i].x = SCR_W - 1;
					if (tsnow[i].x >= SCR_W)
						tsnow[i].x = 1;
					if (pos >= 7)
						tsnow[i].y++;
					if (tsnow[i].y > SCR_H)
						tsnow[i].y = 0;
					SDL_RenderFillRect(pRenderer,&(tsnow[i]));
				}
				if (pos >= 10)
					pos = 0;
			}
			SDL_RenderPresent(pRenderer);
		}
		SDL_Delay(1);
	}
	SDL_Quit();
	return 0;
}
