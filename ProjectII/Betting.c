#include "Betting.h"
#include "DealerHits.h"
#include "Hand.h"
#include "StreamIO.h"
#include "WinConditions.h"

void Hit(HAND* player, DECK* deck, int flag, int n)
{

}

void Stand(DECK* deck, HAND* dealer, HAND player)
{
	dealerHits(deck, dealer, player);
}

void Split(CARDS* player)
{

}

bool VerifyBet(User player, unsigned int bet)
{
	if (GetUserBalance(player) < bet) {
		printf("Unsufficient balance.\n\n");
		return false;
	}
	return true;
}

unsigned int GetBet(User player)
{
	unsigned int bet;
	do {
		printf("Account Balance: %u\n\n", GetUserBalance(player));
		printf("Enter bet amount: ");
		scanf_s("%u", &bet);
		clearBuffer();
		Sleep(500);
		system("cls");

	} while (!VerifyBet(player, bet));
}

void PlaceBet(User player)
{
	unsigned int bet = GetBet(player);
	bet = BlackJack(player, bet);
	SetUserBalance(player, bet);
}

int BlackJack(User p, unsigned int bet) {
	DECK deck = InitDeck();

	HAND player = newHand();
	HAND dealer = newHand();

	//dealer first card
	Draw(&dealer, &deck, 0, 1);
	Draw(&player, &deck, 0, 2); // 1 for first player

	//player round
	char option;
	while (true) {

		//printfHand(player);
		printf("Your card value: %d\n", player.totalCardValue);
		printf("Hit or Stand? (H/S): ");
		option = selectOption();
		if (option == 'H' || option == 'h') {
			Hit(player, dealer);
			if (player.hand_status == BUST) 
				break;
			else
				continue;
		}
		if (option == 'S' || option == 's') 
			break;
	}
	//dealer round
	if (player.hand_status == NOTBUST)
		Stand(&deck, &dealer, player);

	clearScreen(0, screen_h, 0, screen_w);
	return pickWinner(dealer, player);
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