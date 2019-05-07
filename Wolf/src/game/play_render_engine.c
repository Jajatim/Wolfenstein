#include "play.h"

int p_engine(game *g, play *p)
{
	
	//TEMP MAP LOADING
	static uint8_t **map = NULL;
	static map_t *metaMap = NULL;

	if (map == NULL)
	{
		metaMap = loadMap("maps/test.map");
		assert(metaMap != NULL); // TODO : add error
		map = metaMap->map;
	}




	for (int col = 0; col < g->screenW; col++) {
		//Variable initialisation

		//x value of the camera : left = -1, center = 0, right = 1
		const double cameraX = 2.0 * (double)col / (double)g->screenW - 1.0;

		//Current ray vector
		vec2 ray = {
			.x = p->dir.x + p->plane.x * cameraX,
			.y = p->dir.y + p->plane.y * cameraX
		};

		//Current position in the map
		pos2d mapPos = {
			.x = (int)p->pos.x,
			.y = (int)p->pos.y
		};

		//Full distance between 2 squares
		vec2 deltaDst;


		//Digital Differential Analysis init
		pos2d stepDir;
		vec2 curDst;

		//Calc the distance until next map square according to ray vector direction
		if (ray.x < 0) {
			stepDir.x = -1;
			deltaDst.x = 1.0 / -(ray.x);
			curDst.x = (p->pos.x - mapPos.x) * deltaDst.x;
		}
		else {
			stepDir.x = 1;
			deltaDst.x = 1.0 / ray.x;
			curDst.x = (mapPos.x + 1.0 - p->pos.x) * deltaDst.x;
		}
		if (ray.y < 0) {
			stepDir.y = -1;
			deltaDst.y = 1.0 / -(ray.y);
			curDst.y = (p->pos.y - mapPos.y) * deltaDst.y;
		}
		else {
			stepDir.y = 1;
			deltaDst.y = 1.0 / ray.y;
			curDst.y = (mapPos.y + 1.0 - p->pos.y) * deltaDst.y;
		}


		//Digital Differential Analysis calc

		//Wall hit on North/South (=0) or East/West (=1) side ?
		int side;

		while (1)
		{
			//Checking next step on X or Y depending on the closest
			if (curDst.x < curDst.y)
			{
				curDst.x += deltaDst.x;
				mapPos.x += stepDir.x;
				side = 0;
			}
			else
			{
				curDst.y += deltaDst.y;
				mapPos.y += stepDir.y;
				side = 1;
			}

			//A wall has been hit
			if (map[mapPos.x][mapPos.y] > 0)
				break;
		}


		//Wall draw infos
		const int screenHalfHeight = g->screenH / 2;
		double wallDst;
		if (!side)
			wallDst = (mapPos.x - p->pos.x + (1 - stepDir.x) / 2) / ray.x;
		else
			wallDst = (mapPos.y - p->pos.y + (1 - stepDir.y) / 2) / ray.y;

		int wallHeight = (int)(g->screenH / wallDst) / 2;
		int wallStart = screenHalfHeight - wallHeight;
		int wallEnd = screenHalfHeight + wallHeight;
		if (wallHeight >= screenHalfHeight) {
			wallStart = 0;
			wallEnd = g->screenH;
		}

		//Render
		SDL_Rect drawRect = {
			.x = col,
			.y = 0,
			.w = 1,
			.h = wallStart
		};

		//Rendering the sky
		SDL_SetRenderDrawColor(g->ren, 0, 0, 255, 255);
		SDL_RenderFillRect(g->ren, &drawRect);

		//Rendering the wall
		if (side)
			SDL_SetRenderDrawColor(g->ren, 200, 200, 200, 255);
		else
			SDL_SetRenderDrawColor(g->ren, 100, 100, 100, 255);
		drawRect.y = wallStart;
		drawRect.h = wallEnd - wallStart;
		SDL_RenderFillRect(g->ren, &drawRect);

		//Rendering the floor
		SDL_SetRenderDrawColor(g->ren, 50, 50, 50, 255);
		drawRect.y = wallEnd;
		drawRect.h = g->screenH - wallEnd;
		SDL_RenderFillRect(g->ren, &drawRect);
	}

	return 1;
}

