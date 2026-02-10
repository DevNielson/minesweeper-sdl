#include "game.hpp"

Game::Game()
    : m_window { nullptr, SDL_DestroyWindow },
      m_renderer { nullptr, SDL_DestroyRenderer },
      m_isRunning { true },
      m_testEvent {},
      m_minesweeper {}
      {}

Game::~Game()
{
    m_renderer.reset();
    m_window.reset();
    SDL_Quit();
}

void Game::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        const std::string ERROR { std::format("Error initialize SDL3: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }

    m_window.reset(SDL_CreateWindow(WINDOW_TITLE.data(), WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE));
    if (!m_window)
    {
        const std::string ERROR { std::format("Error creating window: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }

    m_renderer.reset(SDL_CreateRenderer(m_window.get(), nullptr));
    if (!m_renderer)
    {
        const std::string ERROR { std::format("Error creating renderer: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }

    m_minesweeper.Init(m_renderer.get());
}

void Game::Run()
{
    while (m_isRunning)
    {
        Events();
        Draw();
    }
}

void Game::Events()
{
    while (SDL_PollEvent(&m_testEvent))
    {
        switch (m_testEvent.type)
        {
            case SDL_EVENT_QUIT:
                m_isRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::Draw() const
{
    SDL_RenderClear(m_renderer.get());

    m_minesweeper.Draw(m_renderer.get());

    SDL_RenderPresent(m_renderer.get());
}
