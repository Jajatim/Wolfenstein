#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include <ctype.h>
#include "../generic.h"

#define TEXT_ASSETS_PATH "src/text_test/letters_img.bmp"

typedef struct text_t {
    SDL_Texture *textAsset;
    SDL_Rect letters[26];
} text_t;

void init_text(game *g, text_t *text);
void print_str(game *g, text_t *text, char *str, SDL_Rect *pos, int flags);

#endif //TEXT_H_INCLUDED