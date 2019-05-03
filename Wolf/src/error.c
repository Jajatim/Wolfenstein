#include "generic.h"

const char *getErrorName(error_t error)
{
    const char *errorNames[] = {
        "SDL initalisation failed !" // ERROR_SDL_INIT_FAILURE
    };
    if (error.errorCode < COUNT_OF(errorNames)) {
        return errorNames[error.errorCode];
    } else {
        return NULL;
    }
    
}

const char *getErrorDescription(error_t error)
{
    static const char *errorDescriptions[] = {
        "error while initializing SDL" // ERROR_SDL_INIT_FAILURE
    };
    if (error.errorCode < COUNT_OF(errorDescriptions)) {
        return errorDescriptions[error.errorCode];
    } else {
        return NULL;
    }
    
}

void onFatalError(game *g)
{
    g_exit(g);
    // TO DO : Create a dialog box
}

void onError(game *g)
{
    printf("onError\n");
    if (g->err.name != NULL)
        free(g->err.name);
    printf("Hello 1\n");
    g->err.name = calloc(1, strlen(getErrorName(g->err)+1));
    if (g->err.name)
        strcpy(g->err.name,getErrorName(g->err));
    if (g->err.name != NULL)
        free(g->err.description);
    printf("Hello 2\n");
    g->err.description = calloc(1, strlen(getErrorDescription(g->err)+1));
    if (g->err.description != NULL)
        strcpy(g->err.description,getErrorDescription(g->err));
    printf("Hello 3\n");
    printf("======= New Error =======\n");
    printf("Error ID : %hhu\n", g->err.errorCode);
    printf("Error Name : %s\n", g->err.name);
    printf("Error Description : %s\n", g->err.description);
    printf("==========================\n");

    if (g->err.name) {
        onFatalError(g);
    }
}