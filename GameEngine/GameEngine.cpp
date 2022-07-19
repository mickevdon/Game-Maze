#include "GameEngine.h"
 
GameEngine::GameEngine() {
 
}
 
GameEngine::~GameEngine() {
 
}

void GameEngine::labyrinth_loop(int level, int &finish, int &collision, int fps, N5110 &lcd, FXOS8700CQ &device, Gamepad pad) {
    int n = sizeof(note_lab)/sizeof(int); //Melody length
    pad.play_melody(n,note_lab,duration_lab,160,true);    //Play lab melody
    
    init(level); // Initialise chosen level from menu
    finish = 0;// Set to 0 i.e. final destination have not been reached
    collision = 0;// Set to 0 i.e. ball have not hit the wall
    lcd.clear();
    
    // short delay before ball start to move in order to get ready
    _level.draw(lcd); //draw level walls
    _ball.draw(lcd);//draw ball
    lcd.refresh();
    wait(1.25);   
    lcd.clear();
    
    while(1) {            
        _level.draw(lcd);//draw level walls
        read_input(device);//read data from accelerometer        
        _ball.update(get_pitch(), get_roll());// update ball coordinates
        check_final(finish);// check wheter final reached before checking for collision with wall
        if (finish == 1) break;// break if final has been reached
        check_collision(lcd,collision);// check  for collision with walls
        if(collision == 1) break;// break if ball have hit wall
        _ball.draw(lcd);//draw ball
        lcd.refresh();
        lcd.clear();
        wait(1.0f/fps);      
    }
}

void GameEngine::read_input(FXOS8700CQ &device) {
    // get roll and pitch angles
    Data values = device.get_values();
        _pitch = device.get_pitch_angle();
        _roll = device.get_roll_angle();
    //  printf("Pitch = %f Roll = %f\n",_pitch,_roll);
}

float GameEngine::get_roll() {
    float r = _roll;
    return r;
}

float GameEngine::get_pitch() {
    float p = _pitch;
    return p;    
}
   
void GameEngine::init(int level) {
    _current_level = level;
   // printf("Current level: %d",_current_level);
     _level.init(_current_level);
     Vector2D start = _level.get_start();
   // printf("Start position: X = %f Y = %f",start.x, start.y);  
     _ball.init(3, start.x,start.y);
}
void GameEngine::check_final(int &reach_final) {
    reach_final = 0;// value of 0 i.e. final sprite not reached    
    //Checks whether ball have reached final sprite (X symbol)    
    //Get final destination coordinates and create 2D vectors to checks every pixel of final sprite
    Vector2D destination = _level.get_final();// centre
    Vector2D destination1 = {destination.x-1,destination.y-1};// top left
    Vector2D destination2 = {destination.x+1,destination.y-1};// top right
    Vector2D destination3 = {destination.x-1,destination.y+1};// bottom left
    Vector2D destination4 = {destination.x+1,destination.y+1};// bottom right
    //printf("Destination X = %f Y = %f", destination.x, destination.y);
    //Check whether ball have reached final sprite
    if (check_final_pixel(destination) == true) {reach_final=1; /*printf("Reached centre");*/}
    else if (check_final_pixel(destination1) == true) {reach_final=1; /*printf("Reached top left");*/}
    else if (check_final_pixel(destination2) == true) {reach_final=1; /*printf("Reached top right");*/}
    else if (check_final_pixel(destination3) == true) {reach_final=1; /*printf("Reached bottom left");*/}
    else if (check_final_pixel(destination4) == true) {reach_final=1; /*printf("Reached bottom right");*/}      
}

bool GameEngine::check_final_pixel(Vector2D destination) {
    //compares every ball pixel to a single pixel of final sprite
    bool finish = false; // Set to false i.e. not reached final pixel
    Vector2D position = _ball.get_position(); //Put ball position into 2D vector
    //printf("Ball position (check final pixel) X = %f Y = %f\n", _ball.get_position().x, _ball.get_position().y);
    if ( position.x == destination.x && position.y == destination.y ) {finish = true; /*printf("Ball top left pixel");*/}
    else if ( position.x+1 == destination.x && position.y == destination.y) {finish = true; /*printf("Ball top middle pixel");*/} 
    else if ( position.x+2 == destination.x && position.y == destination.y) {finish = true; /*printf("Ball top left pixel");*/}
    else if ( position.x == destination.x && position.y+1 == destination.y) {finish = true; /*printf("Ball middle left pixel");*/}
    else if ( position.x+1 == destination.x && position.y+1 == destination.y) {finish = true; /*printf("Ball centre pixel");*/}
    else if ( position.x+2 == destination.x && position.y+1 == destination.y) {finish = true; /*printf("Ball middle right pixel");*/}
    else if ( position.x == destination.x && position.y+2 == destination.y) {finish = true; /*printf("Ball bottom left pixel");*/}
    else if ( position.x+1 == destination.x && position.y+2 == destination.y) {finish = true; /*printf("Ball bottom middle pixel");*/}
    else if ( position.x+2 == destination.x && position.y+2 == destination.y) {finish = true; /*printf("Ball bottom right pixel");*/}
    return finish;            
}  

void GameEngine::check_collision (N5110 &lcd, int &col) {
    col = 0;// value of 0 i.e. ball have not touched wall
    Vector2D position = _ball.get_position();
    //printf("Ball position (check collision) X = %f Y = %f\n", _ball.get_position().x, _ball.get_position().y);
    //Check if any of the ball pixels touched the wall
    if(lcd.getPixel(position.x,position.y) ) {col = 1; /*printf("Ball top left pixel");*/}
    else if(lcd.getPixel(position.x+1,position.y) ) {col = 1; /*printf("Ball top middle pixel");*/} 
    else if(lcd.getPixel(position.x+2,position.y) ) {col = 1; /*printf("Ball top left pixel");*/}
    else if(lcd.getPixel(position.x,position.y+1) ) {col = 1; /*printf("Ball middle left pixel");*/}
    else if(lcd.getPixel(position.x+1,position.y+1) ) {col = 1; /*printf("Ball centre pixel");*/}
    else if(lcd.getPixel(position.x+2,position.y+1) ) {col = 1; /*printf("Ball middle right pixel");*/}
    else if(lcd.getPixel(position.x,position.y+2)  ) {col = 1; /*printf("Ball bottom left pixel");*/}
    else if(lcd.getPixel(position.x+1,position.y+2) ) {col = 1; /*printf("Ball bottom middle pixel");*/}
    else if(lcd.getPixel(position.x+2,position.y+2) ) {col = 1; /*printf("Ball bottom right pixel");*/}
}

         