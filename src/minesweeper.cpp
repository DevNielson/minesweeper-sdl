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
      m_spritesPositions {}
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
}
