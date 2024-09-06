#include "../Header Files/drawing.h"
#include <stdio.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define BOX_WIDTH 50
#define BOX_HEIGHT 50
#define BOX_PADDING 10
#define STEP_DELAY 750 

void drawArray(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size, bool sorted, int selectedIndex, int comparingIndex, int selectedAlgorithm, int minIndex,bool reset)
{
    int totalWidth = size * (BOX_WIDTH + BOX_PADDING) - BOX_PADDING;
    int startX = (WINDOW_WIDTH - totalWidth) / 2;
    for (int idx = 0; idx < size; idx++)
    {
        SDL_Color color;
        SDL_Color textColor = {255, 255, 255, 255}; // Default text color white
        if (reset)
        {
            color = (SDL_Color){255, 255, 255, 255}; // White for reset
        }
        else if (idx == selectedIndex)
        {
            color = (SDL_Color){0, 0, 255, 255}; // Blue for selected
        }
        else if (idx == comparingIndex)
        {
            color = (SDL_Color){255, 105, 180, 255}; // Pink for comparing
        }
        else if (selectedAlgorithm == 1 && idx == minIndex) // Apply yellow only for Selection Sort ..............
        {
            color = (SDL_Color){255, 255, 0, 255}; // Yellow for minimum index
            textColor = (SDL_Color){0, 0, 0, 255}; // Black text for yellow box
        }
        else
        {
            color = sorted ? (SDL_Color){0, 255, 0, 255} : (SDL_Color){255, 0, 0, 255}; // Green for sorted, Red for unsorted
        }
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = {startX + idx * (BOX_WIDTH + BOX_PADDING), WINDOW_HEIGHT / 2 - BOX_HEIGHT / 2, BOX_WIDTH, BOX_HEIGHT};
        SDL_RenderFillRect(renderer, &rect);
        char valueText[10];
        snprintf(valueText, sizeof(valueText), "%d", arr[idx]);
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, valueText, textColor);
        if (textSurface == NULL)
        {
            fprintf(stderr, "Error creating text surface: %s\n", TTF_GetError());
            continue;
        }
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (textTexture == NULL)
        {
            fprintf(stderr, "Error creating text texture: %s\n", SDL_GetError());
            SDL_FreeSurface(textSurface);
            continue;
        }
        int textW = textSurface->w, textH = textSurface->h;
        SDL_Rect textRect = {rect.x + (rect.w - textW) / 2, rect.y + (rect.h - textH) / 2, textW, textH};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
}


void drawLegend(SDL_Renderer *renderer, TTF_Font *font)
{
    SDL_Rect legendRect = {WINDOW_WIDTH - 220, 20, 205, 165}; // Increased height to fit 5 items
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &legendRect);
    const char *labels[] = {"Final Position", "Wrong Position", "Selected", "Comparing", "Minimum Index"};
    SDL_Color colors[] = {
        {0, 255, 0, 255},     // Green for Final Position
        {255, 0, 0, 255},     // Red for Wrong Position
        {0, 0, 255, 255},     // Blue for Selected
        {255, 105, 180, 255}, // Pink for Comparing
        {255, 255, 0, 255}};  // Yellow for Minimum Index
    for (int i = 0; i < 5; i++)
    {
        SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
        SDL_Rect colorRect = {legendRect.x + 10, legendRect.y + 10 + i * 30, 20, 20};
        SDL_RenderFillRect(renderer, &colorRect);
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, labels[i], (SDL_Color){0, 0, 0, 255});
        if (textSurface == NULL)
        {
            fprintf(stderr, "Error creating text surface for legend: %s\n", TTF_GetError());
            continue;
        }
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (textTexture == NULL)
        {
            fprintf(stderr, "Error creating text texture for legend: %s\n", SDL_GetError());
            SDL_FreeSurface(textSurface);
            continue;
        }
        int textW = textSurface->w, textH = textSurface->h;
        SDL_Rect textRect = {colorRect.x + 30, colorRect.y, textW, textH};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
}

void drawButtons(SDL_Renderer *renderer, TTF_Font *font)
{
    // Define button colors and positions
    SDL_Color buttonColor = {0, 0, 0, 255};     // Black
    SDL_Color textColor = {255, 255, 255, 255}; // White
    // Button text
    const char *buttonLabels[] = {"Bubble Sort", "Selection Sort", "Reset"};
    SDL_Rect buttonRects[] = {
    {130, 400, 150, 40},  // Bubble Sort
    {320, 400, 165, 40},  // Selection Sort
    {530, 400, 100, 40}   // Reset
    };
    // Draw buttons
    for (int i = 0; i < 3; i++)
    {
        SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
        SDL_RenderFillRect(renderer, &buttonRects[i]);
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, buttonLabels[i], textColor);
        if (textSurface == NULL)
        {
            fprintf(stderr, "Error creating text surface for button: %s\n", TTF_GetError());
            continue;
        }
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (textTexture == NULL)
        {
            fprintf(stderr, "Error creating text texture for button: %s\n", SDL_GetError());
            SDL_FreeSurface(textSurface);
            continue;
        }
        int textW = textSurface->w, textH = textSurface->h;
        SDL_Rect textRect = {buttonRects[i].x + (buttonRects[i].w - textW) / 2, buttonRects[i].y + (buttonRects[i].h - textH) / 2, textW, textH};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
}
