#ifndef SORTING_H
#define SORTING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

extern int i, j, minIndex;

void resetArray(int *arr, int size);
bool bubbleSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size);
bool selectionSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size);

#endif
