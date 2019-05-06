#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include "generic.h"

const char *getErrorName(error_t error);
const char *getErrorDescription(error_t error);
void onError(game *g);

#endif //ERROR_H_INCLUDED
