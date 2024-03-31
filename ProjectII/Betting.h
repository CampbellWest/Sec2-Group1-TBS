#pragma once

#include "Data.h"

void Hit(HAND*);
void Stand(HAND, HAND*);
void Split(HAND*);
bool VerifyBet(User, unsigned int);
unsigned int GetBet(User);
void PlaceBet(User*);
int BlackJack(void);