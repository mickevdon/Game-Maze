#include "Level.h"
//create final sprite which will be used in all levels
const int final_sprite[3][3] = {
{ 1,0,1 },
{ 0,1,0 },
{ 1,0,1 },
};

//function to draw borders
void borders(N5110 &lcd) {
    lcd.drawRect(0,0,84,2,FILL_BLACK); // top
    lcd.drawRect(0,46,84,2,FILL_BLACK); //bottom
    lcd.drawRect(0,0,2,48,FILL_BLACK); //left
    lcd.drawRect(82,0,2,48,FILL_BLACK); //right
}
       
Level::Level() {
 
}
 
Level::~Level() {
 
}

void Level::init(int lvl) {
    _level_number = lvl; // set level which is currently in play
    //printf("Level _level_number = %d\n", _level_number);
    create_start_and_final(); //update start and final coordinates
}

void Level::create_start_and_final() {    
    Vector2D start;
    Vector2D final;
// Change start and finish coordinates according to chosen level
    switch (_level_number) {
    case 1:{        
        start.x = 5; start.y = 5;
        final.x = 72; final.y = 38;
        set_start(start);
        set_final(final); 
        break;}
    case 2:{
        start.x = 70; start.y = 5;
        final.x = 7; final.y = 6;
        set_start(start);
        set_final(final); 
        break;}
    case 3:{
      start.x = 6; start.y = 5;
        final.x = 76; final.y = 6;
        set_start(start);
        set_final(final);
        break;}
    case 4:{
       start.x = 6; start.y = 5;
        final.x = 74; final.y = 41;
        set_start(start);
        set_final(final); 
        break;}
    case 5:{
        start.x = 74; start.y = 38;
        final.x = 46; final.y = 29;
        set_start(start);
        set_final(final);    
        break;}
        };
 //printf("Creating start X = %f  Y = %f\n", start.x, start.y);
 //printf("Creating Final X = %f  Y = %f\n", final.x, final.y);
 //printf("Current level in creation function: %d",_level_number);       
}
    
void Level::draw(N5110 &lcd) {
    // printf("Level to draw = %d\n", get_level());    
    //Draw walls according to chosen level    
    switch (get_level()) {
    case 1:        
        {create_walls_1(lcd); break;}
    case 2:
        {create_walls_2(lcd); break;}
    case 3:
        {create_walls_3(lcd); break;}
    case 4:
        {create_walls_4(lcd); break;}
    case 5:
        {create_walls_5(lcd); break;}  
    };       
}
void Level::create_final_sprite(N5110 &lcd) {
    Vector2D destination = get_final(); // put final coordinates in 2D vector
    //draw final sprite
    lcd.drawSprite(destination.x-1,destination.y-1,3,3,(int *)final_sprite); // subtract 1 pixel from x and y because final point is centre of final sprite  
}
void Level::create_walls_1(N5110 &lcd) {
    borders(lcd);//draw borders
    create_final_sprite(lcd);//draw final sprite
    //draw walls
    lcd.drawRect(16,2,3,30,FILL_BLACK);
}
void Level::create_walls_2(N5110 &lcd) {
    borders(lcd);//draw borders
    create_final_sprite(lcd);//draw final sprite
    //draw walls
    lcd.drawRect(2,16,26,4,FILL_BLACK);
    lcd.drawRect(38,2,4,36,FILL_BLACK); 
    lcd.drawRect(57,13,25,4,FILL_BLACK);  
}
void Level::create_walls_3(N5110 &lcd) {
    borders(lcd);//draw borders
    create_final_sprite(lcd);//draw final sprite
    //draw walls
    lcd.drawRect(15,2,4,34,FILL_BLACK);
    lcd.drawRect(33,10,4,37,FILL_BLACK);
    lcd.drawRect(51,2,4,34,FILL_BLACK);
    lcd.drawRect(51,32,14,4,FILL_BLACK);
    lcd.drawRect(12,33,14,4,FILL_BLACK);
    lcd.drawRect(66,11,17,4,FILL_BLACK); 
}
void Level::create_walls_4(N5110 &lcd) {
    borders(lcd);//draw borders
    create_final_sprite(lcd);//draw final sprite
    //draw walls
    lcd.drawRect(2,14,51,4,FILL_BLACK);
    lcd.drawRect(66,11,16,4,FILL_BLACK);
    lcd.drawRect(19,28,63,4,FILL_BLACK);
    lcd.drawRect(2,28,7,4,FILL_BLACK);
    lcd.drawRect(36,1,4,4,FILL_BLACK);
    lcd.drawRect(32,17,4,4,FILL_BLACK);
    lcd.drawRect(43,25,4,4,FILL_BLACK);
    lcd.drawRect(24,32,4,4,FILL_BLACK);
    lcd.drawRect(48,32,4,4,FILL_BLACK);
    lcd.drawRect(66,32,4,4,FILL_BLACK);
    lcd.drawRect(36,42,4,4,FILL_BLACK);
    lcd.drawRect(58,42,4,4,FILL_BLACK);
}
void Level::create_walls_5(N5110 &lcd) {
    borders(lcd);//draw borders
    create_final_sprite(lcd);//draw final sprite
    //draw walls
    lcd.drawRect(64,12,4,34,FILL_BLACK);
    lcd.drawRect(14,11,54,4,FILL_BLACK);
    lcd.drawRect(14,14,4,23,FILL_BLACK);
    lcd.drawRect(14,34,38,4,FILL_BLACK);
    lcd.drawRect(51,23,4,15,FILL_BLACK);
    lcd.drawRect(27,21,28,4,FILL_BLACK);
    lcd.drawRect(27,25,4,2,FILL_BLACK);
    lcd.drawRect(38,25,4,2,FILL_BLACK);
    lcd.drawRect(38,32,4,2,FILL_BLACK);    
}
int Level::get_level() {
    int lvl = _level_number;
    return lvl;    
}
void Level::set_final (Vector2D final) {
     _final = final;
}
Vector2D Level::get_final() {
    Vector2D f =  {_final.x, _final.y};
    return f;
}
void Level::set_start (Vector2D start) {
     _start = start;
}
Vector2D Level::get_start() {
    Vector2D s =  {_start.x, _start.y};
    return s;
}
