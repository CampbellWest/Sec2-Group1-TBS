#include "WinConditions.h"

MULTIPLIER pickWinner(HAND dealer, HAND player) {

    if (player.hand_status == BUST){
        red();
        printf("\nYou lost! :(\n");
        reset();
        return LOSS;
    }

    if (dealer.hand_status == BUST) {
        green();
        printf("You won!\n");
        reset();
        return WIN;
    }

    if (player.hand_status == BLACKJACK) {
        if (dealer.hand_status == BLACKJACK) {
            yellow();
            printf("Push! :/\n");
            reset();
            return TIE;
        }
        yellow();
        printf(" **************\n *");
        reset();
        printf(" BLACKJACK! ");
        yellow();
        printf("*\n **************\n");
        reset();
        return SPECIAL_WIN;
    }
    else if (dealer.hand_status == BLACKJACK) {
        red();
        printf("You lost! :(\n");
        reset();
        return LOSS;
    }
    else {
        if (dealer.totalCardValue == player.totalCardValue) {
            yellow();
            printf("Push! :/\n");
            reset();
            return TIE;
        }
        else if (dealer.totalCardValue > player.totalCardValue) {
            red();
            printf("You lost! :(\n");
            reset();
            return LOSS;
        }
        else {
            green();
            printf("You won! :D\n");
            reset();
            return WIN;
        }
    }
}