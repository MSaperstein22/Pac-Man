#pragma once

#include <ge211.hxx>
#include "pacman.hxx"

class Model
{

public:

    Model();

    //initialize vectors containing the walls and the dots
    std::vector<ge211::Rect<int>> walls;
    std::vector<ge211::Rect<int>> dots;

    // accessible by other files but cannot be changed
    Pacman const& pacman() const {
        return pacman_;
    }
    // accessible by other files and can be changed
    Pacman & pacman2() {
        return pacman_;
    }
    // no other file should change the amount of dots eaten
    int const& dots_eaten() const{
        return dots_eaten_;
    }


    void launch();
    void on_frame(double dt);

private:
    Pacman pacman_;
    // number of dots pacman has eaten = score. also tells program when game
    // is over
    int dots_eaten_;




};
