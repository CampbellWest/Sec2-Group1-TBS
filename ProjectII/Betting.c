#include "Betting.h"
#include "DealerHits.h"
#include "Hand.h"
#include "StreamIO.h"
#include "WinConditions.h"

void Hit(HAND* player, DECK* deck, int flag, int n)
{
	Draw(player, deck, flag, n);
}

void Stand(DECK* deck, HAND* dealer, HAND player)
{
	dealerHits(deck, dealer, player);
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
		clearScreen(0, screen_h, 0, screen_w);

	} while (!VerifyBet(player, bet));

	return bet;
}

void PlaceBet(User* player)
{
	char choice;
	do
	{
		clearScreen(0, screen_h, 0, screen_w);
		int bet = GetBet(*player);
		bet *= BlackJack();
		int balance = GetUserBalance(*player) + bet;
		SetUserBalance(player, balance);
		UpdateFile(*player);

		printf("Your new balance is: %u\n\n", GetUserBalance(*player));
		printf("Hit enter to play again or q to quit: ");
		choice = selectOption();
		
	} while (choice != 'q' && choice != 'Q');
	clearScreen(0, screen_h, 0, screen_w);
}

int BlackJack(void) {
	DECK deck = InitDeck();

	HAND player = NewHand();
	HAND dealer = NewHand();

	//dealer first card

	Draw(&player, &deck, 0, 2);
	Draw(&dealer, &deck, 0, 1);
	Draw(&player, &deck, 0, 2);

	char option;
	while (true) {

		printf("Your card value: %d\n", player.totalCardValue);
		printf("Hit or Stand? (H/S): ");
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
		Stand(&deck, &dealer, player);

	return pickWinner(dealer, player);
}
