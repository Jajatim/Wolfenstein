#include "play.h"

int p_free(play *p)
{
    freeMap(&(p->map));
    p->map = NULL;
	return 1;
}