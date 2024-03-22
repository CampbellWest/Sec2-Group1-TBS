// main menu - 18 March - Pen
#include<stdio.h>
#include "Animation.h"
#include"menu.h"


void BlackJack();

void Menu() {
	printf(" ********************************** \n");
	printf("**       Welcome  to\n");
	printf("**		  BlackJack\n");
	printf(" ********************************** \n");

	char choice;
	char buffer[MAXSIZE];

	do {
		//PrintDeck();

		printf("  **** MAIN ****\n\n");

		//printf("  **** MAIN ****\n\n");
		//add in do - while loop  --for return NULL
		printf("a) Quick play\n");
		printf("b) Check ur profile\n");
		//printf("c) Change game mode\n");
		printf("q) Exit\n");
		printf("Enter your Choice: ");
		switch (choice = selectOption()) {
		case 'a':
/*			if (InitWindows(0)) {
				printf("error: init windows\n");
			}else	*/	
			BlackJack();
			

			break;
		case 'b':

			break;
		}

	} while (choice != 'q');

}


void BlackJack() {
	DECK deck = InitDeck();

	HAND player = newHand();
	HAND dealer = newHand();

	char option;

	int x[5] = {1,9,14,50,3};
	int i = 0;

	//dealer first card
	Draw(&dealer, &deck, 0, 1);

	//player round
	while (true) {

		//playerHitsOrStands()

		Draw(&player, &deck, 0,2); // 1 for first player
		//DrawACardFromDeck_A(player.cards[player.numberOfCards - 1], player.numberOfCards - 1);

		//printfHand(player);
		printf("Your card value: %d\n",player.totalCardValue);
		printf("Hit or Stand? (H/S): \n");
		option = selectOption();
		if (option == 'H' || option == 'h') 
			continue;
		if (option == 'S' || option == 's')
			break;
	}

	//dealer round


	clearScreen(0,screen_h,0,screen_w);


}