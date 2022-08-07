#include "include/player.hpp"

Player::Player()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->w = 0.0f;
    this->h = 0.0f;

    char_data["LIFE:  "] = 100;
    char_data["STR:   "] = 0;
    char_data["AGL:     "] = 0;
    char_data["PDEF:   "] = 10;
    char_data["MDEF: "] = 10;
    char_data["LUCK:    "] = 5;
}

Player::Player(float x, float y, float w, float h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    char_data["LIFE:  "] = 100;
    char_data["STR:   "] = 0;
    char_data["AGL:     "] = 0;
    char_data["PDEF:   "] = 10;
    char_data["MDEF: "] = 10;
    char_data["LUCK:    "] = 5;
}

void Player::update(float delta_time, Rectangle game_screen)
{
    move_player(delta_time, game_screen);
}

void Player::draw()
{
}

void Player::move_player(float delta_time, Rectangle game_screen)
{
    if (IsKeyDown('A') && x >= game_screen.x)
    {
        x -= 4; // x the movement by delta time here once it's all working
    }
    if (IsKeyDown('D') && x <= game_screen.width)
    {
        x += 4;
    }
    if (IsKeyDown('S') && y <= game_screen.height)
    {
        y += 4;
    }
    if (IsKeyDown('W') && y >= game_screen.y)
    {
        y -= 4;
    }
}