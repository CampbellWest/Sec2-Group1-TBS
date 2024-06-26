#include "Hand.h"

HAND NewHand() {
	HAND h;
	h.numberOfCards = 0;
	h.totalCardValue = 0;
	h.hand_status = NOTBUST;
	return h;
}

//void flushHand(HAND* h) {
//	h->numberOfCards = 0;
//	h->totalCardValue = 0;
//	h->hand_status = NOTBURST;
//}

//change a static global value
void changeDrawMode(int m) {
	mode = m;
}

int getMode() {
	return mode;
}

//draw card from deck
bool DrawWithMode(HAND* h, DECK* d, int flag, int n) {
	if (GetNumOfCards(*h) == MAX_CARDS) {
		printf("Full hand, cannot draw anymore\n");
		return false;
	}

	if (flag < 0 || flag > 52) {
		printf("Card num not exist\n");
		return false;
	}

	if (flag && !d->cards[flag-1].inDeck) { //draw a card not in deck
		printf("Card not in deck\n");
		return false;
	}

	//method of deck
	CARD* card = DrawFromDeck(d, flag);

	h->cards[GetNumOfCards(*h)] = *card;
	h->numberOfCards += 1;

	// value of A
	if (1 < card->value && card->value < 10)  // 2 - 9
		h->totalCardValue += card->value;
	else if (card->value == 1) { //A
		if (h->totalCardValue < 11) { //soft
			h->totalCardValue += 11;   // A = 11
		}
		else { //hard
			h->totalCardValue += 1;    // A = 1
		}
	}
	else if (card->value >= 10) { //10 - 13  J,Q,K
		h->totalCardValue += 10;
	}

	if (h->totalCardValue == 21 && h->numberOfCards == 2) { //blackJack
		h->hand_status = BLACKJACK;
	}
	else if (h->totalCardValue > 21) {
		int sum = 0;
		for (int i = 0; i < h->numberOfCards; i++) {
			if (h->cards[i].value == 1)
				// previous soft Ace go hard
				sum += 1;
			else if (h->cards[i].value >= 10) { //10 - 13  J,Q,K
				sum += 10;
			}
			else
				sum += h->cards[i].value;
		}
		h->totalCardValue = sum;
		if (sum > 21) {  // bust in hard mode
			h->hand_status = BUST;
		}
	}

	//Card shift animation
	DrawACardFromDeck_A(*card, h->numberOfCards - 1, n);

	return true;
}

bool Draw(HAND* h, DECK* d, int flag, int n) {
	if (mode == TESTMODE) {  //dealer always have large card
		//printf("testing\n");
		if (n == 1) { //dealer
			int arr[] = CARDSHARK;
			flag = arr[rand() % 5] + 13*(rand()%4);
		}
	}
	else if(mode == WINMODE){  //player always have large card
		if (n > 1) { //player
			int arr[] = CARDSHARK;
			flag = arr[rand() % 5] + 13 * (rand() % 4);
		}
	}
	return DrawWithMode(h, d, flag, n);
}

int GetNumOfCards(HAND h) {
	return h.numberOfCards;
}

int GetTotalHandValue(HAND h) {
	return h.totalCardValue;
}