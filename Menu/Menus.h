#ifndef MENUS_H
#define MENUS_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Melodies.h"
/** Menus Class
@author Donatas Mickevicius, University of Leeds
@brief Menu interactions
@date May 2020
*/

class Menus
{
    
public:
    //*Constructor*/
    Menus();
    
    //*Destructor*/
    ~Menus();
    
    /** Sets initial option and level to 1*/    
    void init();
    
    /** Draws main menu and controls arrow which points to Play Game/Instructions. Choose is made by joystick and A button.
    * @param lcd  N5110 LCD object
    * @param pad  Gamepad object
    */
    void main_menu(N5110 &lcd, Gamepad &pad);

    /** Draws instruction menu. Exit by pressing X.
    * @param lcd  N5110 LCD object
    * @param pad  Gamepad object
    */   
    void instructions(N5110 &lcd, Gamepad &pad);
    
    /** Draws choosing level menu and allows to select level. Choose is made by joystick and B button.
    * @param lcd  N5110 LCD object
    * @param pad  Gamepad object
    */
    void choose_level(N5110 &lcd, Gamepad &pad);
    
    /** Sequence if player reached final destination
    * @param lcd  N5110 LCD object
    * @param pad  Gamepad object
    */    
    void win(N5110 &lcd, Gamepad &pad);
    
    /** Sequence if player hit the wall
    * @param lcd  N5110 LCD object
    * @param pad  Gamepad object
    */  
    void lose(N5110 &lcd, Gamepad &pad);

    //--------------Accessors and mutators----------------
    
    /** Gets selected level
    * @return Selected level
    */         
    int get_chosen_level();
    
     /** Sets level that will be played
    * @param chosen_level  Integer value to choose level
    */     
    void set_chosen_level(int chosen_level);
    
    /** Gets selected option from main menu i.e Play Game/Instructions
    * @return Selected level
    */       
    int get_option();
    
    /** Sets option from main menu i.e Play Game/Instructions
    * @param option  Integer value for selected option
    */
    void set_option(int option);
    
private:
    // Controls arrow movement in main menu
    void arrow_movement(Gamepad &pad, N5110 &lcd, int &option);
    
    // Changes level on printed on screen
    void update_level_on_screen(Gamepad &pad, N5110 &lcd, int &l);
    
    int _chosen_level; // selected level
    int _option; // selected option
};
#endif //MENUS_H