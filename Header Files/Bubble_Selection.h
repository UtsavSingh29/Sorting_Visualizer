#ifndef SORTING_H
#define SORTING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

extern int i, j, minIndex;         // Declare the indices used in sorting algorithms
extern int selectedAlgorithm;   
extern bool isSorting;
extern bool sorted;
extern int *originalArray;   // Declare the variable for selected sorting algorithm

void resetArray(int *arr, int size);
bool bubbleSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size, int speed);
bool selectionSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size, int speed);

#endif // SORTING_H
