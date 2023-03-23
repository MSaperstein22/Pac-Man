#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    // constructs a controller
    Controller();

    // defines how game responds to key events
    void on_key(ge211::Key key) override;

    // updates the game state to reflect passage of time
    void on_frame(double dt) override;

    // public function to access private member model_
    Model model(){
        return model_;
    }

protected:

    // called to ask the game what should appear on the screen
    void draw(ge211::Sprite_set& set) override;

private:
    // private members model_ and view_ to access in controller.cxx
    Model model_;
    View view_;

};
