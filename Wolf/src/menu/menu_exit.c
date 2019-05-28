#include "menu.h"

int m_free(menu *m)
{
	SDL_DestroyTexture(m->menuAssets);
	m->menuAssets = NULL;
	return 1;
}