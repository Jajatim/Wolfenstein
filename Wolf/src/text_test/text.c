#include "text.h"

void init_text(game *g, text_t *text)
{
    //Loading the assets texture
	SDL_Surface *tmp = SDL_LoadBMP(TEXT_ASSETS_PATH);
	if (tmp == NULL) {
		printf("Text lib failed to load surface stuff and sucks\n");
		printf("%s\n", SDL_GetError());
        exit(1);
	}
    /*
    //Transparent pink
    SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
*/
    //Transforming to Texture
    text->textAsset = SDL_CreateTextureFromSurface(g->ren, tmp);

    //Surface is not needed anymore
	SDL_FreeSurface(tmp);

    //Checking the texture has been created
    if (text->textAsset == NULL) {
		printf("Text lib failed to load texture stuff and sucks\n");
		printf("%s\n", SDL_GetError());
        exit(1);
    }

    //Set the letter array
    for (int i = 0 ; i < 26 ; i++) {
        text->letters[i].x = i * 10;
        text->letters[i].y = 0;
        text->letters[i].w = 10;
        text->letters[i].h = 10;
    }
}

void print_str(game *g, text_t *text, char *str, SDL_Rect *pos, int flags)
{
    (void)flags;

    int size = (int)strlen(str);
    int letter_size = pos->w / size;

    for (int i = 0 ; i < size ; i++) {
        //Get letter id
        int letter_nb;
        letter_nb = str[i] - 'A';
        if (islower(str[i]))
            letter_nb = str[i] - 'a';
        
        //Checks if is a valid letter
        if (letter_nb < 0 || letter_nb >= 26)
            continue; //cause it is not a letter

        //Prints the letter
        SDL_Rect dst = {
            .x = letter_size * i,
            .y = 0,
            .w = letter_size,
            .h = pos->h
        };
        printf("Printing letter |%c| at pos %d %d with size %d %d\n"
        ,letter_nb + 'a', dst.x, dst.y, dst.w, dst.h);
        SDL_RenderCopy(g->ren, text->textAsset, &(text->letters[letter_nb]), &dst);
    }
}