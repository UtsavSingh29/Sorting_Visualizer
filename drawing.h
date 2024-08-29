#ifndef DRAWING_H
#define DRAWING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void drawArray(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size, bool sorted, int selectedIndex, int comparingIndex, bool reset);
void drawLegend(SDL_Renderer *renderer, TTF_Font *font);
void drawButtons(SDL_Renderer *renderer, TTF_Font *font);

#endif
