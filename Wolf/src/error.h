#ifndef ERROR_H
#define ERROR_H

#include "generic.h"

const char *getErrorName(error_t error);
const char *getErrorDescription(error_t error);
void onError(game *g);

#endif