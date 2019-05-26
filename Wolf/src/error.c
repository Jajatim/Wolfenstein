#include "generic.h"

#if defined(__unix__)

int getSignalNumber(int signal){
    static int number = -1;
    if (signal != -1)
        number = signal;
    return number;
}

void sighandler(int signum) {
    game *g = NULL;
    g = getGame(NULL);
    getSignalNumber(signum);
    int notFatalSignals[] = {
        SIGINT // unkillable with ^C x)
    };
    for (size_t i = 0; i < COUNT_OF(notFatalSignals); i++){
        if (signum == notFatalSignals[i]){
            g->err.errorCode = ERROR_SIGNAL;
            g->err.type = ERROR_TYPE_GAME;
            g->err.isFatal = false;
            updateFileInfoError(g, __LINE__, __FILE__);
            onError(g);
            return;
        }
    }
    g->err.errorCode = ERROR_SIGNAL;
    g->err.type = ERROR_TYPE_GAME;
    g->err.isFatal = true;
    updateFileInfoError(g, __LINE__, __FILE__);
    onError(g);
    return;
}

void setupSignalHandler(){
    for (size_t i = 2; i < 32; i++){
        signal(i, sighandler);
    }
    
}

#else

void setupSignalHandler(){}

int getSignalNumber(int signal){
    return 0;
}

void sighandler(int signum) {}

#endif

const char *getErrorName(error_t error)
{
    const char *errorNames[] = {
        "Undefined error !", // ERROR_UNDEFINED
        "SDL initalisation failed !", // ERROR_SDL_INIT_FAILURE
        "Window initalisation failed !", // ERROR_WINDOW_INIT_FAILURE
        "Renderer initalisation failed !", // ERROR_RENDERER_INIT_FAILURE
        "Error loading an image !", // ERROR_LOADBMP_FAILURE
        "Error while loading a texture !",// ERROR_LOADTEXTURE_FAILURE
        "Error while loading the map !", // ERROR_LOADMAP_FAILURE
        "Detected signal" // ERROR_SIGNAL
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
        NULL, // ERROR_LOADTEXTURE_FAILURE
        NULL, // ERROR_LOADMAP_FAILURE
        "signal recevied", // ERROR_SIGNAL
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
	(void)g;

    char message[2048] = {};

    if (g->err.errorCode != ERROR_SIGNAL){
        sprintf(message,
        "name        : %s\n"
        "description : %s\n"
        "error code  : 0x%X\n"
        "file        : %s\n"
        "line        : %u\n"
        , g->err.name, g->err.description, g->err.errorCode, g->err.fileName, g->err.fileLine);
    } else {
        sprintf(message,
        "name        : %s\n"
        "description : %s ( %d )\n"
        "error code  : 0x%X\n"
        "file        : %s\n"
        "line        : %u\n"
        , g->err.name, g->err.description, getSignalNumber(-1), g->err.errorCode, g->err.fileName, g->err.fileLine);
    }
    
    
    SDL_ShowSimpleMessageBox(
        SDL_MESSAGEBOX_ERROR,
        "FATAL ERROR !",
        message,
        g->win
    );
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
        g->err.description = calloc(1, strlen(strerror(errno))+1);
        if (g->err.description)
            strcpy(g->err.description,strerror(errno));
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

void updateFileInfoError(game *g, uint16_t fileLine, char *fileName){
    g->err.fileLine = fileLine;
    if (g->err.fileName != NULL)
        free(g->err.fileName);
    g->err.fileName = calloc(1, strlen(fileName)+1);
    if (g->err.fileName != NULL)
        strcpy(g->err.fileName, fileName);
}