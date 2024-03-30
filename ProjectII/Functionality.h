#pragma once

#include "Cards.h"

int readAccountBalance();
void writeAccountBalance(int accountBalance);

int getBetAmount(int accountBalance);

int playerHitsOrStands(CARDS* dealer, CARDS* player);
void dealerHitsOrStands(CARDS* dealer, CARDS* player);
void updateCardTotal(CARDS* card);

void pickWinner(CARDS* dealer, CARDS* player, int* accountBalance, int* betAmount);

extern bool Continue();
void clearBuffer();