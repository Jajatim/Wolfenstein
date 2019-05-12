#include "play.h"

int p_update(game *g, play *p)
{
	(void)p;
	(void)g;

	//Moving forward
	if (g->kbd.alpha[g->actions.moveForward])
	//if (g->kbd.w) //TODO : delete when keyboard mapping finished
	{
		p->pos.x += p->moveSpeed * p->dir.x * p->updateTimer;
		p->pos.y += p->moveSpeed * p->dir.y * p->updateTimer;
	}

	//Moving backwards
	if (g->kbd.alpha[g->actions.moveBackward])
	//if (g->kbd.s) //TODO : delete when keyboard mapping finished
	{
		p->pos.x -= p->moveSpeed * p->dir.x * p->updateTimer;
		p->pos.y -= p->moveSpeed * p->dir.y * p->updateTimer;
	}

	//Rotating Right
	if (g->kbd.alpha[g->actions.turnRight])
	//if (g->kbd.d) //TODO : delete when keyboard mapping finished
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(-(p->rotSpeed * p->updateTimer)) - p->dir.y * sin(-(p->rotSpeed * p->updateTimer));
		p->dir.y = oldDirX * sin(-(p->rotSpeed * p->updateTimer)) + p->dir.y * cos(-(p->rotSpeed * p->updateTimer));
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(-(p->rotSpeed * p->updateTimer)) - p->plane.y * sin(-(p->rotSpeed * p->updateTimer));
		p->plane.y = oldPlaneX * sin(-(p->rotSpeed * p->updateTimer)) + p->plane.y * cos(-(p->rotSpeed * p->updateTimer));
	}

	//Rotating Left
	if (g->kbd.alpha[g->actions.turnLeft])
	//if (g->kbd.a) //TODO : delete when keyboard mapping finished
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(p->rotSpeed * p->updateTimer) - p->dir.y * sin(p->rotSpeed * p->updateTimer);
		p->dir.y = oldDirX * sin(p->rotSpeed * p->updateTimer) + p->dir.y * cos(p->rotSpeed * p->updateTimer);
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(p->rotSpeed * p->updateTimer) - p->plane.y * sin(p->rotSpeed * p->updateTimer);
		p->plane.y = oldPlaneX * sin(p->rotSpeed * p->updateTimer) + p->plane.y * cos(p->rotSpeed * p->updateTimer);
	}

	//Strafing Left
	if (g->kbd.alpha[g->actions.moveLeft])
	//if (g->kbd.q) //TODO : delete when keyboard mapping finished
	{
		p->pos.x -= p->dir.y * p->moveSpeed * p->updateTimer;
		p->pos.y -= -(p->dir.x) * p->moveSpeed * p->updateTimer;
	}

	//Strafing Right
	if (g->kbd.alpha[g->actions.moveRight])
	//if (g->kbd.e) //TODO : delete when keyboard mapping finished
	{
		p->pos.x += p->dir.y * p->moveSpeed * p->updateTimer;
		p->pos.y += -(p->dir.x) * p->moveSpeed * p->updateTimer;
	}

	return 1;
}
