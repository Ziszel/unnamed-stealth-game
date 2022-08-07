#include <raylib-cpp.hpp>
#include <iostream>
#include "include/state.hpp"
#include "include/main_menu.hpp"
#include "include/intro_sequence.hpp"
#include "include/game.hpp"

// static values assigned here
game_state State::state = INTRO_SEQUENCE;

int main()
{

    // Initialization
    int screenWidth = 1280;
    int screenHeight = 720;

    raylib::Color mask_colour(0,0,0,255);
    raylib::Color mask_colour_2(0,0,0,255);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");

    SetTargetFPS(60);
    float delta_time = 0.0f;

    // Load game logo
    Image logo_img = LoadImage("res/lm-logo.png");
    ImageResize(&logo_img, 1200, 266);
    Texture2D logo_texture = LoadTextureFromImage(logo_img); // LoadTexture("res/lm-logo.png");
    Texture2D menu_bg_texture = LoadTexture("res/snake.png"); 
    int logo_height = screenHeight / 4;
    int logo_width = 40;
    // Create mask for transparent effects
    Rectangle *mask = (Rectangle*) malloc(sizeof(Rectangle)); //{0, 0, screenWidth, screenHeight};
    mask->x = 0;
    mask->y = 0;
    mask->width = screenWidth;
    mask->height = screenHeight;

    game_state current_state;
    MainMenu main_menu(logo_width, &logo_height, screenWidth, screenHeight, logo_texture, menu_bg_texture, mask, mask_colour);
    IntroSequence intro_sequence(logo_width, &logo_height, logo_texture, mask, mask_colour);
    Game game(&screenWidth, &screenHeight);

    // Main game loop
    while (!w.ShouldClose())
    {
        // get all required params that may have changed
        delta_time = GetFrameTime();
        current_state = intro_sequence.get_current_state();

        BeginDrawing();
        ClearBackground(BLACK);

        switch (current_state)
        {
        case 1:
            intro_sequence.update(delta_time);
            intro_sequence.draw();
            break;
        
        case 2:
            main_menu.update(delta_time);
            main_menu.draw();
            break;
        case 3:
            game.update(delta_time);
            game.draw();
        default:
            break;
        }

        EndDrawing();
    }
    free(mask);

    return 0;
}