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
			"[VIDEO]\n"						//VIDEO OPTIONS
			"\t00:SCREEN_WIDTH=%d\n"			//SCREEN WIDTH
			"\t01:SCREEN_HEIGHT=%d\n"			//SCREEN HEIGHT

			, g->screenW, g->screenH);		//variables

	fclose(cfg);
	return 1;
}


int read_cfg(game *g, FILE *cfg)
{
	char s[BUFSIZE];
	while (fgets(s, BUFSIZE, cfg)) {
		if (!strncmp(s, "\t00:", 4)) {
			int i = 4;
			while (s[i] != '=')
				i++;
			i++;
			g->screenW = atoi(&(s[i]));
		}
		if (!strncmp(s, "\t01:", 4)) {
			int i = 4;
			while (s[i] != '=')
				i++;
			i++;
			g->screenH = atoi(&(s[i]));
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
