#include "bn_core.h"

#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"
#include "state.h"
#include "hub.h"

#include "rhythm_game.h"

#include "bn_sprite_items_common_variable_8x16_font.h"

int main() 
{
    bn::core::init();

    State* current_state = new Hub();

    /*// font testing stuff
    bn::sprite_item font_sprite(bn::sprite_items::common_variable_8x16_font);
    bn::sprite_font font(font_sprite);
    bn::sprite_text_generator text_generator(font);

    bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

    text_generator.set_center_alignment();

    bn::vector<bn::sprite_ptr, 32> text_sprites;*/

    while(true)
    {
        if(current_state)
        {
            current_state->update();
            
            State* next_state = current_state->next_state();
            if(next_state)
            {
                delete current_state;
                current_state = next_state;
            }
        }
        else
        {
            break;
        }
        
        /*if(bn::keypad::a_pressed()) {
            Hub hub();
        }
        if(bn::keypad::b_pressed()) {
            text_sprites.clear();
            text_generator.generate(0, 0, "Playing songss", text_sprites);
            Rhythm_Game rhythm_game(songs::test_song);
            text_sprites.clear();
            text_generator.generate(0, 0, "Song complete", text_sprites);
        }*/

        bn::core::update();
    }
}