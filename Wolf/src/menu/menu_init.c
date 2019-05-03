#include "menu.h"
#include "../utils/utils.h"

int m_init(game *g, menu *m)
{
	(void)g;
	(void)m;
	
	//Init variables
	m->deltaTime = 0;
	m->renderTimer = 0;

	//Init timer (need to init the static var)
	timer(m->deltaTime);
	
	return 1;
}
