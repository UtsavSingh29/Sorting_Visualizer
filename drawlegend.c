void drawLegend(SDL_Renderer *renderer, TTF_Font *font)
{
    SDL_Color textColor = {255, 255, 255, 255};
    const char *legend = "Array State:";
    SDL_Surface *legendSurface = TTF_RenderText_Solid(font, legend, textColor);
    SDL_Texture *legendTexture = SDL_CreateTextureFromSurface(renderer, legendSurface);
    SDL_Rect legendRect = {10, 10, legendSurface->w, legendSurface->h};
    SDL_RenderCopy(renderer, legendTexture, NULL, &legendRect);
    SDL_FreeSurface(legendSurface);
    SDL_DestroyTexture(legendTexture);
}