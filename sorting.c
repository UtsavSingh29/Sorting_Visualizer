#include "sorting.h"
#include <stdio.h>

void resetArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

bool bubbleSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size)
{
    bool sorted = false;
    int comparingIndex = -1;
    int selectedIndex = -1;
    if (i < size - 1)
    {
        if (j < size - i - 1)
        {
            comparingIndex = j;
            selectedIndex = j + 1;
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
    return sorted;
}

bool selectionSortStep(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size)
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
    return sorted;
}
