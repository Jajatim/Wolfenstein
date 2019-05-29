#include "generic.h"
#include "menu/menu.h"
#include "play/play.h"

game *getGame(game *toSet){
	static game *g = NULL;
	if (toSet != NULL){
		g = toSet;
	}
	return g;
}

static void g_exit(game *g)
{
	//Freeing the SDL window
	if (g->win != NULL){
		SDL_DestroyWindow(g->win);
		g->win = NULL;
	}

	//Freeing the SDL renderer
	if (g->ren != NULL){
		SDL_DestroyRenderer(g->ren);
		g->ren = NULL;
	}

	//General SDL exit
	SDL_Quit();
}

//TODO : clean up config loading when done
int get_cfg(game *g);

static int g_init(game *g)
{
	//Variables init
	g->screenW = 800; //TODO : Load from config file ?
	g->screenH = 600; //TODO : Load from config file ?
	g->status = INIT;
	g->win = NULL;
	g->ren = NULL;

	//actions init - wasd by default
	g->actions.moveForward = SDLK_w;
	g->actions.moveBackward = SDLK_s;
	g->actions.moveLeft = SDLK_q;
	g->actions.moveRight = SDLK_e;
	g->actions.turnLeft = SDLK_a;
	g->actions.turnRight = SDLK_d;

	//Get config from file
	get_cfg(g);

	//Keyboard & mouse init
	memset((void *)&(g->kbd), 0, sizeof(keyboard));
	memset((void *)&(g->mse), 0, sizeof(mouse));

	//General Init SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		fprintf(stderr, "SDL initialisation failed: %s\n",SDL_GetError());
		g->err.errorCode = ERROR_SDL_INIT_FAILURE;
		g->err.type = ERROR_TYPE_SDL;
		g->err.isFatal = true;
		updateFileInfoError(g, __LINE__, __FILE__);
		onError(g);
		return 1;
	}

	//Creating the SDL window
	g->win = SDL_CreateWindow(WIN_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, g->screenW, g->screenH, SDL_WINDOW_SHOWN);
	if (!g->win) {
		fprintf(stderr, "Window creation failed: %s\n",SDL_GetError());
		g->err.errorCode = ERROR_WINDOW_INIT_FAILURE;
		g->err.type = ERROR_TYPE_SDL;
		g->err.isFatal = true;
		updateFileInfoError(g, __LINE__, __FILE__);
		onError(g);
		return 1;
	}

	//Creating the SDL renderer
	g->ren = SDL_CreateRenderer(g->win, -1, 0);
	if (!g->ren) {
		fprintf(stderr, "Renderer creation failed: %s\n",SDL_GetError());
		g->err.errorCode = ERROR_RENDERER_INIT_FAILURE;
		g->err.type = ERROR_TYPE_SDL;
		g->err.isFatal = true;
		updateFileInfoError(g, __LINE__, __FILE__);
		onError(g);
		return 1;
	}

	return 0;
}

//TODO : clean up
void change_state(game *g, menu *m, play *p); //state changer test
int game_loop(game *g, menu *m, play *p); //new loop test

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	game g = {};
	menu m;
	play p;

	if (g_init(&g))
		fprintf(stderr, "Error at init\n"); //TODO : gestion err
	else {
		getGame(&g);// set pointer
		setupSignalHandler();
		//menu_loop(&g);

		//Starting with main menu
		g.status = MAIN_MENU;
		change_state(&g, &m, &p);
		game_loop(&g, &m, &p);
	}
	g_exit(&g);

	return EXIT_SUCCESS;
}
