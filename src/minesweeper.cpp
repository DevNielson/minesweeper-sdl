#include "minesweeper.hpp"

Minesweeper::Minesweeper()
    : m_surface { nullptr, SDL_DestroySurface },
      m_sprites { nullptr, SDL_DestroyTexture },
      m_spritesCut { SDL_FRect
                       { .x { SPRITE_SIZE * 0 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                       { .x { SPRITE_SIZE * 1 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                       { .x { SPRITE_SIZE * 2 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                       { .x { SPRITE_SIZE * 3 }, .y { SPRITE_SIZE * 0 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                       { .x { SPRITE_SIZE * 0 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                       { .x { SPRITE_SIZE * 1 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                       { .x { SPRITE_SIZE * 2 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                       { .x { SPRITE_SIZE * 3 }, .y { SPRITE_SIZE * 1 }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } }
                   },
      m_spritesPosition { SDL_FRect
                            { .x {}, .y {}, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                            { .x { WINDOW_WIDTH - SPRITE_SIZE }, .y {}, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                            { .x {}, .y { WINDOW_HEIGHT - SPRITE_SIZE }, .w { SPRITE_SIZE }, .h { SPRITE_SIZE } },
                            { .x { WINDOW_WIDTH - SPRITE_SIZE }, .y { WINDOW_HEIGHT - SPRITE_SIZE }, .w { SPRITE_SIZE },
                             .h { SPRITE_SIZE } }
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
    for (std::size_t i {}; i < 4; ++i)
    {
        SDL_RenderTexture(renderer, m_sprites.get(), &m_spritesCut.at(i), &m_spritesPosition.at(i));
    }
}
