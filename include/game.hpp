#pragma once
#include "minesweeper.hpp"

class Game
{
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

        bool m_isRunning;
        SDL_Event m_testEvent;
        Minesweeper m_minesweeper;

        void Events();
        void Draw() const;

    public:
        Game();
        ~Game();

        void Init();
        void Run();
};
