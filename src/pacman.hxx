// Struct for modeling pacman.

#pragma once

#include <ge211.hxx>

#include <iostream>


//shorthand for posn<float>
using Position = ge211::Posn<float>;


//shorthand for dims<float>
using Velocity = ge211::Dims<float>;

//shorthand for rect<int>
using Block = ge211::Rect<int>;


struct Pacman
{
    // no inputs for constructor
    Pacman();


    // returns top left corner
    Position top_left() const;

    // returns next state of pacman
     Pacman next(double dt) const;

    // check collisions with walls
    bool hits_top() const;
    bool hits_bottom() const;
    bool hits_side() const;

    // check if pacman eats a dot
    bool eats_dot(ge211::Rect<int> const&) const;

    // if he eats a dot, destroy it.
    bool destroy_dot(std::vector<ge211::Rect<int>>& dots) const;





    // radius of pacman
    int radius;
    // center of pacman
    Position center;
    // velocity of pacman
    Velocity velocity;
    // bool that says if pacman is live
    bool live;


};
    // tools to compare pacman with another pacman
bool
operator==(Pacman const&, Pacman const&);

bool
operator!=(Pacman const&, Pacman const&);


