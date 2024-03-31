//#include "Functionality.h"
//
//int getBetAmount(int accountBalance) {
//    printf("Account Balance: %i\n\n", accountBalance);
//
//    int betAmount;
//    printf("Enter bet amount: ");
//    scanf_s("%i", &betAmount);
//    clearBuffer();
//    Sleep(500);
//    system("cls");
//    return betAmount;
//}
//
//void dealerHitsOrStands(CARDS* dealer, CARDS* player) {
//
//    do {
//        if (dealer->totalCardValue >= 17) {
//            Sleep(10);
//            return;
//        }
//
//        Sleep(1500);
//        dealer->numberOfCards++;
//        printDealerHits(dealer, player);
//        updateCardTotal(dealer);
//
//    } while (dealer->totalCardValue < 17);
//}
//
//int playerHitsOrStands(CARDS* dealer, CARDS* player) {
//    char option;
//    do {
//
//        if ((player->numberOfCards == 5 && player->totalCardValue <= 21) || player->totalCardValue == 21)
//            return 0;
//
//        if (player->totalCardValue > 21) {
//            system("cls");
//            printDealerCards(dealer);
//            printPlayerHits(player);
//            return 1;
//        }
//
//        printf("Hit or Stand? (H/S): ");
//        option = getc(stdin);
//        clearBuffer();
//
//        if (option == 'H' || option == 'h') {
//            system("cls");
//            printDealerCards(dealer);
//            player->numberOfCards++;
//            updateCardTotal(player);
//            printPlayerHits(player);
//            Sleep(1500);
//        }
//        else {
//            return 0;
//        }
//
//    } while (1);
//
//    return 0;
//}
//
//void updateCardTotal(CARDS* card) {
//    card->totalCardValue = 0;
//    for (int i = 0; i < card->numberOfCards; i++)
//        card->totalCardValue = card->totalCardValue + card->cardsValue[i];
//}
//
//void pickWinner(CARDS* dealer, CARDS* player, int* accountBalance, int* betAmount) {
//
//    if (player->totalCardValue > 21) {
//        printf("Loser: Player Bust\n");
//        *accountBalance = *accountBalance - *betAmount;
//        printf("\n\nAccount Balance: %i\n\n\n", *accountBalance);
//        return;
//    }
//
//    if (dealer->totalCardValue > 21 && player->totalCardValue <= 21) {
//        *accountBalance = *accountBalance + *betAmount;
//        printf("Winner: Dealer Bust\n");
//        printf("\n\nAccount Balance: %i\n\n\n", *accountBalance);
//        return;
//    }
//
//    if (player->numberOfCards == 5) {
//        *accountBalance = *accountBalance + (*betAmount * 2);
//        printf("Winner: 5 Card Charlie\n");
//        printf("\n\nAccount Balance: %i\n\n\n", *accountBalance);
//        return;
//    }
//
//    if (dealer->totalCardValue == player->totalCardValue)
//        printf("Push\n");
//    else if (dealer->totalCardValue > player->totalCardValue) {
//        *accountBalance = *accountBalance - *betAmount;
//        printf("Loser\n");
//    }
//    else {
//        *accountBalance = *accountBalance + *betAmount;
//        printf("Winner\n");
//    }
//
//    printf("\n\nAccount Balance: %i\n\n\n", *accountBalance);
//
//}
//
//bool Continue() {
//
//    printf("Would you like to play again? (Y/N): ");
//    char option = getc(stdin);
//    clearBuffer();
//
//    if (option == 'Y' || option == 'y') {
//        system("cls");
//        return true;
//    }
//    else
//        return false;
//}
//
//int readAccountBalance() {
//    FILE* fp = fopen("AccountBalance.txt", "r");
//    if (fp == NULL) {
//        printf("Unable to read Account Balance\n");
//        exit(1);
//    }
//
//    int accountBalance;
//    fscanf_s(fp, "%i", &accountBalance);
//
//    fclose(fp);
//
//    return accountBalance;
//}
//
//void writeAccountBalance(int accountBalance) {
//    FILE* fp = fopen("AccountBalance.txt", "w");
//    if (fp == NULL) {
//        printf("Unable to write Account Balance\n");
//        exit(1);
//    }
//
//    fprintf(fp, "%i", accountBalance);
//
//    fclose(fp);
//}
//
//void clearBuffer() {
//    int c = 0;
//    while ((c = getchar() != '\n' && c != EOF))
//        continue;
//}