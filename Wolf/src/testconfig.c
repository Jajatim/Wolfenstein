#include "generic.h"


#define CFG_PATH "./config.cfg"


/* ----- PART 1 : VIDEO INFORMATIONS ----- */

#define CFG_FILE_0 \
	"[0:VIDEO]\n"\
	"\t000:SCREEN_WIDTH=%hd\n"\
	"\t001:SCREEN_HEIGHT=%hd\n"\
	"\n"

#define CFG_FILE_ARGS_0_W \
	g->screenW, g->screenH

#define CFG_FILE_ARGS_0_R \
	&g->screenW, &g->screenH


/* ----- PART 2 : KEYBOARD MAPPING (WITH SDL2 KEYCODES) ----- */

#define CFG_FILE_1 \
	"[1:KEYBOARD MAPPING]\n"\
	"\t100:MOVE_FORWARD=%d\n"\
	"\t101:MOVE_BACKWARD=%d\n"\
	"\t102:MOVE_LEFT=%d\n"\
	"\t103:MOVE_RIGHT=%d\n"\
	"\t104:TURN_LEFT=%d\n"\
	"\t105:TURN_RIGHT=%d\n"\
	"\n"

#define CFG_FILE_ARGS_1_W \
	g->actions.moveForward, \
	g->actions.moveBackward, \
	g->actions.moveLeft, \
	g->actions.moveRight, \
	g->actions.turnLeft, \
	g->actions.turnRight

#define CFG_FILE_ARGS_1_R \
	&g->actions.moveForward, \
	&g->actions.moveBackward, \
	&g->actions.moveLeft, \
	&g->actions.moveRight, \
	&g->actions.turnLeft, \
	&g->actions.turnRight



static int write_cfg(game *g)
{
	//Creates a new file (deletes the current one if there was one)
	FILE *cfg = fopen(CFG_PATH, "w+");
	if (cfg == NULL) {
		fprintf(stderr,"Could not create config file\n");
		exit(1); //TODO : Error handling
	}

	//Printing config infos
	fprintf(cfg, CFG_FILE_0, CFG_FILE_ARGS_0_W);
	fprintf(cfg, CFG_FILE_1, CFG_FILE_ARGS_1_W);

	fclose(cfg);
	return 1;
}


int read_cfg(game *g, FILE *cfg)
{
	//Reading config infos
	fscanf(cfg, CFG_FILE_0, CFG_FILE_ARGS_0_R);
	fscanf(cfg, CFG_FILE_1, CFG_FILE_ARGS_1_R);

	return 1;
}


int get_cfg(game *g)
{
	FILE *cfg = NULL;

	//Check if config file already exists, if not creates it
	cfg = fopen(CFG_PATH, "r+");
	if (cfg != NULL) {
		read_cfg(g, cfg);
		fclose(cfg);
	}
	else
		write_cfg(g);

	return 1;
}
