#include "main.hpp"

class Minesweeper
{
    private:
        std::unique_ptr<SDL_Surface, decltype(&SDL_DestroySurface)> m_surface;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_backgroundTop;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_backgroundBottom;

        SDL_FRect m_backgroundTopDstRect;

    public:
        Minesweeper();
        ~Minesweeper();
        void Init(SDL_Renderer *);
        void Update();
        void Draw(SDL_Renderer *) const;
};
