#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <raylib-cpp.hpp>
#include "player.hpp"

class Game {

private:
    int screen_width;
    int screen_height;

    const float PADDING_LEFT_TOP = 5;
    const float PADDING_RIGHT_BOTTOM = 30;
    const int PADDING_LEFT_CHAR_DATA = 30;
    const int PADDING_RIGHT_CHAR_DATA = 275;
    const int PADDING_ACTION_BOX_Y = 10;
    const int PADDING_ACTION_BOX_X = 30;

    // screen rect setup
    Rectangle game_screen;
    Rectangle char_data_rect;
    Rectangle action_text_rect;

    std::string action_text = "";

    // define colours
    raylib::Color box_colour = {0, 0, 128, 180};
    raylib::Color text_colour = {255, 255, 255, 255};

    // initalise Player here
    float player_x;
    
    // class members initalised automatically when class is constructed, default zero-augument constructor ran here. 
    Player p;

public:
    Game(int *screen_width, int *screen_height);

    void initialise_game();
    void update(float delta_time);
    void draw();
    void draw_action_text(std::string &action_text_string, Rectangle action_text_rect, raylib::Color text_colour, raylib::Color box_colour, int x_padding, int y_padding);

};