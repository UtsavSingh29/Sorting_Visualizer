#include <stdio.h>
#include "../Header Files/Bubble_Selection.h"
#include "../Header Files/drawing.h"

void resetArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = originalArray[i];
    }
    i = 0;
    j = 0;
    minIndex = -1;  
    isSorting = false;  // Stop sorting after reset
    sorted = false; 
}

bool bubbleSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size, int speed)
{
    bool sorted = false;
    int selectedIndex = -1;
    int comparingIndex = -1;
    if (i < size - 1)
    {
        if (j < size - i - 1)
        {
            selectedIndex = j + 1;  // This is the element that will be compared with
            comparingIndex = j;     // This is the element currently being compared
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        else
        {
            j = 0;
            i++;
        }
    }
    else
    {
        sorted = true;
        i = 0;
        j = 0;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    drawArray(renderer, font, arr, size, sorted, selectedIndex, comparingIndex, selectedAlgorithm, minIndex, false);
    drawLegend(renderer, font);
    drawButtons(renderer, font);
    SDL_RenderPresent(renderer);
    SDL_Delay(speed);
    return sorted;
}
bool selectionSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size,int speed)
{
    bool sorted = false;
    if (i < size - 1)
    {
        if (j == i)
        {
            minIndex = i;
        }
        if (j < size)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            j++;
        }
        else
        {
            if (minIndex != i)
            {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
            i++;
            j = i;
        }
    }
    else
    {
        sorted = true;
        i = 0;
        j = 0;
        minIndex = -1;
    }
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    // Updated box size and position for better visibility of text
    int boxWidth = 50;
    int boxHeight = 50;
    int boxSpacing = 60; // Distance between boxes
    for (int k = 0; k < size; k++)
    {
        // Set colors based on sorting stage
        if (k == i)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue for current index
        }
        else if (k == minIndex && j != size)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow for minIndex
        }
        else if (k == j)
        {
            SDL_SetRenderDrawColor(renderer, 255, 105, 180, 255); // Pink for iterating index
        }
        else if (k < i)
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for sorted elements
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for unsorted elements
        }
        // Render the box for each element
        SDL_Rect rect = {107 + k * boxSpacing, 275, boxWidth, boxHeight}; // Adjusted size and position
        SDL_RenderFillRect(renderer, &rect);
        // Render the text inside each box
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%d", arr[k]);
        SDL_Color textColor = {0, 0, 0}; // Black text color
        SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, buffer, textColor);
        SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        int textWidth, textHeight;
        SDL_QueryTexture(message, NULL, NULL, &textWidth, &textHeight);
        SDL_Rect textRect = {107 + k * boxSpacing + (boxWidth - textWidth) / 2, 275 + (boxHeight - textHeight) / 2, textWidth, textHeight};
        SDL_RenderCopy(renderer, message, NULL, &textRect);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(message);
    }
    // Draw other elements
    drawLegend(renderer, font);
    drawButtons(renderer, font);
    SDL_RenderPresent(renderer);
    SDL_Delay(speed);
    return sorted;
    
}