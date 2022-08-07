#pragma once
#include <raylib-cpp.hpp>
#include "state.hpp"

class MainMenu: public State {

private:
    int count = 0;
    int logo_width;
    int *logo_height;
    int screen_width;
    int screen_height;
    Texture2D logo_texture;
    Texture2D menu_bg_texture;
    Rectangle *mask;
    raylib::Color mask_colour;

public:
    MainMenu(int logo_width, int *logo_height, int screen_width, int screen_height, Texture2D logo_texture, Texture2D menu_bg_texture, Rectangle *mask, raylib::Color mask_colour);
    void update(float delta_time);
    void draw();

};