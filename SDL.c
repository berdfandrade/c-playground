#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h> // Para usar fontes TrueType (TTF)

int main(int argc, char* args[]) {
    // Inicializa a SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL não pode ser inicializada! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Inicializa o SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf não pode ser inicializado! SDL_Error: %s\n", TTF_GetError());
        return 1;
    }

    // Cria uma janela
    SDL_Window* janela = SDL_CreateWindow("Mensagem na Tela", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (janela == NULL) {
        printf("Janela não pode ser criada! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Cria um renderizador para a janela
    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    if (renderizador == NULL) {
        printf("Renderizador não pode ser criado! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Carrega uma fonte TrueType
    TTF_Font* fonte = TTF_OpenFont("path/to/your/font.ttf", 28); // Substitua "path/to/your/font.ttf" pelo caminho para sua fonte TTF
    if (fonte == NULL) {
        printf("Fonte não pode ser carregada! SDL_Error: %s\n", TTF_GetError());
        return 1;
    }

    // Cor da fonte (branco)
    SDL_Color cor = {255, 255, 255};

    // Renderiza a mensagem em uma superfície
    SDL_Surface* superficie = TTF_RenderText_Solid(fonte, "Hello, SDL!", cor);
    if (superficie == NULL) {
        printf("Superfície não pode ser criada! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Converte a superfície para uma textura
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderizador, superficie);
    if (textura == NULL) {
        printf("Textura não pode ser criada! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Limpa a tela
    SDL_RenderClear(renderizador);

    // Define a posição da mensagem
    SDL_Rect destino = {100, 100, superficie->w, superficie->h};

    // Renderiza a mensagem na tela
    SDL_RenderCopy(renderizador, textura, NULL, &destino);

    // Atualiza a tela
    SDL_RenderPresent(renderizador);

    // Mantém a janela aberta por alguns segundos
    SDL_Delay(3000);

    // Libera recursos
    SDL_DestroyTexture(textura);
    SDL_FreeSurface(superficie);
    TTF_CloseFont(fonte);
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    TTF_Quit();
    SDL_Quit();

    return 0;
}