#pragma once

#include "model.hxx"

class View
{
public:
    // Constructs a "View" given a const reference to the model
    // that stores the actual state of the game (which
    // lets the view observe the model’s state but not modify it) and a
    // reference to a mixer.
    explicit View(Model const& model, ge211::Mixer& mixer);

    // renders all the game entities to the screen
    void draw(ge211::Sprite_set& set);


private:
    // const reference to model_
    Model const& model_;

    // definition for top and side wall sprites
    ge211::sprites::Rectangle_sprite wall_sprite_horiz;
    ge211::sprites::Rectangle_sprite wall_sprite_side;
    // definition for dot sprites
    ge211::sprites::Circle_sprite dot_sprite;
    // definition for Pacman sprite
    ge211::sprites::Circle_sprite pacman_size_test;
    // definition for test_sprite to display score
    ge211::sprites::Text_sprite score;



    // audio
    ge211::Mixer& mixer_;
    ge211::Sound_effect pacman_sound_;

};
