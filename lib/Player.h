#ifndef PLAYER_H
#define PLAYER_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"

class Player
{
public:

    Player();
    void init(int x,int height,int width);
    void draw(N5110 &lcd);
    void update(UserInput input);
    void add_score();
    int get_score();
    Position2D get_pos();
    int get_height();
    int get_width();

private:

    int _height;
    int _width;
    int _x;
    int _y;
    int _speed;
    int _score;

};
#endif