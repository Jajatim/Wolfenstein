#include "generic.h"

const char *getErrorName(error_t error)
{
    const char *errorNames[] = {
        "undefined error !", // ERROR_UNDEFINED
        "SDL initalisation failed !", // ERROR_SDL_INIT_FAILURE
        "Window initalisation failed !", // ERROR_WINDOW_INIT_FAILURE
        "Renderer initalisation failed !", // ERROR_RENDERER_INIT_FAILURE
        "error loading an image !", // ERROR_LOADBMP_FAILURE
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
        NULL, // ERROR_UNDIFINED
        NULL, // ERROR_SDL_INIT_FAILURE
        NULL, // ERROR_WINDOW_INIT_FAILURE
        NULL, // ERROR_RENDERER_INIT_FAILURE
        NULL, // ERROR_LOADBMP_FAILURE
    };
    if (error.errorCode < COUNT_OF(errorDescriptions)) {
        return errorDescriptions[error.errorCode];
    } else {
        return NULL;
    }
    
}

void freeError(game *g)
{
    if(g->err.description != NULL)
        free(g->err.description);
    if (g->err.name)
        free(g->err.name);
}

void onFatalError(game *g)
{
    g_exit(g);
    // TODO : Create a dialog box
    exit(EXIT_FAILURE);
}

void onError(game *g)
{
    freeError(g);
    if (g->err.type == ERROR_TYPE_GAME){
        if (getErrorDescription(g->err) != NULL)
            g->err.description = calloc(1, strlen(getErrorDescription(g->err))+1);
        if (g->err.description != NULL)
            strcpy(g->err.description,getErrorDescription(g->err));
    } else if (g->err.type == ERROR_TYPE_SDL){
        g->err.description = calloc(1, strlen(SDL_GetError())+1);
        if (g->err.description)
            strcpy(g->err.description,SDL_GetError());
    } else if (g->err.type == ERROR_TYPE_ERRNO){
        // TODO : add errno support
    }
    if (getErrorName(g->err) != NULL)
        g->err.name = calloc(1, strlen(getErrorName(g->err))+1);
    if (g->err.name)
        strcpy(g->err.name,getErrorName(g->err));
    printf("======= New Error =======\n");
    printf("Error ID : 0x%hhX\n", g->err.errorCode);
    printf("Error Name : %s\n", g->err.name);
    printf("Error Description : %s\n", g->err.description);
    printf("==========================\n");

    if (g->err.isFatal) {
        onFatalError(g);
    }
}