#pragma once
#include "main.hpp"

class Game
{
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

        bool m_isRunning;
        SDL_Event m_testEvent;

        void Events();

    public:
        Game();
        ~Game();

        void Init();
        void Run();
};
