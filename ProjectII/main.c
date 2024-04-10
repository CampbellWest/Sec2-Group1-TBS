#include <stdio.h>﻿
#include "Cards.h"
#include "Hand.h"
#include "menu.h"

#include "Animation.h"

int main(int argc, char* argv[]) {


    //TODO
    //login();
    srand(time(NULL));
    User player = CreateNewUser();

    if (argc == 2) {
        //enable cheat mode

        //Menu(&player, argv[1]); //use command line input as mode indicator
        //return 0;
        int m = atoi(argv[1]);
        changeDrawMode(m);
    }

    Menu(&player, 0); //default mode

    return 0;
}

//checking ace 
//if there is one make 2 variables for 2 totals and if one total is over 21 use the other variable
//if they are both under 21 use higher if there is not hit 
// and if there is a hit add hit to each of them and keep checking if one of them is over 21 
// 
// In the event you draw 5 cards to a hand without exceeding 21, 
// you automatically win and the Dealer will pay you even money