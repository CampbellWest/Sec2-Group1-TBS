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
		red();
		printf("   ***************\n   **");
		reset();
		printf(" MAIN MENU ");
		red();
		printf("**\n   ***************\n");
		reset();
		//printf("   **** MAIN ****\n\n");

		printf(" a) Quick Play\n");
		printf(" b) Account Details\n");
		printf(" q) Quit\n");
		printf(" Enter your Choice: ");
		switch (option = selectOption()) {
		case 'a':
			/*			if (InitWindows(0)) {
							printf("error: init windows\n");
						}else	*/
			PlaceBet(player);

			break;
		case 'b':
			clearScreen(0, screen_h, 0, screen_w);
			yellow();
			printf(" *******************\n *");
			white();
			printf(" Account Details ");
			yellow();
			printf("*\n *******************\n\n");
			cyan();
			printf(" %s\n", GetUsersName(*player));
			green();
			printf(" %d ", GetUserBalance(*player));
			reset();
			printf("Credits\n\n");
			
			break;
		}

	} while (option != 'q');
}
