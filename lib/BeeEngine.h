#ifndef BEE_ENGINE_H
#define BEE_ENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Ball.h"
#include "Utils.h"
#include "Player.h"

class BeeEngine {
    public:
        BeeEngine();  // pass in the lcd object from the main file
        void init(int paddle_position,int paddle_height,int paddle_width,int ball_size,int speed);
        int update(UserInput input);
        void draw(N5110 &lcd);
    private:
        void check_wall_collision();
        void check_paddle_collision();
        void check_goal();
        Ball _ball;
        Player _paddle;
        int _lives;
};

#endif