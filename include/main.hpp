#pragma once
#include <array>
#include <memory>
#include <print>
#include <SDL3/SDL.h>

namespace Window
{
    constexpr std::string TITLE { "Minesweeper" };
    constexpr int WIDTH { 384 };
    constexpr int HEIGHT { 500 };
    const std::string FAVICON_URL { "../data/favicon.png" };
}

namespace Sprites
{
    const std::string URL { "../data/sprites.png" };
    constexpr float SIZE { 32.0f };
}
