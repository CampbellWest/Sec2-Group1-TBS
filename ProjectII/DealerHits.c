#include "Hand.h"

void dealerHits(DECK* deck, HAND* dealer, HAND player) {

    do {
        if (dealer->totalCardValue >= 17) {
            return;
        }

        Draw(&dealer, &deck, 0, 1);



    } while (dealer->totalCardValue < 17 || dealer->totalCardValue < player.totalCardValue);
}