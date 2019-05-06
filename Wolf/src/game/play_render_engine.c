#include "play.h"

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

int p_engine(game *g, play *p)
{
	for (int x = 0; x < g->screenW; x++)
	{
		double cameraX = 2 * x / (double)g->screenW - 1;

		vec2 ray;
		ray.x = p->dir.x + p->plane.x * cameraX;
		ray.y = p->dir.y + p->plane.y * cameraX;

		int mapx = (int)p->pos.x;
		int mapy = (int)p->pos.y;

		vec2 sidedst;

		vec2 deltadst;
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
			sidedst.x = (p->pos.x - mapx) * deltadst.x;
		}
		else
		{
			stepx = 1;
			sidedst.x = (mapx + 1.0 - p->pos.x) * deltadst.x;
		}
		if (ray.y < 0)
		{
			stepy = -1;
			sidedst.y = (p->pos.y - mapy) * deltadst.y;
		}
		else
		{
			stepy = 1;
			sidedst.y = (mapy + 1.0 - p->pos.y) * deltadst.y;
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
			walldst = (mapx - p->pos.x + (1 - stepx) / 2) / ray.x;
		else
			walldst = (mapy - p->pos.y + (1 - stepy) / 2) / ray.y;

		int lineHeight = (int)(g->screenH / walldst);

		int drawStart = -lineHeight / 2 + g->screenH / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + g->screenH / 2;
		if (drawEnd >= g->screenH)
			drawEnd = g->screenH - 1;

		if (side)
			SDL_SetRenderDrawColor(g->ren,200,200,200,255);
		else
			SDL_SetRenderDrawColor(g->ren,100,100,100,255);

		SDL_Rect srcRect;
		srcRect.x = x;
		srcRect.y = drawStart;
		srcRect.h = drawEnd - drawStart;
		srcRect.w = 1;
		SDL_RenderFillRect(g->ren,&srcRect);

		srcRect.y = 0;
		srcRect.h = drawStart;
		SDL_SetRenderDrawColor(g->ren,0,0,255,255);
		SDL_RenderFillRect(g->ren,&srcRect);

		srcRect.y = drawEnd;
		srcRect.h = g->screenH - drawEnd;
		SDL_SetRenderDrawColor(g->ren,50,50,50,255);
		SDL_RenderFillRect(g->ren,&srcRect);
	}

	return 1;
}
