#include "WinConditions.h"

MULTIPLIER pickWinner(HAND dealer, HAND player) {

    if (player.hand_status == BUST || (dealer.hand_status == BUST && player.hand_status == BUST)) {
        printf("You lost! :(\n");
        return LOSS;
    }

    if (dealer.hand_status == BLACKJACK && player.hand_status == BLACKJACK) {
        printf("Push! :/\n");
        return TIE;
    }

    if (player.hand_status == BLACKJACK || player.numberOfCards == 5) {
        printf("BLACKJACK!\n");
        return SPECIAL_WIN;
    }

    if (dealer.hand_status == BUST && player.hand_status == NOTBUST) {
        printf("You won! :D\n");
        return WIN;
    }

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