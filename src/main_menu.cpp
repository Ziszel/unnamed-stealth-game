#include "include/main_menu.hpp"

MainMenu::MainMenu(int logo_width, int *logo_height, int screen_width, int screen_height, Texture2D logo_texture, Texture2D menu_bg_texture, Rectangle *mask, raylib::Color mask_colour)
{
    this->logo_width = logo_width;
    this->logo_height = logo_height;
    this->screen_width = screen_width;
    this->screen_height = screen_height;
    this->logo_texture = logo_texture;
    this->menu_bg_texture = menu_bg_texture;
    this->mask = mask;
    this->mask_colour = mask_colour;
}

void MainMenu::update(float delta_time)
{
    count++;
    if (count > 100)
    {
        count = 0;
    }
    if (mask_colour.GetA() != 0)
    {
        mask_colour.SetA(mask_colour.GetA() - 1);
    }
    if (IsKeyPressed('A'))
    {
        state = GAME_LOOP;
    }
}

void MainMenu::draw()
{
    DrawTexture(menu_bg_texture, 0, 0, RAYWHITE);
    DrawRectangleRec(*mask, mask_colour);
    DrawTexture(logo_texture, logo_width, *logo_height, RAYWHITE);
    if (count < 50)
    {
        DrawText("Press any button to start", screen_width / 2 - 275, screen_height / 2 + 100, 40, WHITE);
    }
}