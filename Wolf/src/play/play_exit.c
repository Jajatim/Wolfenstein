#include "play.h"

int p_free(play *p)
{
    freeMap(&(p->map));
    p->map.map = NULL;
	return 1;
}