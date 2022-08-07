#pragma once
#include <raylib-cpp.hpp>
#include <map>
#include <string>

using namespace std;

class Player
{

public:
    float x, y, w, h;
    map<string, int> char_data;

    Player();
    Player(float x, float y, float w, float h);
    void update(float delta_time, Rectangle game_screen);
    void draw();
    void move_player(float delta_time, Rectangle game_screen);
};