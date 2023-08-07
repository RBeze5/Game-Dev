#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "JRPG GUI Example";

SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void handleEvents(bool& quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }
}

void render(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Texture* startButtonTexture) {
    // Clear the screen
    SDL_RenderClear(renderer);

    // Render the background image
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);

    // Render the start button at position (x, y)
    int x = SCREEN_WIDTH / 2 - 100;
    int y = SCREEN_HEIGHT / 2 - 50;
    SDL_Rect buttonRect = { x, y, 200, 100 };
    SDL_RenderCopy(renderer, startButtonTexture, nullptr, &buttonRect);

    // Present the renderer
    SDL_RenderPresent(renderer);
}

bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the clear color to black

    return true;
}

int main() {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!initSDL(window, renderer)) {
        return 1;
    }

    // Load textures
    SDL_Texture* backgroundTexture = loadTexture("background.png", renderer);
    SDL_Texture* startButtonTexture = loadTexture("start_button.png", renderer);

    bool quit = false;
    while (!quit) {
        handleEvents(quit);
        render(renderer, backgroundTexture, startButtonTexture);
        // Add your game logic here, such as handling button clicks
    }

    // Cleanup and shutdown SDL
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(startButtonTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}