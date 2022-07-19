#include "Menus.h"
void outer_walls_menu(N5110 &lcd) {
    //Draw outer walls
    lcd.drawRect(0,0,84,3,FILL_BLACK); // top
    lcd.drawRect(0,45,84,3,FILL_BLACK); //bottom
    lcd.drawRect(0,0,3,48,FILL_BLACK); //left
    lcd.drawRect(81,0,3,48,FILL_BLACK); //right
}

//Arror pointer used in main menu.
const int pointer[3][3] = {
    { 1,0,0 },
    { 1,1,0 },
    { 1,0,0 },
};

//Sprite to draw in instructions to show how final point looks like
const int f_sprite[3][3] = {
    { 1,0,1 },
    { 0,1,0 },
    { 1,0,1 },
};
//Sprite to draw in main menu (main menu look nicer)
const int labyrinth[9][12] = {
    { 1,1,1,1,1,1,1,1,1,1,1,1, },
    { 1,0,0,1,0,0,0,0,0,0,0,1, },
    { 1,0,0,0,0,0,0,1,0,0,0,1, },
    { 1,1,1,1,0,0,1,1,1,0,0,1, },
    { 0,0,0,1,0,0,0,0,1,0,1,1, },
    { 1,0,0,1,1,1,0,0,1,0,0,1, },
    { 1,0,0,1,0,0,0,0,1,0,0,1, },
    { 1,0,0,0,0,0,1,0,1,1,0,1, },
    { 1,1,1,1,1,1,1,1,1,1,1,1, },
};

Menus::Menus() {

}

Menus::~Menus() {

}

void Menus::init() {
    _chosen_level = 1;//Initialise as 1
    _option = 1;//Initialise as 1
}

void Menus::main_menu(N5110 &lcd, Gamepad &pad) {
    lcd.clear();
    int option = 1;//First selected option is 1
    while(!pad.A_pressed() && !pad.B_pressed() && !pad.X_pressed() && !pad.Y_pressed()) {
        lcd.setContrast( pad.read_pot1()); //change contrast
        pad.leds_on(); //flashing LEDs
        wait(0.3);
        pad.leds_off(); //flashing LEDs
        wait(0.3);
        outer_walls_menu(lcd); //draw borders
        lcd.drawSprite(68,7,9,12,(int *)labyrinth);
        lcd.printString("Labyrinth!",9,1);
        lcd.printString("Play game   ",9,3);
        lcd.printString("Instructions",8,4);
        lcd.drawRect(0,18,84,3,FILL_BLACK);
        arrow_movement(pad,lcd,option);//controls arrow position and draws it/returns selected option
        lcd.refresh();
        lcd.clear();
    }
    lcd.clear();
    set_option(option);
}

void Menus::instructions(N5110 &lcd, Gamepad &pad) {
    while(!pad.A_pressed() && !pad.B_pressed() && !pad.X_pressed() && !pad.Y_pressed()) {
        lcd.clear();
        lcd.drawRect(0,0,3,48,FILL_BLACK); //left
        lcd.drawRect(81,0,3,48,FILL_BLACK); //right
        lcd.printString("How to play:",8,0);
        lcd.printString("To controll",8,1);
        lcd.printString("ball tilt ",8,2);
        lcd.printString("gamepad ",8,3);
        lcd.printString("Avoid walls ",8,4);
        lcd.printString("Reach: ",8,5);
        lcd.drawSprite(44,42,3,3,(int *)f_sprite);//draw final sprite
        lcd.refresh();
    }
}

void Menus::choose_level(N5110 &lcd, Gamepad &pad) {
    lcd.clear();
    int l = 1; // initial level is 1
    while(!pad.A_pressed() && !pad.B_pressed() && !pad.X_pressed() && !pad.Y_pressed()) {
        outer_walls_menu(lcd); //Draw borders
        lcd.printString("Move joystick",4,1);
        lcd.printString("Up or down   ",4,2);
        lcd.printString("Press any key",4,3);
        update_level_on_screen(pad,lcd,l);//update level and print on screen
    }
    lcd.clear();
    set_chosen_level(l);// Change level that was chosen
}

void Menus::win(N5110 &lcd, Gamepad &pad) {
    lcd.clear();
    int n = sizeof(note_win)/sizeof(int); //Melody length
    pad.play_melody(n,note_win,duration_win,320,false);    //Play lose melody
    char buffer[14];
    outer_walls_menu(lcd);
    lcd.printString("You won! :)",8,1);
    lcd.printString("Going back",8,2);
    lcd.printString("in:",38,3);
    //Print sequence 3,2,1
    for(int i = 3; i>0; i--) {
        sprintf(buffer,"%d",i);
        lcd.printString(buffer,36,4);
        lcd.refresh();
        wait(1);
    }
}

void Menus::lose(N5110 &lcd, Gamepad &pad) {
    lcd.clear();
    int n = sizeof(note_lose)/sizeof(int); //Melody length
    pad.play_melody(n,note_lose,duration_lose,320,false);    //Play lose melody
    char buffer[14];
    outer_walls_menu(lcd);
    lcd.printString("You lost! :(",8,1);
    lcd.printString("Going back",8,2);
    lcd.printString("in:",38,3);
    //Print sequence 3,2,1
    for(int i = 3; i>0; i--) {
        sprintf(buffer,"%d",i);
        lcd.printString(buffer,38,4);
        lcd.refresh();
        wait(1);
    }
}

int Menus::get_chosen_level() {
    int l = _chosen_level;
    return l;
}

void Menus::set_chosen_level(int chosen_level) {
    _chosen_level = chosen_level;
}

int Menus::get_option() {
    int o = _option;
    return o;
}

void Menus::set_option(int option) {
    _option = option;
}

//Function for arrow movement
void Menus::arrow_movement(Gamepad &pad, N5110 &lcd, int &option) {
    //Check whether joystick have moved and change selection
    if(pad.get_direction() == N && option == 2) {
        option = 1;
        pad.tone(800,0.2);  // Play tone when pointer moves
    } else if (pad.get_direction() == S && option == 1) {
        option = 2;
        pad.tone(600,0.2);  // Play tone when pointer moves
    }
    // printf(" Option = %d",option);
    //Draw arrow which points to wanted selection
    if(option == 1) lcd.drawSprite(5,26,3,3,(int *)pointer);
    else if (option == 2) lcd.drawSprite(5,34,3,3,(int *)pointer);

}

//Function which interacts with joystick and will increase/decrease level
void Menus::update_level_on_screen(Gamepad &pad, N5110 &lcd, int &l) {
    // Move joysctick up or down to select level
    if(pad.get_direction() == N && l != 5) {
        l++; //Increase level number
        pad.tone(800,0.2);  // Play tone when pointer moves
    } else if (pad.get_direction() == S && l!= 1) {
        l--; //Decrease level number
        pad.tone(600,0.2);  // Play tone when pointer moves
    }
    // printf("Current level = %d",l); //Print level over serial to check if it changes
    //Convert selected level into string and print it
    char buffer[14];
    sprintf(buffer,"Level:%2d/5",l);
    lcd.printString(buffer,16,4);
    lcd.refresh();
    wait(0.3);
}