void drawButtons(SDL_Renderer *renderer, TTF_Font *font)
{
    SDL_Color textColor = {255, 255, 255, 255};
    const char *bubbleSortText = "Bubble Sort";
    SDL_Surface *bubbleSortSurface = TTF_RenderText_Solid(font, bubbleSortText, textColor);
    SDL_Texture *bubbleSortTexture = SDL_CreateTextureFromSurface(renderer, bubbleSortSurface);
    SDL_Rect bubbleSortRect = {130, 400, bubbleSortSurface->w, bubbleSortSurface->h};
    SDL_RenderCopy(renderer, bubbleSortTexture, NULL, &bubbleSortRect);
    SDL_FreeSurface(bubbleSortSurface);
    SDL_DestroyTexture(bubbleSortTexture);

    const char *selectionSortText = "Selection Sort";
    SDL_Surface *selectionSortSurface = TTF_RenderText_Solid(font, selectionSortText, textColor);
    SDL_Texture *selectionSortTexture = SDL_CreateTextureFromSurface(renderer, selectionSortSurface);
    SDL_Rect selectionSortRect = {320, 400, selectionSortSurface->w, selectionSortSurface->h};
    SDL_RenderCopy(renderer, selectionSortTexture, NULL, &selectionSortRect);
    SDL_FreeSurface(selectionSortSurface);
    SDL_DestroyTexture(selectionSortTexture);

    const char *resetText = "Reset";
    SDL_Surface *resetSurface = TTF_RenderText_Solid(font, resetText, textColor);
    SDL_Texture *resetTexture = SDL_CreateTextureFromSurface(renderer, resetSurface);
    SDL_Rect resetRect = {530, 400, resetSurface->w, resetSurface->h};
    SDL_RenderCopy(renderer, resetTexture, NULL, &resetRect);
    SDL_FreeSurface(resetSurface);
    SDL_DestroyTexture(resetTexture);
}