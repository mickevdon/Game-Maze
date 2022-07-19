/*
ELEC2645 Embedded Systems Project
School of Electronic & Electrical Engineering
University of Leeds
2019/20

Name: Donatas Mickevicius
Username: el18dm
Student ID Number: 201260463
Date: 10/03/2020
*/

//--------------includes----------------
#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "FXOS8700CQ.h"
#include "GameEngine.h"
#include "Menus.h"
//-------------------objects-----------------------
Gamepad pad;
N5110 lcd;
FXOS8700CQ device(I2C_SDA,I2C_SCL);
GameEngine game;
Menus menu;
//--------------function prototypes----------------

void init();
void game_loop(int fps);

//------------------testing------------------------

//#define WITH_TESTING
#ifdef WITH_TESTING
    #include "tests.h"
#endif

//-------------------------------------------------
int main()
{ 
    init(); //initialise all objects
   
#ifdef WITH_TESTING  
    int number_of_failures = run_all_tests(lcd);

    if(number_of_failures > 0) return number_of_failures;
#endif

    int fps = 8; //Set fps    
    game_loop(fps);//Play game i.e. Menu and labyrinth game interactions 
}

//-------------------------------------------------
void init(){
   lcd.init();
   pad.init();
   device.init();
   menu.init();
}

void game_loop(int fps) {
    while(1) {
         menu.main_menu(lcd,pad);//draw main menu
     switch (menu.get_option()){ //switch according to selected option in main menu (Play Game/Instructions)
    case 1:{
         menu.choose_level(lcd,pad);//draw level selection menu
         int finish = 0;//integer to check finish
         int collision = 0;//integer to check collision
         game.labyrinth_loop(menu.get_chosen_level(),finish,collision,fps,lcd,device,pad);//main labyrinth game loop
         lcd.clear();
         if(finish ==1) {
            menu.win(lcd,pad);//win sequence
         }
         if(collision ==1) {
            menu.lose(lcd,pad);//lose sequence
         }
         break;}         
    case 2:{
        menu.instructions(lcd,pad);//draws instruction menu
        break;}    
    };     
  }
}   
