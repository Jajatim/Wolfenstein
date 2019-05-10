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
		res = get_cfg_val(s, "\t00:");
		if (res) {
			g->screenW = atoi(res);
			continue;
		}
		res = get_cfg_val(s, "\t01:");
		if (res) {
			g->screenH = atoi(res);
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
