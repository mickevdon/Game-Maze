#ifndef MELODIES_H
#define MELODIES_H

/**
 * @brief Contains melodies used it other classes
 */
 
//Win melody 300 bpm
const int note_win[] = {
    NOTE_G5, NOTE_B5, NOTE_D6, NOTE_G6, NOTE_B6,
    NOTE_GS5, NOTE_C6, NOTE_DS6, NOTE_GS6, NOTE_C7,
     NOTE_AS5, NOTE_D6, NOTE_F6, NOTE_AS6, NOTE_D7
};
const int duration_win[] = {
    2,4,4,4,2,2,4,4,4,2,2,4,4,4,2
};

//Lose melody 320 bpm
const int note_lose[] = {
    NOTE_G4, 0, NOTE_GS4, 0, NOTE_A4, 0,   NOTE_AS4, 0,
    NOTE_B4, 0, NOTE_C5, 0, NOTE_CS5, 0, NOTE_D5
};
const int duration_lose[] = {
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
};

//Labyrinth melody 160 bpm
const int note_lab[] = {
    NOTE_C6, NOTE_DS6, NOTE_G6, 0, NOTE_FS6, 0,
    NOTE_DS6, NOTE_F6, 0, NOTE_F6, 0, NOTE_C6,
    NOTE_DS6, 0, NOTE_F6, 0
};
 
const int duration_lab[] = {
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
};

#endif //MELODIES_H