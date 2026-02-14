#include "main.hpp"

class Minesweeper
{
    private:
        std::unique_ptr<SDL_Surface, decltype(&SDL_DestroySurface)> m_surface;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_sprites;

        std::array<SDL_FRect, 8> m_spritesCut;

    public:
        Minesweeper();
        ~Minesweeper();
        void Init(SDL_Renderer *);
        void Update();
        void Draw(SDL_Renderer *) const;
};
