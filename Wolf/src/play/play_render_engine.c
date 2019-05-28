#include "play.h"

static int dda_raycast(play *p, uint8_t **map, pos2d *mapPos, pos2d *stepDir, vec2 *ray)
{
	//Current travelled distance
	vec2 curDst;

	//Distance between two squares on each axis
	vec2 deltaDst;

	//Digital Differential Analysis init
	//Sets the step (direction of ray in square units), and sets the distances
	if (ray->x < 0) {
		stepDir->x = -1;
		deltaDst.x = 1.0 / -(ray->x);
		curDst.x = (p->pos.x - mapPos->x) * deltaDst.x;
	}
	else {
		stepDir->x = 1;
		deltaDst.x = 1.0 / ray->x;
		curDst.x = (mapPos->x + 1.0 - p->pos.x) * deltaDst.x;
	}
	if (ray->y < 0) {
		stepDir->y = -1;
		deltaDst.y = 1.0 / -(ray->y);
		curDst.y = (p->pos.y - mapPos->y) * deltaDst.y;
	}
	else {
		stepDir->y = 1;
		deltaDst.y = 1.0 / ray->y;
		curDst.y = (mapPos->y + 1.0 - p->pos.y) * deltaDst.y;
	}


	//Digital Differential Analysis loop
	//Moves to the next square (x or y, the closest is always chosen) until a wall is hit
	//Return the orientation of the wall hit (north/south or east/west)

	int side = 0;

	while (1)
	{
		//Checking next step on X or Y depending on the closest
		if (curDst.x < curDst.y)
		{
			curDst.x += deltaDst.x;
			mapPos->x += stepDir->x;
			side = 0;
		}
		else
		{
			curDst.y += deltaDst.y;
			mapPos->y += stepDir->y;
			side = 1;
		}
		
		//A wall has been hit
		if (map[mapPos->x][mapPos->y] > 0)
			return side;
	}

	//TODO : If code goes here, it is a fatal error
	return -1;
}

int p_engine(game *g, play *p)
{

	//LOADING THIS WAY DOES NOT WORK ON WINDOWS
	//Todo : Fix map loading
/*
	//TEMP MAP LOADING
	static uint8_t **map = NULL;
	static map_t *metaMap = NULL;

	if (map == NULL)
	{
		metaMap = loadMap("resources/maps/test.map");
		if (metaMap == NULL){
			g->err.errorCode = ERROR_LOADMAP_FAILURE;
			g->err.type = ERROR_TYPE_ERRNO;
			g->err.isFatal = true;
			updateFileInfoError(g, __LINE__, __FILE__);
			onError(g);
		}
		map = metaMap->map;
	}
*/
	//Hardcoded map - to delete when map loading is finished
	uint8_t **map = malloc(sizeof(uint8_t *) * 10);
	for (int i = 0 ; i < 10 ; i++) {
		map[i] = malloc(sizeof(uint8_t) * 10);
		for (int j = 0 ; j < 10 ; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 9)
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
	map[2][2] = 1;
	map[3][2] = 1;


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

		//Direction of the ray (+1 or -1 on x and y axis)
		pos2d stepDir;


		//Raycater engine
		//Launching a ray, updating mapPos and returning the side of the wall hit
		int side = dda_raycast(p, map, &mapPos, &stepDir, &ray);


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
