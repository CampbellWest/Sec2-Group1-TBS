#include "Hand.h"

bool dealerHits(DECK* deck, HAND* dealer, HAND player) {

    do {
        if (dealer->totalCardValue > player.totalCardValue || dealer->totalCardValue >= 17) {
            return true;
        }

        Draw(dealer, deck, 0, 1);

    } while (dealer->totalCardValue < 17 || dealer->totalCardValue < player.totalCardValue);
}