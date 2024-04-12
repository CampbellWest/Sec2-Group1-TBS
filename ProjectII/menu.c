// main menu - 18 March - Pen
#include<stdio.h>
#include"menu.h"

void Menu(User* player, int mode) {
	yellow();
	printf(" ********************************* \n");
	white();
	printf("       Welcome to Blackjack,      \n");
	cyan();
	printf(" 	    %s!	   \n", GetUsersName(*player));
	yellow();
	printf(" ********************************* \n\n");
	reset();

	char option;
	do {
		printf("  **** MAIN ****\n\n");

		printf("a) Quick Play\n");
		printf("b) Account Details\n");
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
		}

	} while (option != 'q');
}
