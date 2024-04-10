#include "Hand.h"

bool dealerHits(DECK* deck, HAND* dealer, HAND player) {

    // AI MODE  4/10
    if (getMode() == SKYNET) {
        while (dealer->totalCardValue < player.totalCardValue) {
            int safe = 21 - dealer->totalCardValue;
            if (safe >= 10) {
                Draw(dealer, deck, 0, 1);
                //int value = 1;
                //do {
                //    value = rand() % 4 + 10 + (rand() % 4) * 13; // +10
                //} while (!Draw(dealer, deck, value, 1));
            }
            else {
                int difference = player.totalCardValue - dealer->totalCardValue;
                int value = difference;
                do {
                    value = difference + rand()%2 + (rand() % 4) * 13; // + (1 or 0) + difference
                } while (!Draw(dealer, deck, value, 1));
            }
        }
        return true;
    }

    do {
        if (dealer->totalCardValue > player.totalCardValue || dealer->totalCardValue >= 17) {
            return true;
        }

        Draw(dealer, deck, 0, 1);

    } while (dealer->totalCardValue < 17 || dealer->totalCardValue < player.totalCardValue);
}