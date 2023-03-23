#include "model.hxx"


Model::Model()
{
    // create border walls
    walls.push_back(ge211::Rect<int>(0, 0, 0, 0));
    walls.push_back(ge211::Rect<int>(0, 500, 0, 0));

    walls.push_back(ge211::Rect<int>(490, 0, 0, 0));
    walls.push_back(ge211::Rect<int>(0, 0, 0, 0));

    // make array of dots
    for (int i = 20; i <= 475; i += 25) {
        for (int j = 25; j <= 480; j += 30) {
            ge211::Posn<int> pos {i, j};
            dots.push_back(ge211::Rect<int>(pos.x, pos.y, 6, 6));
        }
    }
}


void
Model::launch()
{
    pacman_.live = true;
}

void
Model::on_frame(double dt)
{
    // if pacman is live
    if (pacman_.live) {

        // find next pacman position
        Pacman next_pos = pacman_.next(dt);


        // if next_pos hits the bottom, set pacman velocity to {0,0}
        if (next_pos.hits_bottom()) {
            pacman_.velocity.height = 0;
            pacman_.velocity.width = 0;
            return;
        }
        // if next_pos hits the top, set pacman velocity to {0,0}
        if (next_pos.hits_top()) {
            pacman_.velocity.height = 0;
            pacman_.velocity.width = 0;
            return;
        }
        // if next_pos hits the side, set pacman velocity to {0,0}
        if (next_pos.hits_side()) {
            pacman_.velocity.height = 0;
            pacman_.velocity.width = 0;
            return;
        }
        // if next_pos destroys a dot, add one to dots eaten and don't change
        // velocity
        if (next_pos.destroy_dot(dots)) {
            pacman_.velocity.width += 0;
            dots_eaten_ += 1;
        }
        //actually move to next pacman
        pacman_ = pacman_.next(dt);
    }

}

