#include "include/intro_sequence.hpp"

IntroSequence::IntroSequence(int logo_width, int *logo_height, Texture2D logo_texture, Rectangle *mask, raylib::Color mask_colour)
{
    this->logo_width = logo_width;
    this->logo_height = logo_height;
    this->logo_texture = logo_texture;
    this->mask = mask;
    this->mask_colour = mask_colour;
}

void IntroSequence::update(float delta_time)
{
    if (*logo_height < 50)
    {
        mask_colour = Color{0, 0, 0, 255};
        state = MAIN_MENU;
    }

    if (mask_colour.GetA() != 0)
    {
        mask_colour.SetA(mask_colour.GetA() - 0.5);
    }
    else
    {
        *logo_height -= 1;
    }
}

void IntroSequence::draw()
{
    DrawTexture(logo_texture, logo_width, *logo_height, RAYWHITE);
    DrawRectangleRec(*mask, mask_colour);
}