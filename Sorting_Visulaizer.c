#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./Header Files/Bubble_Selection.h"
#include "./Header Files/drawing.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define STEP_DELAY 750 

int *array = NULL;
int *originalArray = NULL;
int arraySize = 10;
int speed = STEP_DELAY;
bool isSorting = false;
int selectedAlgorithm = -1;
bool sorted = false;
int i = 0, j = 0, minIndex = 0;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow("Sorting Visualizer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);
    if (font == NULL)
    {
        fprintf(stderr, "Error loading font: %s\n", TTF_GetError());
        return 1;
    }
    array = malloc(arraySize * sizeof(int));
    originalArray = malloc(arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % 100;
    }
    resetArray(array, arraySize);
    memcpy(originalArray, array, arraySize * sizeof(int));
    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= 130 && x <= 280 && y >= 400 && y <= 440)
                {
                    selectedAlgorithm = 0; 
                    isSorting = true;
                    sorted = false;
                }
                else if (x >= 320 && x <= 485 && y >= 400 && y <= 440)
                {
                    selectedAlgorithm = 1;
                    isSorting = true;
                    sorted = false;
                }
                else if (x >= 530 && x <= 630 && y >= 400 && y <= 440)
                {
                    resetArray(array, arraySize);
                    sorted = false;
                    i = 0;
                    j = 0;
                    minIndex = -1;
                }
            }
        }
        if (isSorting)
        {
            if (selectedAlgorithm == 0)
            {
                sorted = bubbleSortStep(renderer, font, array, arraySize,speed);
            }
            else if (selectedAlgorithm == 1)
            {
                sorted = selectionSortStep(renderer, font, array, arraySize,speed);
            }
            if (sorted)
            {
                isSorting = false;
            }
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            drawArray(renderer, font, array, arraySize, sorted, -1, -1,selectedAlgorithm,minIndex, false);
            drawLegend(renderer, font);
            drawButtons(renderer, font);
            SDL_RenderPresent(renderer);
        }
    }
    free(array);
    free(originalArray);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
