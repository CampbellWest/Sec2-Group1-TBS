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

	HAND player = NewHand();
	HAND dealer = NewHand();

	char option;

	int x[5] = {1,27,23,50,3};
	int i = 0;

	//dealer first card
	char* buffer = "Dealer:\0";
	overPrint(buffer, CARD_H + 2, 0, strlen(buffer));
	buffer = "Player:\0";
	overPrint(buffer, 27 + 2, 0, strlen(buffer));
	Draw(&dealer, &deck, 0, 1); // 1 for dealer (first card set) 

	//player round
	while (true) {


		//Draw(&player, &deck, 0, 2); // 2 for first player
		Draw(&player, &deck, x[i++], 2); // debug test mode

		printf("Your card value: %d\n", GetTotalHandValue(player));
		printf("Hit or Stand? (H/S): \n");
		option = selectOption();
		if (option == 'H' || option == 'h') 
			continue;
		if (option == 'S' || option == 's')
			break;
	}

	Draw(&player, &deck, 0, 3);

	//dealer round - dealer hit module


	clearScreen(0,screen_h,0,screen_w);


}