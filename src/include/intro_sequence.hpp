#pragma once
#include <raylib-cpp.hpp>
#include "state.hpp"

class IntroSequence : public State
{

private:
    int logo_width;
    int *logo_height;
    Texture2D logo_texture;
    Rectangle *mask;
    raylib::Color mask_colour;

public:
    IntroSequence(int logo_width, int *logo_height, Texture2D logo_texture, Rectangle *mask, raylib::Color mask_colour);
    void update(float delta_time);
    void draw();
};