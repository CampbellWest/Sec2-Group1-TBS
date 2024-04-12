#pragma once

#include "Data.h"
#include "DealerHits.h"
#include "Hand.h"
#include "StreamIO.h"
#include "WinConditions.h"

void Hit(HAND*, DECK*, int, int);
void Stand(DECK*, HAND*, HAND);
void Split(HAND*);
bool VerifyBet(User, int);
unsigned int GetBet(User);
void PlaceBet(User*);
int BlackJack(void);