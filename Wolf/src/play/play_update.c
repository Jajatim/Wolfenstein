#include "play.h"

int p_update(game *g, play *p)
{
	(void)p;
	(void)g;

	//Moving forward
	if (g->kbd.w)
	{
		p->pos.x += p->moveSpeed * p->dir.x * p->updateTimer;
		p->pos.y += p->moveSpeed * p->dir.y * p->updateTimer;
	}

	//Moving backwards
	if (g->kbd.s)
	{
		p->pos.x -= p->moveSpeed * p->dir.x * p->updateTimer;
		p->pos.y -= p->moveSpeed * p->dir.y * p->updateTimer;
	}

	//Rotating Right
	if (g->kbd.d)
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(-(p->rotSpeed * p->updateTimer)) - p->dir.y * sin(-(p->rotSpeed * p->updateTimer));
		p->dir.y = oldDirX * sin(-(p->rotSpeed * p->updateTimer)) + p->dir.y * cos(-(p->rotSpeed * p->updateTimer));
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(-(p->rotSpeed * p->updateTimer)) - p->plane.y * sin(-(p->rotSpeed * p->updateTimer));
		p->plane.y = oldPlaneX * sin(-(p->rotSpeed * p->updateTimer)) + p->plane.y * cos(-(p->rotSpeed * p->updateTimer));
	}

	//Rotating Left
	if (g->kbd.a)
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(p->rotSpeed * p->updateTimer) - p->dir.y * sin(p->rotSpeed * p->updateTimer);
		p->dir.y = oldDirX * sin(p->rotSpeed * p->updateTimer) + p->dir.y * cos(p->rotSpeed * p->updateTimer);
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(p->rotSpeed * p->updateTimer) - p->plane.y * sin(p->rotSpeed * p->updateTimer);
		p->plane.y = oldPlaneX * sin(p->rotSpeed * p->updateTimer) + p->plane.y * cos(p->rotSpeed * p->updateTimer);
	}

	//Strafing Left
	if (g->kbd.q)
	{
		p->pos.x -= p->dir.y * p->moveSpeed * p->updateTimer;
		p->pos.y -= -(p->dir.x) * p->moveSpeed * p->updateTimer;
	}

	//Strafing Right
	if (g->kbd.e)
	{
		p->pos.x += p->dir.y * p->moveSpeed * p->updateTimer;
		p->pos.y += -(p->dir.x) * p->moveSpeed * p->updateTimer;
	}

	return 1;
}
