#pragma once

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS

#define MAX_CARDS 5

typedef struct cards {
    int cardsForPrint[MAX_CARDS];
    int cardsValue[MAX_CARDS];
    int numberOfCards;
    int totalCardValue;
}CARDS;

void printPlayerHits(CARDS* player);
void printDealerHits(CARDS* dealer, CARDS* player);

void printDealerCards(CARDS* dealer);
void printTwoCards(CARDS* card);
void printThreeCards(CARDS* card);
void printFourCards(CARDS* card);
void printFiveCards(CARDS* card);

void printCardValue(int card);