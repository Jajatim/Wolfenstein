#include "utils.h"

/* Checks if a dot and a rectangle collide
 *  returns 1 if yes, 0 if not
*/
int collide_dot_rect(pos2d dot, SDL_Rect rect)
{
	if (dot.x < rect.x)
		return 0;
	if (dot.y < rect.y)
		return 0;
	if (dot.x > rect.x + rect.w)
		return 0;
	if (dot.y > rect.y + rect.h)
		return 0;
	return 1;
}
