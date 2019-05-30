#include "play.h"

int p_update(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;
	
	//Moving forward
	if (check_action(g, g->actions.moveForward))
	{
		double movX = p->moveSpeed * p->dir.x * g->updateDelta;
		double movY = p->moveSpeed * p->dir.y * g->updateDelta;

		if (p->map.map[(int)(p->pos.x + movX)][(int)p->pos.y] == 0)
			p->pos.x += movX;
		if (p->map.map[(int)p->pos.x][(int)(p->pos.y + movY)] == 0)
			p->pos.y += movY;
	}

	//Moving backwards
	if (check_action(g, g->actions.moveBackward))
	{
		double movX = p->moveSpeed * p->dir.x * g->updateDelta;
		double movY = p->moveSpeed * p->dir.y * g->updateDelta;

		if (p->map.map[(int)(p->pos.x - movX)][(int)p->pos.y] == 0)
			p->pos.x -= movX;
		if (p->map.map[(int)p->pos.x][(int)(p->pos.y - movY)] == 0)
			p->pos.y -= movY;
	}

	//Rotating Right
	if (check_action(g, g->actions.turnRight))
	{
		const double calcAngle = -(p->rotSpeed * g->updateDelta);
		const double calcCos = cos(calcAngle);
		const double calcSin = sin(calcAngle);

		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * calcCos - p->dir.y * calcSin;
		p->dir.y = oldDirX * calcSin + p->dir.y * calcCos;
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * calcCos - p->plane.y * calcSin;
		p->plane.y = oldPlaneX * calcSin + p->plane.y * calcCos;
	}

	//Rotating Left
	if (check_action(g, g->actions.turnLeft))
	{
		const double calcAngle = p->rotSpeed * g->updateDelta;
		const double calcCos = cos(calcAngle);
		const double calcSin = sin(calcAngle);

		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * calcCos - p->dir.y * calcSin;
		p->dir.y = oldDirX * calcSin + p->dir.y * calcCos;
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * calcCos - p->plane.y * calcSin;
		p->plane.y = oldPlaneX * calcSin + p->plane.y * calcCos;
	}

	//Strafing Left
	if (check_action(g, g->actions.moveLeft))
	{
		double movX = p->dir.y * p->moveSpeed * g->updateDelta;
		double movY = -(p->dir.x) * p->moveSpeed * g->updateDelta;

		if (p->map.map[(int)(p->pos.x - movX)][(int)p->pos.y] == 0)
			p->pos.x -= movX;
		if (p->map.map[(int)p->pos.x][(int)(p->pos.y - movY)] == 0)
			p->pos.y -= movY;
	}

	//Strafing Right
	if (check_action(g, g->actions.moveRight))
	{
		double movX = p->dir.y * p->moveSpeed * g->updateDelta;
		double movY = -(p->dir.x) * p->moveSpeed * g->updateDelta;

		if (p->map.map[(int)(p->pos.x + movX)][(int)p->pos.y] == 0)
			p->pos.x += movX;
		if (p->map.map[(int)p->pos.x][(int)(p->pos.y + movY)] == 0)
			p->pos.y += movY;
	}

	return 1;
}
