#include "minesweeper.hpp"

Minesweeper::Minesweeper()
    : m_surface { nullptr, SDL_DestroySurface },
      m_sprites { nullptr, SDL_DestroyTexture },
      m_spritesCut {
                    { .x { SPRITE_SIZE * 0 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                    { .x { SPRITE_SIZE * 1 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                    { .x { SPRITE_SIZE * 2 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                    { .x { SPRITE_SIZE * 3 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                    { .x { SPRITE_SIZE * 0 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                    { .x { SPRITE_SIZE * 1 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                    { .x { SPRITE_SIZE * 2 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                    { .x { SPRITE_SIZE * 3 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } }
                   }
      {}

Minesweeper::~Minesweeper()
{
    m_sprites.reset();
}

void Minesweeper::Init(SDL_Renderer *renderer)
{
    m_surface.reset(SDL_LoadPNG(SPRITES_URL.data()));
    if (!m_surface)
    {
        const std::string ERROR { std::format("Error loding sprites.png: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }

    m_sprites.reset(SDL_CreateTextureFromSurface(renderer, m_surface.get()));
    if (!m_sprites)
    {
        const std::string ERROR { std::format("Error creating sprites: {}", SDL_GetError()) };
        throw std::runtime_error(ERROR);
    }
    m_surface.reset();

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
    // SDL_RenderTexture(renderer, m_sprites.get(), &m_spritesArray.at(5), &m_posicaoDaBorda.at(0));
}
