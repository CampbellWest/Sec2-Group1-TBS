#pragma once

#include "Cards.h"
#include "Animation.h"


#define CARDSHARK {1,10,11,12,13}


//#ifdef GAMEMODE == 1
#define MAX_CARDS 5  //A hand can has max 5 cards
//#endif // DEBUG

typedef enum  mode {
    DEFAULTMODE, TESTMODE, WINMODE, SKYNET
}MODE;

static int mode = DEFAULTMODE;

typedef enum status {
    BUST, NOTBUST, BLACKJACK
} HANDSTATUS;


typedef struct hand {
    //int cardsForPrint[MAX_CARDS];
    //int cardsValue[MAX_CARDS];
    CARD cards[MAX_CARDS];
    int numberOfCards;  // 0 - 5
    int totalCardValue; //bust or no
    HANDSTATUS hand_status;

}HAND;


void changeDrawMode(int);

int getMode();

HAND NewHand();


bool Draw(HAND* h, DECK* d, int flag, int);


//void flushHand(HAND* h);


int GetNumOfCards(HAND h);


int GetTotalHandValue(HAND h);