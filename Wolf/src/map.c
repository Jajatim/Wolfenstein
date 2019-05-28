#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "map.h"

map_t *loadMap(const char *fileName){
    if (fileName == NULL)
        return NULL;
    
    FILE *mapFile = NULL;
    map_t *map = NULL;

    mapFile = fopen(fileName, "rb");

    if (mapFile == NULL)
        return NULL;

    map = calloc(1, sizeof(map_t));
    
    if (map == NULL){
        fclose(mapFile);
        return NULL;
    }
    
    fread(&map->version, sizeof(uint8_t), 1, mapFile);
    fread(&map->h, sizeof(uint8_t), 1, mapFile);
    fread(&map->w, sizeof(uint8_t), 1, mapFile);

    map->map = calloc(map->w, sizeof(uint8_t *));

    if (allocateMap(map, map->h, map->w) == NULL) {
        fclose(mapFile);
    }

    for(size_t i = 0; i < map->w; i++){
        fread(map->map[i], sizeof(uint8_t), map->h, mapFile);
    }
    
    fclose(mapFile);
    return map;
}

void freeMap(map_t *map){
    if (map->map != NULL) {
        for(size_t i = 0; i < map->w; i++){
            if (map->map[i] != NULL) {
                free(map->map[i]);
            }
        }
        free(map->map);
    }
    free(map);
}

//if the pointer is NULL, the function will allocate the map
map_t *allocateMap(map_t *map, uint8_t ySize, uint8_t xSize){
    if (map == NULL) {
        map = calloc(sizeof(map_t), 1);
        if (map != NULL) {
            return NULL;
        }
    }
    
    map->w = xSize;
    map->h = ySize;

    map->map = calloc(map->w, sizeof(uint8_t *));

    if (map->map == NULL) {
        freeMap(map);
        return NULL;
    }
    
    for(size_t i = 0; i < map->w; i++){
        map->map[i] = calloc(map->h, sizeof(uint8_t));
        if (map->map[i] == NULL) {
            freeMap(map);
            return NULL;
        }
    }

    return map;
}

_Bool saveMap(const char *fileName, map_t *map){
    if(fileName == NULL || map == NULL)
        return false;

    FILE *fileMap = NULL;
    fileMap = fopen(fileName, "wb");

    if (fileMap == NULL) {
        return false;
    }
    
    fwrite(&map->version, sizeof(uint8_t), 1, fileMap);
    fwrite(&map->h, sizeof(uint8_t), 1, fileMap);
    fwrite(&map->w, sizeof(uint8_t), 1, fileMap);

    for(size_t i = 0; i < map->w; i++){
        fwrite(map->map, sizeof(uint8_t), map->h, fileMap);
    }
    
    fclose(fileMap);
    return true;
}
