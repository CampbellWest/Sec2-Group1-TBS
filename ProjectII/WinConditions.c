#include "WinConditions.h"

MULTIPLIER pickWinner(HAND dealer, HAND player) {

    if (player.hand_status == BUST){
        printf("You lost! :(\n");
        return LOSS;
    }

    if (dealer.hand_status == BUST) {
        printf("You won!\n");
        return WIN;
    }

    if (player.hand_status == BLACKJACK) {
        if (dealer.hand_status == BLACKJACK) {
            printf("Push! :/\n");
            return TIE;
        }
        printf("BLACKJACK!\n");
        return SPECIAL_WIN;
    }
    else if (dealer.hand_status == BLACKJACK) {
        printf("You lost! :(\n");
        return LOSS;
    }
    else {
        if (dealer.totalCardValue == player.totalCardValue) {
            printf("Push! :/\n");
            return TIE;
        }
        else if (dealer.totalCardValue > player.totalCardValue) {
            printf("You lost! :(\n");
            return LOSS;
        }
        else {
            printf("You won! :D\n");
            return WIN;
        }
    }
}