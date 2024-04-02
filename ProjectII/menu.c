// main menu - 18 March - Pen
#include<stdio.h>
#include "Animation.h"
#include"menu.h"

void Menu(User* player) {
	printf(" ********************************** \n");
	printf("**       Welcome  to\n");
	printf("**		  BlackJack\n");
	printf(" ********************************** \n");

	char choice;
	do {
		//PrintDeck();


		printf("  **** MAIN ****\n\n");

		//printf("  **** MAIN ****\n\n");
		//add in do - while loop  --for return NULL
		printf("a) Quick play\n");
		printf("b) Check ur profile\n");
		//printf("c) Change game mode\n");
		printf("q) Quit\n");
		printf("Enter your Choice: ");
		switch (choice = selectOption()) {
		case 'a':
			/*			if (InitWindows(0)) {
							printf("error: init windows\n");
						}else	*/
			PlaceBet(player);

			break;
		case 'b':

			break;
		}

	} while (choice != 'q');
}
