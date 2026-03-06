#pragma once
#include "main.hpp"

class Minesweeper
{
private:
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_sprites;

private:
    std::array<SDL_FRect, 8> m_spritesCut;
    std::array<SDL_FRect, 9> m_spritesPositions;

public:
    Minesweeper();
    ~Minesweeper();
    void Init(SDL_Renderer *);
    void Update();
    void Draw(SDL_Renderer *) const;
};
