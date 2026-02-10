#include "minesweeper.hpp"

Minesweeper::Minesweeper()
    : m_surface { nullptr, SDL_DestroySurface },
      m_backgroundTop { nullptr, SDL_DestroyTexture },
      m_backgroundBottom { nullptr, SDL_DestroyTexture },
      m_backgroundTopDstRect { .x {}, .y {}, .w { BACKGROUND_TOP_WIDTH }, .h { BACKGROUND_TOP_HEIGHT  } }
      {}

Minesweeper::~Minesweeper()
{
    m_backgroundBottom.reset();
    m_backgroundTop.reset();
}

void Minesweeper::Init(SDL_Renderer *renderer)
{
    m_surface.reset(SDL_LoadPNG("../data/backgroundTop.png"));
    if (!m_surface)
    {
        const std::string ERROR { std::format("Error loding backgroundTop.png: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }

    m_backgroundTop.reset(SDL_CreateTextureFromSurface(renderer, m_surface.get()));
    if (!m_backgroundTop)
    {
        const std::string ERROR { std::format("Error creating backgroundTop: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }
    m_surface.reset();

    if (!SDL_SetTextureScaleMode(m_backgroundTop.get(), SDL_SCALEMODE_NEAREST))
    {
        const std::string ERROR { std::format("Error setting scale mode for backgroundTop: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }
}

void Minesweeper::Update()
{
}

void Minesweeper::Draw(SDL_Renderer *renderer) const
{
    SDL_RenderTexture(renderer, m_backgroundTop.get(), nullptr, &m_backgroundTopDstRect);
}
