#include "main.hpp"

class Minesweeper
{
private:
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_sprites;

    std::array<SDL_FRect, 8> m_spritesCut;
    std::array<SDL_FRect, 4> m_spritesPosition;

public:
    Minesweeper();
    ~Minesweeper();
    void Init(SDL_Renderer *);
    void Update();
    void Draw(SDL_Renderer *) const;
};
