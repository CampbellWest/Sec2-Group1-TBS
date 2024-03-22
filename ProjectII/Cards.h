#pragma once

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>


#define _CRT_SECURE_NO_WARNINGS


// 1-13 spades
// 14-26 hearts
// 27-39 diamonds
// 40-52 clubs
#define DECKNUM 52
#define CARDOFONESUIT 13

typedef enum suit {
    SPADES, HEARTS, DIAMONDS, CLUBS
}SUIT;

typedef struct card {
    int value;
    SUIT suit;
    bool inDeck;
}CARD;


typedef struct deck {
    CARD cards[DECKNUM];
}DECK;

CARD newCard(int value, SUIT suit);

DECK InitDeck();

CARD* DrawFromDeck(DECK* d, int flag);

//void ShuffleDeck(DECK*);




//void printPlayerHits(CARDS* player);
//void printDealerHits(CARDS* dealer, CARDS* player);

//void printDealerCards(CARDS* dealer);
//void printTwoCards(CARDS* card);
//void printThreeCards(CARDS* card);
//void printFourCards(CARDS* card);
//void printFiveCards(CARDS* card);
//
//void printCardValue(int card);