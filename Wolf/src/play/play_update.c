#include "play.h"

int p_update(game *g, menu *m, play *p)
{
	(void)g;
	(void)m;
	(void)p;
	
	//Moving forward
	if (check_action(g, g->actions.moveForward))
	{
		p->pos.x += p->moveSpeed * p->dir.x * g->updateDelta;
		p->pos.y += p->moveSpeed * p->dir.y * g->updateDelta;
	}

	//Moving backwards
	if (check_action(g, g->actions.moveBackward))
	{
		p->pos.x -= p->moveSpeed * p->dir.x * g->updateDelta;
		p->pos.y -= p->moveSpeed * p->dir.y * g->updateDelta;
	}

	//Rotating Right
	if (check_action(g, g->actions.turnRight))
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(-(p->rotSpeed * g->updateDelta)) - p->dir.y * sin(-(p->rotSpeed * g->updateDelta));
		p->dir.y = oldDirX * sin(-(p->rotSpeed * g->updateDelta)) + p->dir.y * cos(-(p->rotSpeed * g->updateDelta));
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(-(p->rotSpeed * g->updateDelta)) - p->plane.y * sin(-(p->rotSpeed * g->updateDelta));
		p->plane.y = oldPlaneX * sin(-(p->rotSpeed * g->updateDelta)) + p->plane.y * cos(-(p->rotSpeed * g->updateDelta));
	}

	//Rotating Left
	if (check_action(g, g->actions.turnLeft))
	{
		double oldDirX = p->dir.x;
		p->dir.x = p->dir.x * cos(p->rotSpeed * g->updateDelta) - p->dir.y * sin(p->rotSpeed * g->updateDelta);
		p->dir.y = oldDirX * sin(p->rotSpeed * g->updateDelta) + p->dir.y * cos(p->rotSpeed * g->updateDelta);
		double oldPlaneX = p->plane.x;
		p->plane.x = p->plane.x * cos(p->rotSpeed * g->updateDelta) - p->plane.y * sin(p->rotSpeed * g->updateDelta);
		p->plane.y = oldPlaneX * sin(p->rotSpeed * g->updateDelta) + p->plane.y * cos(p->rotSpeed * g->updateDelta);
	}

	//Strafing Left
	if (check_action(g, g->actions.moveLeft))
	{
		p->pos.x -= p->dir.y * p->moveSpeed * g->updateDelta;
		p->pos.y -= -(p->dir.x) * p->moveSpeed * g->updateDelta;
	}

	//Strafing Right
	if (check_action(g, g->actions.moveRight))
	{
		p->pos.x += p->dir.y * p->moveSpeed * g->updateDelta;
		p->pos.y += -(p->dir.x) * p->moveSpeed * g->updateDelta;
	}

	return 1;
}
