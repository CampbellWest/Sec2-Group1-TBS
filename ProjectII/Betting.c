#include "Betting.h"
#include "Hand.h"
#include "StreamIO.h"

void Hit(HAND* player, DECK* deck, int flag, int n)
{
	Draw(player, deck, flag, n);
}

void Stand(HAND player, HAND* dealer)
{
	//DealerHits(player, dealer);
}

void Split(HAND* player)
{

}

bool VerifyBet(User player, int bet)
{
	if (GetUserBalance(player) < bet || bet <= 0) {
		printf("Unsufficient balance.\n\n");
		return false;
	}
	return true;
}

unsigned int GetBet(User player)
{
	int bet;
	do {
		printf("Account Balance: %u\n\n", GetUserBalance(player));
		printf("Enter bet amount: ");
		char buffer[MAXSIZE];
		ReadStream(buffer, MAXSIZE, stdin);
		bet = atoi(buffer);
		Sleep(500);
		system("cls");

	} while (!VerifyBet(player, bet));
}

void PlaceBet(User* player)
{
	unsigned int bet = GetBet(*player);
	bet *= BlackJack();
	SetUserBalance(player, bet);
}

int BlackJack(void) {
	DECK deck = InitDeck();

	HAND player = NewHand();
	HAND dealer = NewHand();

	//dealer first card
	Draw(&dealer, &deck, 0, 1);
	Draw(&player, &deck, 0, 2);

	char option;
	while (true) {

		printf("Your card value: %d\n", player.totalCardValue);
		printf("Hit or Stand? (H/S): \n");
		option = selectOption();
		if (option == 'H' || option == 'h') {
			Hit(&player, &deck, 0, 2);
			if (player.hand_status == BUST)
				break;
			else
				continue;
		}
		if (option == 'S' || option == 's')
			break;
	}
	if (player.hand_status == NOTBUST)
		Stand(player, &dealer);

	clearScreen(0, screen_h, 0, screen_w);
	return -1; //WinCondition(player, dealer);
}
//player.balance += blackjack();

//
// return -bet if
// 
// 
// 
// int blackjack(User* player)
//    returns integer whether win or lose
// very useful
// 
// Pen's draw() function very useful
// 
// have blackjack inside placebet()
// outside placebet() you decide whether to play again, inside while{} loop
//