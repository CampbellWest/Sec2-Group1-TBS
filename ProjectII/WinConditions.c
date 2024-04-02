#include "WinConditions.h"

MULTIPLIER pickWinner(HAND dealer, HAND player) {

    if (player.hand_status == BUST || (dealer.hand_status == BUST && player.hand_status == BUST))
        return LOSS;

    if (dealer.hand_status == BLACKJACK && player.hand_status == BLACKJACK)
        return TIE;

    if (player.hand_status == BLACKJACK || player.numberOfCards == 5)
        return SPECIAL_WIN;

    if (dealer.hand_status == BUST && player.hand_status == NOTBUST)
        return WIN;

    if (dealer.totalCardValue == player.totalCardValue)
        return TIE;
    else if (dealer.totalCardValue > player.totalCardValue)
        return LOSS;
    else
        return WIN;
}