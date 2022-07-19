#ifndef BALL_H
#define BALL_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Ball Class
@author Donatas Mickevicius, University of Leeds
@brief Draws and controls the ball
@date April 2020
*/

class Ball
{

public:
    //*Constructor*/
    Ball();

    //*Destructor*/
    ~Ball();

    /** Initialises the Ball class
    * @param size  Size of the ball
    * @param initial_x  Initial x coordinate of the ball
    * @param initial_y  Initial y coordinate of the ball
    */
    void init(int size, int initial_x, int initial_y);

    /** Draws the ball on the screen
    * @param lcd  N5110 LCD object
    */
    void draw(N5110 &lcd);

    /** Updates ball x/y coordinates
    * @param pitch  Pitch angle in degrees
    * @param roll  Roll angle in degrees
    */
    void update(float pitch, float roll);

    //--------------Accessors and mutators----------------

    /** Return ball position as 2D vector
    * @return Ball coordinates
    */
    Vector2D get_position();

    /** Set ball position
     * @param p  Coordinates (Vector2D)
    */
    void set_position(Vector2D p);

private:
    int _x; //X coordinate of the ball   
    int _y; //Y coordinate of the ball
    int _size; //Size of the ball
};
#endif //BALL_H