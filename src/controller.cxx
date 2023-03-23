#include "controller.hxx"


Controller::Controller()
        : model_(),
        view_(model_, mixer())

{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void Controller::on_frame(double dt) {
    model_.on_frame(dt);
    // if all 304 dots are eaten, the game is over - call quit()
    if (model_.dots_eaten() == 304) {
        model_.pacman2().live = false;
        quit();
    }
}


void Controller::on_key(ge211::Key key) {
    // if the left key is pressed
    if (key == ge211::Key::left()) {
        // move Pacman to the left with -75 x-velocity and 0 y-velocity
        model_.pacman2().velocity.height = 0;
        model_.pacman2().velocity.width = -75;
    }

    // if the right key is pressed
    if (key == ge211::Key::right()) {
        // move Pacman to the right with 75 x-velocity and 0 y-velocity
        model_.pacman2().velocity.height = 0;
        model_.pacman2().velocity.width = 75;
    }

    // if the up key is pressed
    if (key == ge211::Key::up()) {
        // move Pacman up with 0 x-velocity and -75 y-velocity
        model_.pacman2().velocity.height = -75;
        model_.pacman2().velocity.width = 0;
    }

    // if the down key is pressed
    if (key == ge211::Key::down()) {
        // move Pacman down with 0 x-velocity and 75 y-velocity
        model_.pacman2().velocity.height = 75;
        model_.pacman2().velocity.width = 0;

    }

    // press enter key to start game
    if (key == ge211::Key::code(13)) {
        model_.launch();
    }
    // press q to quit game
    if (key == ge211::Key::code(27)) {
        quit();
    }

    // press p to pause game
    if (key == ge211::Key::code('p')) {
        model_.pacman2().velocity.height = 0;
        model_.pacman2().velocity.width = 0;
    }

}