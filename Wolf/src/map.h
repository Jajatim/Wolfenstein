#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include <stdbool.h>

typedef struct map {
    uint8_t version;
    uint8_t ySize;
    uint8_t xSize;
    uint8_t **map;
} map_t;

map_t *allocateMap(map_t *map, uint8_t ySize, uint8_t xSize);
_Bool saveMap(const char *fileName, map_t *map);
map_t *loadMap(const char *fileName);
void freeMap(map_t *map);

#endif
