#include "model.hxx"
#include <catch.hxx>



TEST_CASE("Test Movement")
{
    Model m;
    CHECK(m.pacman2().live == false);
    CHECK(m.pacman2().velocity == Velocity{0,0});
    CHECK(m.pacman2().center ==  Position{25,25});
    m.pacman2().live = true;
    CHECK(m.pacman2().live == true);
    m.pacman2().velocity = Velocity{25,25};
    m.on_frame(1);
    CHECK(m.pacman2().center ==  Position{50,50});
}

TEST_CASE("Hits Top")
{
    Model m;
    CHECK(m.pacman2().live == false);
    CHECK(m.pacman2().velocity == Velocity{0,0});
    // set center to be (0, 0) and check that Pacman hits top and side
    m.pacman2().center = Position{0,0};
    m.pacman2().live = true;
    CHECK(m.pacman2().live == true);
    CHECK(m.pacman2().hits_top());
    CHECK(m.pacman2().hits_side());
    // set center to be (100, 0) and check that Pacman hits top
    m.pacman2().center = Position{100,0};
    CHECK(m.pacman2().hits_top());
    // set center to be (490, 0) and check that Pacman hits top
    m.pacman2().center = Position{490,0};
    CHECK(m.pacman2().hits_top());
}

TEST_CASE("Hits Left Side")
{

    Model m;
    CHECK(m.pacman2().live == false);
    CHECK(m.pacman2().velocity == Velocity {0, 0});
    m.pacman2().center = Position {0, 100};
    CHECK(m.pacman2().hits_side());
    m.pacman2().center = Position {0, 350};
    CHECK(m.pacman2().hits_side());

}

TEST_CASE("Hits Right Side")
{

    Model m;
    CHECK(m.pacman2().live == false);
    CHECK(m.pacman2().velocity == Velocity {0, 0});
    m.pacman2().center = Position {490, 100};
    CHECK(m.pacman2().hits_side());
    m.pacman2().center = Position {490, 350};
    CHECK(m.pacman2().hits_side());

}

TEST_CASE("Hits Bottom")
{
    Model m;
    CHECK(m.pacman2().live == false);
    CHECK(m.pacman2().velocity == Velocity{0,0});
    // set center to be (100, 490) and check that Pacman hits bottom
    m.pacman2().center = Position{100,490};
    m.pacman2().live = true;
    CHECK(m.pacman2().live == true);
    CHECK(m.pacman2().hits_bottom());
    // set center to be (300, 490) and check that Pacman hits top
    m.pacman2().center = Position{300,490};
    CHECK(m.pacman2().hits_bottom());
}


TEST_CASE("Hits Corner")
{
    Model m;
    CHECK(m.pacman2().live == false);
    CHECK(m.pacman2().velocity == Velocity{0,0});

    // set center to be (0, 0) and check that Pacman hits top and side
    // simultaneously
    m.pacman2().center = Position{0,0};
    m.pacman2().live = true;
    CHECK(m.pacman2().live == true);
    CHECK(m.pacman2().hits_top());
    CHECK(m.pacman2().hits_side());

    // set center to be (490, 0) and check that Pacman hits top and side
    // simultaneously
    m.pacman2().center = Position{490,0};
    m.pacman2().live = true;
    CHECK(m.pacman2().live == true);
    CHECK(m.pacman2().hits_top());
    CHECK(m.pacman2().hits_side());

    // set center to be (0, 490) and check that Pacman hits bottom and side
    // simultaneously
    m.pacman2().center = Position{0,490};
    m.pacman2().live = true;
    CHECK(m.pacman2().live == true);
    CHECK(m.pacman2().hits_bottom());
    CHECK(m.pacman2().hits_side());

    // set center to be (490, 490) and check that Pacman hits bottom and side
    // simultaneously
    m.pacman2().center = Position{490,490};
    m.pacman2().live = true;
    CHECK(m.pacman2().live == true);
    CHECK(m.pacman2().hits_bottom());
    CHECK(m.pacman2().hits_side());

}

TEST_CASE("Destroys Dots")
{
    Model m;
    CHECK(m.pacman2().live == false);
    CHECK(m.pacman2().velocity == Velocity {0, 0});
    m.pacman2().live = true;
    CHECK(m.pacman2().destroy_dot(m.dots));
    m.pacman2().center = Position{100,100};
    CHECK(m.pacman2().destroy_dot(m.dots));
    // move him back to original position and check that he doesn't destroy
    // a dot at that position (because it's already been destroyed)
    m.pacman2().center = Position{25, 25};
    CHECK(!m.pacman2().destroy_dot(m.dots));

}


