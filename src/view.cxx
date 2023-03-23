#include "view.hxx"


// color of the walls
static ge211::Color const wall_color {0, 0, 100};
// color of the dots
static ge211::Color const dot_color {222, 161, 133};
// color of Pacman
static ge211::Color const pacman_test_color {255, 255, 0};
// name of pacman sound effect file
static std::string const pacman_sound_filename {"munch.mp3"};



View::View(Model const& model, ge211::Mixer& mixer)
        : model_(model),
        wall_sprite_horiz({500, 10}, wall_color),
        wall_sprite_side({10, 500}, wall_color),
        dot_sprite(3, dot_color),
        pacman_size_test(15, pacman_test_color),
        score(),
        mixer_(mixer)

{ }

void
View::draw(ge211::Sprite_set& set)
{
    // set font and display score, thanks Professor Hummel for helping me
    // use this code from the GE211 website
    ge211::Font sans30{"sans.ttf", 30};
    ge211::Text_sprite::Builder score_builder(sans30);
    score_builder.color(pacman_test_color) << model_.dots_eaten();
    score.reconfigure(score_builder);
    set.add_sprite(score, {700, 20});

    // set position of Pacman
    Position pos = model_.pacman().top_left();
    ge211::Posn<int> p = pos.into<int>();
    // display Pacman
    set.add_sprite(pacman_size_test, p, 2);

    // displays walls
    set.add_sprite(wall_sprite_horiz, model_.walls[0].top_left());
    set.add_sprite(wall_sprite_horiz, model_.walls[1].top_left());
    set.add_sprite(wall_sprite_side, model_.walls[2].top_left());
    set.add_sprite(wall_sprite_side, model_.walls[3].top_left());

    // display dots
    for (ge211::Rect<int> i : model_.dots) {
        set.add_sprite(dot_sprite, i.top_left());
    }

    // if Pacman is moving, load the sound effect file and play the sound
    // effect
    if (model_.pacman().velocity.width != 0 ||
    model_.pacman().velocity.height != 0) {
        pacman_sound_.try_load(pacman_sound_filename, mixer_);
        try {
            mixer_.play_effect(pacman_sound_);
        } catch (ge211::Environment_error const& exn) {
            // Thanks to Professor Hummel for giving us the idea to catch and
            // not display an error

            //ge211::internal::logging::warn(exn.what())
            //        << "To enable background music, put a file named\n"
            //        << pacman_sound_filename
            //        << " in the Resources/ directory.";
        }

    }
}