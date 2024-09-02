
void drawArray(SDL_Renderer *renderer, TTF_Font *font, int *arr, int size, bool sorted, int selectedIndex, int comparingIndex, bool reset)
{
    int totalWidth = size * (50 + 10) - 10;
    int startX = (WINDOW_WIDTH - totalWidth) / 2;

    for (int idx = 0; idx < size; idx++)
    {
        SDL_Color color;
        SDL_Color textColor = {255, 255, 255, 255}; 
        if (reset)
        {
            color = (SDL_Color){255, 255, 255, 255}; 
        }
        else if (idx == selectedIndex)
        {
            color = (SDL_Color){0, 0, 255, 255}; 
        }
        else if (idx == comparingIndex)
        {
            color = (SDL_Color){255, 105, 180, 255}; 
        }
        else if (selectedIndex == 1 && idx == comparingIndex)
        {
            color = (SDL_Color){255, 255, 0, 255}; 
            textColor = (SDL_Color){0, 0, 0, 255}; 
        }
        else
        {
            color = sorted ? (SDL_Color){0, 255, 0, 255} : (SDL_Color){255, 0, 0, 255}; 
        }
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = {startX + idx * (50 + 10), WINDOW_HEIGHT / 2 - 50 / 2, 50, 50};
        SDL_RenderFillRect(renderer, &rect);
        char valueText[10];
        snprintf(valueText, sizeof(valueText), "%d", arr[idx]);
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, valueText, textColor);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        int textW = textSurface->w, textH = textSurface->h;
        SDL_Rect textRect = {rect.x + (rect.w - textW) / 2, rect.y + (rect.h - textH) / 2, textW, textH};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
}