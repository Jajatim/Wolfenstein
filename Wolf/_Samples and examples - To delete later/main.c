//Standard libraries
#include <stdlib.h>
#include <stdio.h>

//Other libraries
#include "include/SDL2/SDL.h"
//#include "include/SDL2/SDL_mixer.h"

//Local includes
#include "define.h"
#include "struct.h"
#include "timer.h"
#include "events.h"


int main(int argc, char** argv) {
    
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        fprintf(stderr, "ERROR : SDL initialization failed.");
        exit(EXIT_FAILURE);
    }

/*
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        fprintf(stderr, "ERROR : SDL_Mixer initialization failed.");
        return -1;
    };
*/

    //Init Window
    SDL_Window *pWindow = NULL;
    pWindow = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

    if(pWindow == NULL){
        fprintf(stderr, "ERROR : Window creation failed.");
        exit(EXIT_FAILURE);
    }

    //Init Renderer
    SDL_Renderer *pRenderer = NULL;
    pRenderer = SDL_CreateRenderer(pWindow, -1 , 0);

    if(pRenderer == NULL){
        fprintf(stderr, "ERROR : Renderer creation failed.");
        exit(EXIT_FAILURE);
    }

    //Main variables
    Mouse mouse = {0};
    //Mouse *pMouse = &mouse;
    Keyboard keyboard = {0};
    //Keyboard *pKeyboard = &keyboard;
    User_Input user_input;
    user_input.pMouse = &mouse;
    user_input.pKeyboard = &keyboard;
    User_Input *pUser_Input = &user_input;
    Uint32 deltaTime = 0;
    Uint32 updateTimer = UPDATE_TIMER;
    Uint32 renderTimer = RENDER_TIMER;

    //Local variables
    int loop = 1;
    int gamestate = 0;

    //Main Loop
    while (loop) {
        deltaTime = Timer(deltaTime);
        loop = Events(pUser_Input);

        updateTimer += deltaTime;
        if (updateTimer >= UPDATE_TIMER) {
            Update(pUser_Input, deltaTime, gamestate);
            updateTimer = 0;
        }
        
        renderTimer += deltaTime;
        if (renderTimer >= RENDER_TIMER) {
            Render(gamestate);
            renderTimer = 0;
        }
        SDL_Delay(1);
    }

    //End program
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return EXIT_SUCCESS;
}