#include "generic.h"


#define BUFSIZE 1024
#define CFG_PATH "./config.cfg"


static int save_cfg(game *g)
{
	//Creates a new file (deletes the current one if there was one)
	FILE *cfg = fopen(CFG_PATH, "w+");
	if (cfg == NULL) {
		fprintf(stderr,"Could not create config file\n");
		exit(1); //TODO : Error handling
	}

	//TODO : optimize, but how ?
	//Fills file with every config info
	fprintf(cfg,
			"[0:VIDEO]\n"						//VIDEO OPTIONS
			"\t000:SCREEN_WIDTH=%d\n"			//SCREEN_WIDTH
			"\t001:SCREEN_HEIGHT=%d\n"			//SCREEN_HEIGHT
			"\n"

			"[1:KEYBOARD MAPPING]\n"			//KEYBOARD MAPPING
			"\t100:MOVE_FORWARD=%c\n"			//MOVE_FORWARD
			"\t101:MOVE_BACKWARD=%c\n"			//MOVE_BACKWARD
			"\t102:MOVE_LEFT=%c\n"				//MOVE_LEFT
			"\t103:MOVE_RIGHT=%c\n"				//MOVE_RIGHT
			"\t104:TURN_LEFT=%c\n"				//TURN_LEFT
			"\t105:TURN_RIGHT=%c\n"				//TURN_RIGHT

			//Variables 0:VIDEO
			, g->screenW, g->screenH

			//Variables 1:KEYBOARD MAPPING
			, g->actions.moveForward+'a', g->actions.moveBackward+'a', g->actions.moveLeft+'a'
			, g->actions.moveRight+'a', g->actions.turnLeft+'a', g->actions.turnRight+'a'
			);

	fclose(cfg);
	return 1;
}


char *get_cfg_val(char *s, const char *tag)
{
	int tagSize = (int)strlen(tag);
	if (!strncmp(s, tag, tagSize)) {
		int i = tagSize;
		while (s[i] != '=')
			i++;
		i++;
		return &(s[i]);
	}
	return NULL;
}


int read_cfg(game *g, FILE *cfg)
{
	char *res;
	char s[BUFSIZE];

	while (fgets(s, BUFSIZE, cfg)) {
		res = get_cfg_val(s, "\t000:");
		if (res) {
			g->screenW = atoi(res);
			continue;
		}
		res = get_cfg_val(s, "\t001:");
		if (res) {
			g->screenH = atoi(res);
			continue;
		}

		
		res = get_cfg_val(s, "\t100:");
		if (res) {
			g->actions.moveForward = res[0] - 'a';
			continue;
		}
		res = get_cfg_val(s, "\t101:");
		if (res) {
			g->actions.moveBackward = res[0] - 'a';
			continue;
		}
		res = get_cfg_val(s, "\t102:");
		if (res) {
			g->actions.moveLeft = res[0] - 'a';
			continue;
		}
		res = get_cfg_val(s, "\t103:");
		if (res) {
			g->actions.moveRight = res[0] - 'a';
			continue;
		}
		res = get_cfg_val(s, "\t104:");
		if (res) {
			g->actions.turnLeft = res[0] - 'a';
			continue;
		}
		res = get_cfg_val(s, "\t105:");
		if (res) {
			g->actions.turnRight = res[0] - 'a';
			continue;
		}
	}
	return 1;
}


int get_cfg(game *g)
{
	FILE *cfg = NULL;

	//Check if config file already exists, if not creates it
	cfg = fopen(CFG_PATH, "r+");
	if (cfg == NULL)
		save_cfg(g);
	else
		read_cfg(g, cfg);

	if (cfg != NULL)
		fclose(cfg);
	return 1;
}
