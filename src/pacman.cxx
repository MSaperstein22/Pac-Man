#include "pacman.hxx"


// initialize a pacman
Pacman::Pacman()
        : radius(15),
          center(Position(25, 25)),
          velocity(Velocity(0,0)),
          live(false)
{ }

Position
Pacman::top_left() const
{
    float x_val = center.x - radius;
    float y_val = center.y - radius;
    return {x_val, y_val};
}

bool
Pacman::hits_bottom() const
{
    // bottom of pacman is the y-coordinate of center + radius
    float y_pacman = center.y + radius;
    // if the y-coordinate of pacman > the dimensions of game, return true
    if (y_pacman > 500) {
        return true;
    }
    return false;
}

// Pacman hits the top wall when the y coordinate of its top is less than
// 10.
bool
Pacman::hits_top() const
{
    // top of pacman is the y-coordinate of center + radius
    float y_pacman = center.y - radius;
    // if the top of pacman is above the wall, return true
    if (y_pacman < 10) {
        return true;
    }
    return false;
}

// He hits a side when the x coordinate of his left side is
// less than 10 or the x coordinate of his right side is greater
// than the width of the game.
bool
Pacman::hits_side() const
{
    // initialize left and right sides of pacman
    float x_LHS_p = center.x - radius;
    float x_RHS_p = center.x + radius;
    // if left side of pacman hits left wall, return true
    if (x_LHS_p < 10) {
        return true;
    }
    // if right side of pacman hits right wall return true
    if (x_RHS_p > 490) {
        return true;
    }
    return false;
}

// calculate pacman next state
Pacman
Pacman::next(double dt) const
{
    // make copy of pacman
    Pacman result(*this);

    // initialize x,y coordinates of his center based on his velocity and dt
    result.center.x += (result.velocity.width * dt);
    result.center.y += (result.velocity.height * dt);
    // return next position of pacman
    return result;
}

// check if pacman eats a dot
bool
Pacman::eats_dot(ge211::Rect<int> const& dot) const
{
    // initialize sides of pacman
    float x_RHS_pacman = center.x + radius;
    float x_LHS_pacman = center.x - radius;
    float top_pacman = center.y - radius;
    float bottom_pacman = center.y + radius;
    // initialize sides of dot
    float x_RHS_dot = dot.bottom_right().x;
    float x_LHS_dot = dot.bottom_left().x;
    float top_dot = dot.top_right().y;
    float bottom_dot = dot.bottom_right().y;
    // if right hand side of pacman < left hand side of dot, return false
    if (x_RHS_pacman < x_LHS_dot) {
        return false;
    }
    // if left hand side of pacman > right hand side of dot, return false
    if (x_LHS_pacman > x_RHS_dot) {
        return false;
    }
    // if bottom of pacman < top of dot, return false
    if (bottom_pacman < top_dot) {
        return false;
    }
    // if bottom of dot < top of pacman, return false
    if (bottom_dot < top_pacman) {
        return false;
    }

    // if none of these occur, return true
    return true;
}

bool
Pacman::destroy_dot(std::vector<ge211::Rect<int>>& dots) const
{
    // iterate through each dot in the dots vector
    for (Block& dot : dots) {
        // if pacman eats a dot
        if (eats_dot(dot)) {
            // swap this dot with a copy of the last dot
            std::swap(dot, dots.back());
            // remove the last dot and return true
            dots.pop_back();
            return true;
        }
    }
    // if pacman does not eat a dot, return false
    return false;
}

bool
operator==(Pacman const& a, Pacman const& b)
{

    // if pacman == pacman, return true. If not, return false
    if (a.center == b.center && a.radius == b.radius && a.velocity == b
            .velocity && a.live == b.live) {
        return true;
    }
    else {
        return false;
    }

}

bool
operator!=(Pacman const& a, Pacman const& b)
{
    return !(a == b);
}

