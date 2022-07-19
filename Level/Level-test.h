#ifndef LEVEL_TEST_H
#define LEVEL_TEST_H
/**
 * @brief Check that Level generates starting/finish positions and correctly draws final sprite
 * 
 * @returns true if all the tests passed
 */
//-------------------------------------
 bool Level_test (N5110 &lcd);
 bool Level_test_start_final();
 bool Level_test_final_sprite(N5110 &lcd);
//-------------------------------------
bool Level_test (N5110 &lcd){
    bool passed = true;
    if(!Level_test_start_final()) passed = false;
    if(!Level_test_final_sprite(lcd)) passed = false;
    return passed;
}
bool Level_test_start_final(){
    int number_of_tests_failed = 0;
    //create level objects
    Level level_1;
    Level level_2;
    Level level_3;
    Level level_4;
    Level level_5;    
    //Initialise level i.e creates start and finish coordinates
    level_1.init(1);
    level_2.init(2);    
    level_3.init(3);
    level_4.init(4);    
    level_5.init(5);
    //Check if levels was correctly initialised
    if (!(level_1.get_start().x == 5 && level_1.get_start().y == 5 && level_1.get_final().x == 72 && level_1.get_final().y == 38 )) {
          number_of_tests_failed ++;
          printf("Level 1 start/final generation error\n");
    }
    if (!(level_2.get_start().x == 70 && level_2.get_start().y == 5 && level_2.get_final().x == 7 && level_2.get_final().y == 6 )) {
          number_of_tests_failed ++;
          printf("Level 2 start/final generation error\n");
    }    
    if (!(level_3.get_start().x == 6 && level_3.get_start().y == 5 && level_3.get_final().x == 76 && level_3.get_final().y == 6 )) {
          number_of_tests_failed ++;
          printf("Level 3 start/final generation error\n");
    }
    if (!(level_4.get_start().x == 6 && level_4.get_start().y == 5 && level_4.get_final().x == 74 && level_4.get_final().y == 41 )) {
          number_of_tests_failed ++;
          printf("Level 4 start/final generation error\n");
    }    
    if (!(level_5.get_start().x == 74 && level_5.get_start().y == 38 && level_5.get_final().x == 46 && level_5.get_final().y == 29 )) {
          number_of_tests_failed ++;
          printf("Level 5 start/final generation error\n");
    }    
        
    //Check if all tests passed
    if(number_of_tests_failed == 0) return true;
    else return false;
}

bool Level_test_final_sprite(N5110 &lcd){
    int number_of_wrong_pixels = 0;
    //Testing if final sprite is generated for X level (in this example level 5)
    Level level;    
    level.init(5); //Final coordinates 46/29
    lcd.clear();
    level.create_final_sprite(lcd);
    lcd.refresh();
    //Check if correct pixel is set
    if(!lcd.getPixel(46,29)) {
        number_of_wrong_pixels++;
        printf("Centre pixel not set\n");
    }
    if(!lcd.getPixel(45,28)) {
        number_of_wrong_pixels++;
        printf("Top left pixel not set\n");
    }
    if(!lcd.getPixel(47,28)) {
        number_of_wrong_pixels++;
        printf("Top right pixel not set\n");
    }
    if(!lcd.getPixel(45,30)) {
        number_of_wrong_pixels++;
        printf("Bottom left pixel not set\n");
    }
    if(!lcd.getPixel(47,30)) {
        number_of_wrong_pixels++;
        printf("Bottom right pixel not set\n");
    }
    lcd.clear();
    //Check if all tests passed
    if(number_of_wrong_pixels == 0) return true;
    else return false;
}
#endif