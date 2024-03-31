#include "Cards.h"

CARD newCard(int value, SUIT suit) {
    CARD c;
    c.suit = suit;
    c.value = value;
    c.inDeck = true;
    return c;
}


DECK InitDeck() {
    DECK d = { 0 };
    //52 card
    for (int i = 0; i < DECKNUM; i++) {
        d.cards[i] = newCard((i % CARDOFONESUIT) + 1, i / CARDOFONESUIT);
    }
    return d;
}

CARD* DrawFromDeck(DECK* d, int flag) {

    CARD* c = NULL;
    int index;
    // flag != 0, debug mode, return a card as flag value
    if (flag && flag - 1 < DECKNUM && flag > 0) {   // [1,52]
        index = flag - 1;
        c = &(d->cards[index]);
    }
    else {
        // default mode, random card
        do {
            index = rand() % DECKNUM; //[0,51]
            c = &(d->cards[index]);

        } while (!c->inDeck); //if not in current deck(in hand), draw again

    }

    c->value = (index + 1) % 13;
    if (c->value == 0) //K
        c->value = 13;

    c->inDeck = false; //the card was draw

    return c;
}

//void ShuffleDeck(DECK* d) {
//    
//}