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
int arraySize ;
int speed = STEP_DELAY;
bool isSorting = false;
int selectedAlgorithm = -1;
bool sorted = false;
int i = 0, j = 0, minIndex = 0;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    if (TTF_Init() == -1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        return -1;
    }
    // Ask user for array size
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);
    array = (int *)malloc(arraySize * sizeof(int));
    originalArray = (int *)malloc(arraySize * sizeof(int));
    // Ask user for array elements
    printf("Enter %d elements of the array: ", arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &array[i]);
        originalArray[i] = array[i];
    }
    SDL_Window *window = SDL_CreateWindow("Sorting Algorithm Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return -1;
    }
    TTF_Font *font = TTF_OpenFont("./Font/arial.ttf", 24);
    if (!font)
    {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        return -1;
    }
    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                // Check if Bubble Sort button was clicked
                if (x >= 130 && x <= 280 && y >= 400 && y <= 440)
                {
                    selectedAlgorithm = 0; 
                    isSorting = true;
                    sorted = false;
                    i = 0;
                    j = 0;
                    minIndex = -1;
                }
                else if (x >= 320 && x <= 485 && y >= 400 && y <= 440)
                {
                    selectedAlgorithm = 1;
                    isSorting = true;
                    sorted = false;
                    i = 0;
                    j = 0;
                    minIndex = -1;
                }
                else if (x >= 530 && x <= 630 && y >= 400 && y <= 440)
                {
                    resetArray(array, arraySize);
                    sorted = false;
                    i = 0;
                    j = 0;
                    minIndex = -1;
                }
                else if (x >= 640 && x <= 740 && y >= 400 && y <= 440)
                {
                    isSorting=false;
                }
            }
        }
        if (isSorting && !sorted)
        {
            if (selectedAlgorithm == 0)
            {
                sorted = bubbleSortStep(renderer, font, array, arraySize,speed);
            }
            else if (selectedAlgorithm == 1)
            {
                sorted = selectionSortStep(renderer, font, array, arraySize,speed);
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

