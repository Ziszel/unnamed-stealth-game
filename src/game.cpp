#include "include/game.hpp"

Game::Game(int *screen_width, int *screen_height)
{
    this->screen_width = *screen_width;
    this->screen_height = *screen_height;
    initialise_game();
}

void Game::initialise_game()
{
    this->game_screen.x = PADDING_LEFT_TOP;
    this->game_screen.y = PADDING_LEFT_TOP;
    this->game_screen.width = screen_width * 0.60 - PADDING_RIGHT_BOTTOM;
    this->game_screen.height = screen_height - PADDING_RIGHT_BOTTOM;

    this->char_data_rect.x = screen_width * 0.60 + PADDING_LEFT_CHAR_DATA;
    this->char_data_rect.y = PADDING_LEFT_TOP;
    this->char_data_rect.width = screen_width * 0.40;
    this->char_data_rect.height = screen_height - PADDING_RIGHT_BOTTOM;

    this->action_text_rect.x = screen_width * 0.60 + PADDING_LEFT_TOP;
    this->action_text_rect.y = screen_height * 0.55 + PADDING_LEFT_TOP;
    this->action_text_rect.width = screen_width * 0.40 - PADDING_RIGHT_BOTTOM;
    this->action_text_rect.height = screen_width * 0.55 - PADDING_RIGHT_BOTTOM;

    p.x = game_screen.width;
    p.y = game_screen.height;
    p.w = 20;
    p.h = 20;
}

void Game::update(float delta_time)
{
    p.update(delta_time, game_screen);
}

void Game::draw()
{
    text_colour.DrawText("CHAR", screen_width * 0.75, char_data_rect.y, 60);

    // test updating action_text
    if (p.x < game_screen.width / 2)
    {
        action_text = "You are on the left side of the game area!";
    }
    else if (p.x >= game_screen.width / 2)
    {
        action_text = "You are on the right side of the game area!";
    }

    DrawLine(game_screen.width / 2, 0, game_screen.width / 2, game_screen.height, RED);

    int y_offset = 100;
    int count = 0;
    for (map<string, int>::iterator i = p.char_data.begin(); i != p.char_data.end(); i++)
    {
        if (count > 0 && count % 2 == 0)
        {
            y_offset += 40;
        }
        if (count % 2 == 0)
        {
            text_colour.DrawText((*i).first + to_string((*i).second), char_data_rect.x, char_data_rect.y + y_offset, 40);
        }
        else
        {
            text_colour.DrawText((*i).first + to_string((*i).second), char_data_rect.x + PADDING_RIGHT_CHAR_DATA, char_data_rect.y + y_offset, 40);
        }

        count++;
    }

    draw_action_text(action_text, action_text_rect, text_colour, box_colour, PADDING_ACTION_BOX_X, PADDING_ACTION_BOX_Y);

    DrawRectangle(p.x, p.y, p.w, p.h, box_colour);
}

void Game::draw_action_text(std::string &action_text_string, Rectangle action_text_rect, raylib::Color text_colour, raylib::Color box_colour, int x_padding, int y_padding)
{
    std::vector<string> action_text_split;

    int buf_size = 30;
    char buffer[buf_size];
    int j_count = 0;
    bool zero_flag = true;
    for (int i = 0; i < action_text_string.size();)
    {
        for (int j = 0; j < buf_size; ++j)
        {

            if (j == 0 && action_text_string[i] == ' ')
            {
                zero_flag = true;
                ++i;
            }
            // ensure words are on the same line
            buffer[j] = action_text_string[i];

            if (j > buf_size - 10)
            {
                if (action_text_string[i] != ' ')
                {
                    buffer[j] = action_text_string[i];
                    if (i < action_text_string.size())
                    {
                        i++;
                    }
                }
            }

            if (j <= buf_size - 10)
            {
                if (i < action_text_string.size())
                {
                    i++;
                }
            }
            zero_flag = false;
        }
        // May be a cleaner way to do this
        std::string temp;
        temp.append(buffer);
        // std::cout << temp << "\n";
        action_text_split.push_back(temp);
    }
    DrawRectangle(action_text_rect.x, action_text_rect.y, action_text_rect.width, action_text_rect.height, box_colour);

    int line_padding = 0;
    for (auto s : action_text_split)
    {
        text_colour.DrawText(s.c_str(), action_text_rect.x + x_padding, action_text_rect.y + y_padding + line_padding, 30);
        line_padding += 30;
    }
}
