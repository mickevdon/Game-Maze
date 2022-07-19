#include "Ball.h"
 
Ball::Ball() {
 
}
 
Ball::~Ball() {
 
}
 
void Ball::init(int size, int initial_x, int initial_y) {
    _size = size;
    _x = initial_x;
    _y = initial_y;
    //printf(" Size = %d Initial_x = %d Initial_y = %d\n", _size, _x, _y);
}
 
void Ball::draw(N5110 &lcd) {
    lcd.drawRect(_x,_y,_size,_size,FILL_BLACK);
}
      
void Ball::update(float pitch, float roll) {
    //Update Y coordinate which is controlled by pitch angle
    if (pitch > 0 ) _y--;
    else if (pitch < -0) _y++;
    
    //Update X coordinate which is controlled by roll angle
    if (roll > 0 ) _x++;
    else if (roll <-0) _x--;  
    
    //  printf("Ball update X = %d Y= %d\n", _x, _y); 
 }
Vector2D Ball::get_position() {
    Vector2D p = {_x,_y};
    return p;
     //  printf("PX = %d PY= %d\n", p.x, p.y); 
}
 
void Ball::set_position(Vector2D p) {
    _x = p.x;
    _y = p.y;
    //  printf("Set_X = %d Set_Y= %d\n", _x, _y);
}
            