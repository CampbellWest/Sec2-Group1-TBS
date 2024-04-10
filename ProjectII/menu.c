// main menu - 18 March - Pen
#include<stdio.h>
#include"menu.h"

void Menu(User* player, int mode) {
	printf(" ************************* \n");
	printf(" * Welcome to Blackjack, *\n");
	//printf("to");
	printf(" *	%s!	 *\n", GetUsersName(*player));
	printf(" ************************* \n\n");

	char option;
	do {
		printf("  **** MAIN ****\n\n");

		//printf("  **** MAIN ****\n\n");
		//add in do - while loop  --for return NULL
		printf("a) Quick Play\n");
		printf("b) Account Details\n");
		if (mode == TESTMODE) {
			//printf("c) Change mode\n");
		}
		printf("q) Quit\n");
		printf("Enter your Choice: ");
		switch (option = selectOption()) {
		case 'a':
			/*			if (InitWindows(0)) {
							printf("error: init windows\n");
						}else	*/
			PlaceBet(player);

			break;
		case 'b':
			clearScreen(0, screen_h, 0, screen_w);
			printf(" *******************\n * Account Details *\n *******************\n\n");
			printf("Name: %s\n", GetUsersName(*player));
			printf("Balance: %d\n\n", GetUserBalance(*player));
			
			break;
			
		case 'c':
			if (mode == TESTMODE) {
				PlaceBet(player);
			}
			break;
		}

	} while (option != 'q');
}
