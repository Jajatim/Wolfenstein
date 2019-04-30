#include "events.h"

int Events(User_Input *pUser_Input) {

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        //vérifications QUIT
        if (event.type == SDL_QUIT) return 0;

        //CLAVIER - TOUCHE ENFONCEE
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pUser_Input->pKeyboard->ArrowUp = 1;
                    break;
                case SDLK_LEFT:
                    pUser_Input->pKeyboard->ArrowLeft = 1;
                    break;
                case SDLK_DOWN:
                    pUser_Input->pKeyboard->ArrowDown = 1;
                    break;
                case SDLK_RIGHT:
                    pUser_Input->pKeyboard->ArrowRight = 1;
                    break;
                case SDLK_z:
                    pUser_Input->pKeyboard->Keyz = 1;
                    break;
                case SDLK_q:
                    pUser_Input->pKeyboard->Keyq = 1;
                    break;
                case SDLK_s:
                    pUser_Input->pKeyboard->Keys = 1;
                    break;
                case SDLK_d:
                    pUser_Input->pKeyboard->Keyd = 1;
                    break;
                case SDLK_SPACE:
                    pUser_Input->pKeyboard->KeySpace = 1;
                    break;
            }
        }
        //CLAVIER - TOUCHE RELACHEE
        else if (event.type == SDL_KEYUP) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pUser_Input->pKeyboard->ArrowUp = 0;
                    break;
                case SDLK_LEFT:
                    pUser_Input->pKeyboard->ArrowLeft = 0;
                    break;
                case SDLK_DOWN:
                    pUser_Input->pKeyboard->ArrowDown = 0;
                    break;
                case SDLK_RIGHT:
                    pUser_Input->pKeyboard->ArrowRight = 0;
                    break;
                case SDLK_z:
                    pUser_Input->pKeyboard->Keyz = 0;
                    break;
                case SDLK_q:
                    pUser_Input->pKeyboard->Keyq = 0;
                    break;
                case SDLK_s:
                    pUser_Input->pKeyboard->Keys = 0;
                    break;
                case SDLK_d:
                    pUser_Input->pKeyboard->Keyd = 0;
                    break;
                case SDLK_SPACE:
                    pUser_Input->pKeyboard->KeySpace = 0;
                    break;
            }
        }

        //SOURIS - MOUVEMENT
        if (event.type == SDL_MOUSEMOTION) {
            pUser_Input->pMouse->MouseX=event.motion.x;
            pUser_Input->pMouse->MouseY=event.motion.y;
        }
        //SOURIS - CLIC ENFONCE
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pUser_Input->pMouse->MouseLeftClic = 1;
                    break;
                case SDL_BUTTON_RIGHT:
                    pUser_Input->pMouse->MouseRightClic = 1;
                    break;
            }
        }
        //SOURIS - CLIC RELACHE
        else if (event.type == SDL_MOUSEBUTTONUP) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pUser_Input->pMouse->MouseLeftClic = 0;
                    break;
                case SDL_BUTTON_RIGHT:
                    pUser_Input->pMouse->MouseRightClic = 0;
                    break;
            }
        }

/*
        //Ecran redimensionné
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
            pScr->w = event.window.data1;
            pScr->h = event.window.data2;
            pScr->needResize = 1;
        }
*/

    }

    return 1;
}