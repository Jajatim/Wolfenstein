#include "play.h"

int p_init(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;

	//TODO : move somewhere else ? Or map really belongs to play struct ?
	//Map loading
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
	p->map.version = 0;
	p->map.h = 10;
	p->map.w = 10;
	p->map.map = malloc(sizeof(uint8_t *) * 10);
	for (int i = 0 ; i < 10 ; i++) {
		p->map.map[i] = malloc(sizeof(uint8_t) * 10);
		for (int j = 0 ; j < 10 ; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 9)
				p->map.map[i][j] = 1;
			else
				p->map.map[i][j] = 0;
		}
	}
	p->map.map[2][2] = 1;
	p->map.map[3][2] = 1;
	
	//Player infos
	p->moveSpeed = 0.002;
	p->rotSpeed = 0.002;
	p->pos = (vec2) {
		.x = 8.0,
		.y = 8.0
	};
	p->dir = (vec2) {
		.x = -1.0,
		.y = 0.0
	};
	p->plane = (vec2) {
		.x = 0.0,
		.y = 0.66
	};

	return 1;
}
