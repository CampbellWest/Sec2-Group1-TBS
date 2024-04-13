#include "Betting.h"

bool Hit(HAND* player, DECK* deck, int flag, int n)
{
	/* test */
	//static int i = 0;
	//Draw(player, deck, 1 + 13*i++, n);
	//if (i == 4)
	//	i = 0; //reset value

	/* default */
	Draw(player, deck, flag, n);
}

void Stand(DECK* deck, HAND* dealer, HAND player)
{
	dealerHits(deck, dealer, player);
}

//void Split(HAND* player)
//{
//
//}

bool VerifyBet(User player, int bet)
{
	if (GetUserBalance(player) < bet || bet <= 0) {
		red();
		printf("Insufficient or invalid balance.\n\n");
		reset();
		return false;
	}
	return true;
}

unsigned int GetBet(User player)
{
	int bet;
	do {
		printf("Account Balance:");
		green();
		printf(" % u", GetUserBalance(player));
		reset();
		printf(" Credits\n\n");
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

		printf("Your new balance is: ");
		green();
		printf("% u ", GetUserBalance(*player));
		reset();
		printf("Credits\n\nHit enter to play again or q to quit: ");
		choice = selectOption();
		
	} while (choice != 'q' && choice != 'Q');
	clearScreen(0, screen_h, 0, screen_w);
}

int BlackJack(void) {
	DECK deck = InitDeck();

	HAND player = NewHand();
	HAND dealer = NewHand();

	char* p = "\033[0;36mYour Hand:\033[0m\0";
	char* d = "\033[0;31mDealer Hand:\033[0m\0";

	overPrint(d, 14, 0, strlen(d));
	overPrint(p, 29, 0, strlen(p));

	Draw(&player, &deck, 0, 2);
	Draw(&dealer, &deck, 0, 1);
	Draw(&player, &deck, 0, 2);

	char option;
	while (true) {

		if (player.hand_status == BLACKJACK)
			break;

		printf("Your card value: %d\n", player.totalCardValue);
		printf("Hit or Stand? (H/S): ");
		option = selectOption();
		if (option == 'H' || option == 'h') {
			if (Hit(&player, &deck, 0, 2)) {
				if (player.hand_status == BUST) {
					yellow();
					drawBust();
					reset();
					break;
				}
				else if (player.numberOfCards == MAX_CARDS) {//full hand win 4/10
					if (getMode() == SKYNET) {
						printf("You saved our lives from the out-of-control AI and prevented the judgment day, for which you will earn a 100x bonus\n");
						return 100;
					}
					return 1;
				}else
					continue;
			}
		}
		if (option == 'S' || option == 's')
			break;
	}
	if (player.hand_status == NOTBUST || player.hand_status == BLACKJACK)
		Stand(&deck, &dealer, player);

	return pickWinner(dealer, player);
}
