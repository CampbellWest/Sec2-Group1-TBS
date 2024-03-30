#include "Betting.h"

int main() { 

    srand(time(NULL));

    //int accountBalance = readAccountBalance();
    
    /* Mine */
    User player = CreateNewUser();
    int accountBalance = GetUserBalance(player);
    /* Mine */

    CARDS* d = (CARDS*)malloc(sizeof(CARDS));
    if (d == NULL) {
        printf("Unable to allocated memory for dealer\n");
        return 1;
    }

    CARDS* p = (CARDS*)malloc(sizeof(CARDS));
    if (p == NULL) {
        printf("Unable to allocated memory for player\n");
        return 1;
    }
        
    do {

        int betAmount = getBetAmount(accountBalance);
        //can check for over bet limit, dont have enough in account, under minimum

        /* Mine */
        PlaceBet(player);
        /* Mine */

        d->numberOfCards = p->numberOfCards = 2;

        for (int i = 0; i < MAX_CARDS; i++) {
            d->cardsForPrint[i] = rand() % (13) + 1;
            if (d->cardsForPrint[i] > 10)
                d->cardsValue[i] = 10;
            else
                d->cardsValue[i] = d->cardsForPrint[i];

            p->cardsForPrint[i] = rand() % (13) + 1;
            if (p->cardsForPrint[i] > 10)
                p->cardsValue[i] = 10;
            else
                p->cardsValue[i] = p->cardsForPrint[i];
        }
        
        updateCardTotal(d);
        updateCardTotal(p);

        Sleep(1000);
        printDealerCards(d);
       
        Sleep(1000);
        printTwoCards(p);
   

        if (!playerHitsOrStands(d, p)) {
            system("cls");
            printDealerCards(d);
            printPlayerHits(p);
            Sleep(1000);
            system("cls");

            printTwoCards(d);
            printPlayerHits(p);
            dealerHitsOrStands(d, p);
        }
        else {
            system("cls");
            printDealerCards(d);
            printPlayerHits(p);
            Sleep(1000);
            system("cls");

            printTwoCards(d);
            printPlayerHits(p);
            Sleep(1000);
        }

        pickWinner(d, p, &accountBalance, &betAmount);

        writeAccountBalance(accountBalance);

    } while (Continue());

    writeAccountBalance(accountBalance);
    UpdateFile(player);
    free(p);
    free(d);

    return 0;
 }

//checking ace 
//if there is one make 2 variables for 2 totals and if one total is over 21 use the other variable
//if theyre both under 21 use higher if there is not hit 
// and if there is a hit add hit to each of them and keep checking if one of them is over 21 
// 
// In the event you draw 5 cards to a hand without exceeding 21, 
// you automatically win and the Dealer will pay you even money
