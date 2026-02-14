#pragma once
#include <array>
#include <map>
#include <memory>
#include <print>
#include <SDL3/SDL.h>

constexpr std::string WINDOW_TITLE { "Minesweeper" };
constexpr int WINDOW_WIDTH { 800 };
constexpr int WINDOW_HEIGHT { 800 };

const std::string SPRITES_URL { "../data/sprites.png" };
constexpr float SPRITE_SIZE { 32.0f };
