#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include "generic.h"

const char *getErrorName(error_t error);
const char *getErrorDescription(error_t error);
void onError(game *g);
void updateFileInfoError(game *g, uint16_t fileLine, char *fileName);

#endif //ERROR_H_INCLUDED
