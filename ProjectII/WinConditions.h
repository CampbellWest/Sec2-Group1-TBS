#pragma once

#include "Hand.h"
#include "Cards.h"

typedef enum multiplier {
	LOSS = -1, TIE = 0, WIN = 1, SPECIAL_WIN = 2
}MULTIPLIER;

MULTIPLIER pickWinner(HAND* dealer, HAND* player);