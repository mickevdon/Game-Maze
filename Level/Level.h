#ifndef LEVEL_H
#define LEVEL_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
/** Level Class
@author Donatas Mickevicius, University of Leeds
@brief Creates level
@date April 2020
*/

class Level
{
    
public:
    //*Constructor*/
    Level();
    
    //*Destructor*/
    ~Level();
    
    /** Initialises chosen level
    * @param level_number  Chosen level
    */    
    void init(int level_number);

    /** Sets start and final positions
    */     
    void create_start_and_final();
    
    /** Draws walls of the chosen level
    * @param lcd  N5110 LCD object
    */   
    void draw(N5110 &lcd);
    
    /** Draws final destination (X) on the screen
    * @param lcd  N5110 LCD object
    */  
    void create_final_sprite(N5110 &lcd);
    
    //--------------Accessors and mutators----------------
    
    /** Set chosen level
    * @param lvl  Chosen level number
    */          
    void set_level (int lvl);
    
    /** Get chosen level
    * @return Chosen level
    */    
    int get_level();
    
    /** Set final coordinates
    * @param final  Final coordinates(Vector2D)
    */      
    void set_final(Vector2D final);
    
    /** Get final coordinates
    * @return Final coordinates(Vector2D)
    */       
    Vector2D get_final();
     
    /** Set start coordinates
    * @param start  Start coordinates(Vector2D)
    */      
    void set_start(Vector2D start);

    /** Get start coordinates
    * @return Start coordinates(Vector2D)
    */           
    Vector2D get_start(); 
    
private:
    // Draws walls of 1st level  
    void create_walls_1(N5110 &lcd);
    
    // Draws walls of 2nd level         
    void create_walls_2(N5110 &lcd);
    
    // Draws walls of 3rd level     
    void create_walls_3(N5110 &lcd);
    
    // Draws walls of 4th level     
    void create_walls_4(N5110 &lcd);
    
    //Draws walls of 5th level    
    void create_walls_5(N5110 &lcd);
    
    int _level_number; // level number currently in play
    Vector2D _final; //final (destination) coordinates
    Vector2D _start;//initial ball coordinates
};
#endif //LEVEL_H