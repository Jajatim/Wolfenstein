#include "generic.h"
#include "menu/menu.h"
#include "play/play.h"



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
	g->actions.moveForward = 'w' - 'a';
	g->actions.moveBackward = 's' - 'a';
	g->actions.moveLeft = 'q' - 'a';
	g->actions.moveRight = 'e' - 'a';
	g->actions.turnLeft = 'a' - 'a';
	g->actions.turnRight = 'd' - 'a';

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
		onError(g);
		return 1;
	}

	return 0;
}



int main(int argc, char **argv)
{
	argv[0][0] += argc * 0; //Making the compiler happy.

	game g = {};

	if (g_init(&g))
		fprintf(stderr, "Error at init\n"); //TODO : gestion err
	else
		menu_loop(&g);
	g_exit(&g);

	return EXIT_SUCCESS;
}
