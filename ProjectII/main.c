#include <stdio.h>﻿
#include "Cards.h"
#include "Hand.h"
#include "menu.h"

#include "Animation.h"

// command line argv used for mode
// DEFAULTMODE - 0
// TESTMODE - 1  also dealer win mode
// WINMODE - 2  user ez win
// SKYNET - 3

int main(int argc, char* argv[]) {

    srand(time(NULL));
    User player = CreateNewUser();

    if (argc == 2) {
        //enable cheat mode

        int m = atoi(argv[1]);
        changeDrawMode(m);
        if (m == SKYNET) {
            //drawBust();
            draw_big_image();
            Sleep(2000);
            red();
            printf("\n\n        SKYNET AI ACTIVATED\n\n");
            reset();
            Sleep(2000);
        }
    }

    Menu(&player, 0); //default mode
    
    return 0;
}