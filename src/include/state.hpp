#pragma once

enum game_state
{
    // shorterned names for clarity in-relation to classes
    INTRO_SEQUENCE = 1,
    MAIN_MENU = 2,
    GAME_LOOP = 3
};

class State {

protected:
    static game_state state;

public:
   // pure virtual function providing interface framework.
   virtual void update(float delta_time) = 0;
   virtual void draw() = 0;
   
   game_state get_current_state() {
      return state;
   }

   void set_current_state(game_state new_state) {
       state = new_state;
   }

};