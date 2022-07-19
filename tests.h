#ifndef TESTS_H
#define TESTS_H

#include "N5110.h"
#include "Ball-test.h"
#include "Level-test.h"
/**
 * @brief Run all the tests for this program
 *
 * @returns The number of tests that failed
 */
int run_all_tests(N5110 &lcd)
{    
    lcd.setContrast( pad.read_pot1());
    lcd.printString("RUNNING TESTS", 4, 2);
    lcd.refresh();
    wait(1.25);    
    int n_tests_failed = 0; // A log of the number of tests that have failed

    // Run the Ball_test_movement test
    printf("Testing Ball_test_movement...\n");
    bool this_test_passed = Ball_test_movement();

    // Print out the result of this test
    if (this_test_passed) {
        printf("...Passed!\n");
    }
    else {
        printf("...FAILED!\n");
        ++n_tests_failed; // Increment number of failures
    }
    
    //Run Level test
    printf("Testing Level_test...\n");
    this_test_passed = Level_test(lcd);

    // Print out the result of this test
    if (this_test_passed) {
        printf("...Passed!\n");
    }
    else {
        printf("...FAILED!\n");
        ++n_tests_failed; // Increment number of failures
    }

    // Summary of the tests
    if (n_tests_failed > 0) {
        printf("%d tests FAILED!\n", n_tests_failed);
    }
    else {
        printf("All tests passed!\n");
    }

    return n_tests_failed;
}

#endif //TESTS_H