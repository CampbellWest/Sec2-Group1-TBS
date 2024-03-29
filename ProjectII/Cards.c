

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
    if (flag && flag - 1 < DECKNUM && flag > 0) {   // [1,52]
        index = flag - 1;
        c = &(d->cards[index]);
    }
    else {
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



//#include "Cards.h"
//
//void printDealerCards(CARDS* card) {
//    printf("+====+==========+\n");
//    printf("| ");
//    printCardValue(card->cardsForPrint[0]);
//    printf(" | +======+ | \n");
//    printf("|    | |      | |\n");
//    printf("|    | |      | |\n");
//    printf("|    | |      | |\n");
//    printf("|    | |      | |\n");
//    printf("|    | |      | |\n");
//    printf("|    | |      | |\n");
//    printf("|    | +======+ |\n");
//    printf("+====+==========+\n");
//    printf("\n\n\n");
//}
//
//void printTwoCards(CARDS* card) {
//    printf("+====+==========+\n");
//    printf("| ");
//    printCardValue(card->cardsForPrint[0]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[1]);
//    printf("       | \n");
//    printf("|    |          |\n");
//    printf("|    |          |\n");
//    printf("|    |    /\\    |\n");
//    printf("|    |    \\/    |\n");
//    printf("|    |          |\n");
//    printf("|    |          |\n");
//    printf("|    |        ");
//    printCardValue(card->cardsForPrint[1]);
//    printf("| \n");
//    printf("+====+==========+\n");
//    printf("\n\n\n");
//}
//
//void printThreeCards(CARDS* card) {
//    printf("+====+====+==========+\n");
//    printf("| ");
//    printCardValue(card->cardsForPrint[0]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[1]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[2]);
//    printf("       |\n");
//    printf("|    |    |          |\n");
//    printf("|    |    |          |\n");
//    printf("|    |    |    /\\    |\n");
//    printf("|    |    |    \\/    |\n");
//    printf("|    |    |          |\n");
//    printf("|    |    |          |\n");
//    printf("|    |    |        ");
//    printCardValue(card->cardsForPrint[2]);
//    printf("|\n");
//    printf("+====+====+==========+\n");
//    printf("\n\n\n");
//}
//
//void printFourCards(CARDS* card) {
//    printf("+====+====+====+==========+\n");
//    printf("| ");
//    printCardValue(card->cardsForPrint[0]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[1]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[2]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[3]);
//    printf("       |\n");
//    printf("|    |    |    |          |\n");
//    printf("|    |    |    |          |\n");
//    printf("|    |    |    |    /\\    |\n");
//    printf("|    |    |    |    \\/    |\n");
//    printf("|    |    |    |          |\n");
//    printf("|    |    |    |          |\n");
//    printf("|    |    |    |        ");
//    printCardValue(card->cardsForPrint[3]);
//    printf("|\n");
//    printf("+====+====+====+==========+\n");
//    printf("\n\n\n");
//}
//
//void printFiveCards(CARDS* card) {
//    printf("+====+====+====+====+==========+\n");
//    printf("| ");
//    printCardValue(card->cardsForPrint[0]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[1]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[2]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[3]);
//    printf(" | ");
//    printCardValue(card->cardsForPrint[4]);
//    printf("       |\n");
//    printf("|    |    |    |    |          |\n");
//    printf("|    |    |    |    |          |\n");
//    printf("|    |    |    |    |    /\\    |\n");
//    printf("|    |    |    |    |    \\/    |\n");
//    printf("|    |    |    |    |          |\n");
//    printf("|    |    |    |    |          |\n");
//    printf("|    |    |    |    |        ");
//    printCardValue(card->cardsForPrint[4]);
//    printf("|\n");
//    printf("+====+====+====+====+==========+\n");
//    printf("\n\n\n");
//}
//
//void printCardValue(int card) {
//    switch (card) {
//    case 1:
//        printf("A ");
//        break;
//    case 11:
//        printf("J ");
//        break;
//    case 12:
//        printf("Q ");
//        break;
//    case 13:
//        printf("K ");
//        break;
//    case 10:
//        printf("%i", card);
//        break;
//    default:
//        printf("%i ", card);
//        break;
//    }
//}
//
//void printDealerHits(CARDS* dealer, CARDS* player) {
//    system("cls");
//    switch (dealer->numberOfCards) {
//    case 2:
//        printTwoCards(dealer);
//        printPlayerHits(player);
//        break;
//    case 3:
//        printThreeCards(dealer);
//        printPlayerHits(player);
//        break;
//    case 4:
//        printFourCards(dealer);
//        printPlayerHits(player);
//        break;
//    case 5:
//        printFiveCards(dealer);
//        printPlayerHits(player);
//        break;
//    }
//}
//
//void printPlayerHits(CARDS* player) {
//
//    switch (player->numberOfCards) {
//    case 2:
//        printTwoCards(player);
//        break;
//    case 3:
//        printThreeCards(player);
//        break;
//    case 4:
//        printFourCards(player);
//        break;
//    case 5:
//        printFiveCards(player);
//        break;
//    }
//}