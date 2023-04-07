#include "Player.h"

// nothing doing in the constructor and destructor
Player::Player() { }

void Player::init(int x,int height,int width) {
    printf("Player: Init\n");
    _x = x;  // x value on screen is fixed
    _y = HEIGHT/2 - height/2;  // y depends on height of screen and height of Player
    _height = height;
    _width = width;
    _speed = 1;  // default speed
    _score = 0;  // start score from zero
}

const int Fish[4][9]= {
    { 1,0,0,1,1,1,1,1,0, },
    { 1,1,1,1,1,1,1,0,1, },
    { 1,1,1,1,1,1,1,1,1, },
    { 1,0,0,1,1,1,1,1,0, },
};

void Player::draw(N5110 &lcd) { 
    printf("Player: Draw\n");
    lcd.drawSprite(30, 5, 4, 9, (int*)Fish); //_x,_y,_width,_height
}

void Player::update(UserInput input) {
    printf("Player: Update\n");
    _speed = 2;
    // update y value depending on direction of movement
    // North is decrement as origin is at the top-left so decreasing moves up
    if (input.d == N) { _y-=_speed; }
    else if (input.d == S) { _y+=_speed; }

    // check the y origin to ensure that the Player doesn't go off screen
    if (_y < 1) { _y = 1; }
    if (_y > HEIGHT - _height - 1) { _y = HEIGHT - _height - 1; }
}

void Player::add_score() { _score++; }

int Player::get_score() { return _score; }

Position2D Player::get_pos() { return {_x,_y}; }

int Player::get_height() { return _height; }

int Player::get_width() { return _width; }