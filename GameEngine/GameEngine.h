#ifndef GAMEENGINE_H
#define GAMEENGINE_H
 
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Ball.h"
#include "Level.h"
#include "FXOS8700CQ.h"
#include "Melodies.h"

/** GameEngine Class
@author Donatas Mickevicius, University of Leeds
@brief Controls main game loop 
@date April 2020
*/

class GameEngine
{
    
public:
    //*Constructor*/
    GameEngine();
    
    //*Destructor*/    
    ~GameEngine();
    
    /** Main game loop
    * @param level  Chosen level
    * @param finish  Ball have reached final or not, values 1/0 respectively
    * @param collision  Ball have hit wall or not, values 1/0 respectively
    * @param fps Frames per second
    * @param lcd N5110 LCD object
    * @param device  FXOS8700CQ accelerometer 
    * @param pad  Gamepad object 
    */
    void labyrinth_loop(int level,int &finish, int &collision, int fps, N5110 &lcd, FXOS8700CQ &device, Gamepad pad);

    //--------------Accessors and mutators----------------
    
    /** Reads data from accelerometer and sets roll,pitch values
    * @param device  FXOS8700CQ accelerometer
    */        
    void read_input(FXOS8700CQ &device);
    
     /** Get roll angle in degrees
    * @return  Roll angle in degrees
    */       
    float get_roll();
    
     /** Get pitch angle in degrees
    * @return  Pitch angle in degrees
    */  
    float get_pitch();
    
private:
    // Initialises the Game engine (used in void labyrinth_loop) 
    void init(int level);
    
    // Checks whether the ball have reached final destination
    void check_final(int &reach_final);
    
    // Checks whether any ball pixel reached a single pixel of final sprite
    bool check_final_pixel(Vector2D destination);
    
    // Checks whether ball touched a wall
    void check_collision (N5110 &lcd, int &col);
        
    int _current_level; // Chosen level  
    float _roll;// Roll angle
    float _pitch;// Pitch angle
    
    Ball _ball;// Ball class object
    Level _level;// Level class object    
};

#endif //GAMEENGINE_H