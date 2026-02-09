#include "game.hpp"
#include <SDL3/SDL_main.h>

int main(int argc, char **argv)
{
    try
    {
        Game game;
        game.Init();
        game.Run();
    }
    catch (std::runtime_error &e)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", e.what(), nullptr);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
