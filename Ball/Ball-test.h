#ifndef BALL_TEST_H
#define BALL_TEST_H
 
/**
 * @brief Check that Ball position changes depending on roll/pitch angles
 * 
 * @returns true if all the tests passed
 */
bool Ball_test_movement()
{
    int number_of_tests_failed = 0;
    // Initialise Ball object with a size of 3, and initial coordinates 43/23 and direction they will be tested
    // Centre of the ball will be center pixel of LCD
    Ball ball_NE;
    Ball ball_SE;
    Ball ball_SW;
    Ball ball_NW;
    
    ball_NE.init(3, 43, 23);
    ball_SE.init(3, 43, 23);
    ball_SW.init(3, 43, 23);
    ball_NW.init(3, 43, 23);
    
    // Read the initial positions
    Vector2D read_pos_initial_NE = ball_NE.get_position();
    Vector2D read_pos_initial_SE = ball_SE.get_position();
    Vector2D read_pos_initial_SW = ball_SW.get_position();
    Vector2D read_pos_initial_NW = ball_NW.get_position();
    
    printf(" Initial pos_NE %f, %f\n", read_pos_initial_NE.x, read_pos_initial_NE.y);
    printf(" Initial pos_SE %f, %f\n", read_pos_initial_SE.x, read_pos_initial_SE.y);
    printf(" Initial pos_SW %f, %f\n", read_pos_initial_SW.x, read_pos_initial_SW.y);
    printf(" Initial pos_NW %f, %f\n", read_pos_initial_NW.x, read_pos_initial_NW.y);
    
    //Ball will be moving in X direction
    //Angles in degrees accordingly {pitch (changes Y), roll (changes X)}
    float pitch_NE = 45; float roll_NE = 45;
    float pitch_SE = -45; float roll_SE = 45;
    float pitch_SW = -45; float roll_SW = -45;
    float pitch_NW = 45; float roll_NW = -45;

    
    //Ball will update for 5 loops
    for (int i = 0; i < 5; i++) {
        ball_NE.update(pitch_NE,roll_NE); 
        ball_SE.update(pitch_SE,roll_SE); 
        ball_SW.update(pitch_SW,roll_SW); 
        ball_NW.update(pitch_NW,roll_NW); 
    }
    
    printf(" Updated pos_NE %f, %f\n", ball_NE.get_position().x, ball_NE.get_position().y);
    printf(" Updated pos_SE %f, %f\n", ball_SE.get_position().x, ball_SE.get_position().y);
    printf(" Updated pos_SW %f, %f\n", ball_SW.get_position().x, ball_SW.get_position().y);
    printf(" Updated pos_NW %f, %f\n", ball_NW.get_position().x, ball_NW.get_position().y);
 
    //Checks if all tests passed
    if (!((ball_NE.get_position().x == read_pos_initial_NE.x + 5) && (ball_NE.get_position().y == read_pos_initial_NE.y - 5))) {
        number_of_tests_failed++;  
        printf("Ball_NE failed\n");
        }
    if (!((ball_SE.get_position().x == read_pos_initial_SE.x + 5) && (ball_SE.get_position().y == read_pos_initial_SE.y + 5))) {
        number_of_tests_failed++;  
        printf("Ball_SE failed\n");
        }    
    if (!((ball_SW.get_position().x == read_pos_initial_SW.x - 5) && (ball_SW.get_position().y == read_pos_initial_SW.y + 5))) {
        number_of_tests_failed++;  
        printf("Ball_SW failed\n");
        }
    if (!((ball_NW.get_position().x == read_pos_initial_NW.x - 5) && (ball_NW.get_position().y == read_pos_initial_NW.y - 5))) {
        number_of_tests_failed++;  
        printf("Ball_NW failed\n");
        }               
    if(number_of_tests_failed == 0) return true;
    else return false;
}
#endif