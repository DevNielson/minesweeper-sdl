#include "game.hpp"

Game::Game()
    : m_window { nullptr, SDL_DestroyWindow },
      m_renderer { nullptr, SDL_DestroyRenderer },
      m_isRunning { true },
      m_testEvent {}
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

    m_window.reset(SDL_CreateWindow(WINDOW_TITLE.data(), WINDOW_WIDTH, WINDOW_HEIGHT, 0));
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
}

void Game::Run()
{
    while (m_isRunning)
    {
        Events();
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
