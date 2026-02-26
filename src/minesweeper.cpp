#include "minesweeper.hpp"

Minesweeper::Minesweeper()
    : m_sprites { nullptr, SDL_DestroyTexture },
      m_spritesCut
      {
          SDL_FRect { .x { Sprites::SIZE * 0 }, .y { Sprites::SIZE * 0 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Sprites::SIZE * 1 }, .y { Sprites::SIZE * 0 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Sprites::SIZE * 2 }, .y { Sprites::SIZE * 0 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Sprites::SIZE * 3 }, .y { Sprites::SIZE * 0 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Sprites::SIZE * 0 }, .y { Sprites::SIZE * 1 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Sprites::SIZE * 1 }, .y { Sprites::SIZE * 1 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Sprites::SIZE * 2 }, .y { Sprites::SIZE * 1 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Sprites::SIZE * 3 }, .y { Sprites::SIZE * 1 }, .w { Sprites::SIZE }, .h { Sprites::SIZE } }
      },
      m_spritesPositions
      {
          SDL_FRect { .x {}, .y {}, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Window::WIDTH - Sprites::SIZE }, .y {}, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x {}, .y { Window::HEIGHT - Sprites::SIZE }, .w { Sprites::SIZE }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Window::WIDTH - Sprites::SIZE }, .y { Window::HEIGHT - Sprites::SIZE }, .w { Sprites::SIZE },
                      .h { Sprites::SIZE } },

          SDL_FRect { .x {}, .y {}, .w { Window::WIDTH }, .h { Sprites::SIZE } },
          SDL_FRect { .x { 32.0f }, .y {  100.0f }, .w { Window::WIDTH - Sprites::SIZE * 2 }, .h { Sprites::SIZE } },
          SDL_FRect { .x {}, .y { Window::HEIGHT - Sprites::SIZE }, .w { Window::WIDTH }, .h { Sprites::SIZE } },
          SDL_FRect { .x { Window::WIDTH - 32.0f }, .y {}, .w { Sprites::SIZE }, .h { 132.0f } },
          SDL_FRect { .x {}, .y { Window::WIDTH }, .w { Sprites::SIZE }, .h { Sprites::SIZE } }
      }
{}

Minesweeper::~Minesweeper()
{
    m_sprites.reset();
}

void Minesweeper::Init(SDL_Renderer *renderer)
{
    m_sprites.reset(SDL_CreateTextureFromSurface(renderer, SDL_LoadPNG(Sprites::URL.data())));
    if (!m_sprites)
    {
        const std::string ERROR { std::format("Error creating sprites: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }

    if (!SDL_SetTextureScaleMode(m_sprites.get(), SDL_SCALEMODE_NEAREST))
    {
        const std::string ERROR { std::format("Error setting scale mode from sprites: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }
}

void Minesweeper::Update()
{
}

void Minesweeper::Draw(SDL_Renderer *renderer) const
{
    SDL_RenderTexture(renderer, m_sprites.get(), &m_spritesCut.at(4), &m_spritesPositions.at(4));
    SDL_RenderTexture(renderer, m_sprites.get(), &m_spritesCut.at(4), &m_spritesPositions.at(5));
    SDL_RenderTexture(renderer, m_sprites.get(), &m_spritesCut.at(4), &m_spritesPositions.at(6));
    SDL_RenderTexture(renderer, m_sprites.get(), &m_spritesCut.at(5), &m_spritesPositions.at(7));

    for (const SDL_FRect &dstRect : m_spritesPositions)
    {
    }
    for (std::size_t i {}; i < 4; ++i)
    {
        SDL_RenderTexture(renderer, m_sprites.get(), &m_spritesCut.at(i), &m_spritesPositions.at(i));
    }
}
