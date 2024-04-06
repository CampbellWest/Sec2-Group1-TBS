#include "pch.h"
#include "CppUnitTest.h"

#define DECKNUM 52

typedef enum suit {
	SPADES, HEARTS, DIAMONDS, CLUBS
}SUIT;

typedef struct card {
	int value;
	SUIT suit;
	bool inDeck;
}CARD;

typedef struct deck {
	CARD cards[DECKNUM];
}DECK;

typedef enum status {
	BUST, NOTBUST, BLACKJACK
} HANDSTATUS;

#define MAX_CARDS 5 

typedef struct hand {
	CARD cards[MAX_CARDS];
	int numberOfCards;  // 0 - 5
	int totalCardValue; //bust or no
	HANDSTATUS hand_status;
}HAND;

typedef enum multiplier {
	LOSS = -1, TIE = 0, WIN = 1, SPECIAL_WIN = 2
}MULTIPLIER;

extern "C" bool dealerHits(DECK * deck, HAND * dealer, HAND player);

extern "C" MULTIPLIER pickWinner(HAND dealer, HAND player);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CampbellWestTests
{
	TEST_CLASS(CampbellWestTests)
	{
	public:
		
		TEST_METHOD(DealerHits1)
		{
			//DECK* deck;
			//HAND* dealer;
			//HAND player;

			//Assert::IsTrue(dealerHits(deck, dealer, player));
		}
		TEST_METHOD(WinConditions_LOSS) // LOSS = -1, TIE = 0, WIN = 1, SPECIAL_WIN = 2
		{
			HAND dealer, player;
			dealer.hand_status = (HANDSTATUS)1;
			dealer.totalCardValue = 20;
			dealer.numberOfCards = 2;

			player.hand_status = (HANDSTATUS)0;
			player.totalCardValue = 22;
			player.numberOfCards = 3;



			int result = pickWinner(dealer, player);

			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(WinConditions_TIE)
		{
			HAND dealer, player;
			dealer.hand_status = NOTBUST;
			dealer.totalCardValue = 19;
			dealer.numberOfCards = 3;

			player.hand_status = NOTBUST;
			player.totalCardValue = 19;
			player.numberOfCards = 3;

			int result = pickWinner(dealer, player);

			Assert::AreEqual(0, result);
		}

		TEST_METHOD(WinConditions_WIN)
		{
			HAND dealer, player;
			dealer.hand_status = BUST;
			dealer.totalCardValue = 24;
			dealer.numberOfCards = 4;

			player.hand_status = NOTBUST;
			player.totalCardValue = 18;
			player.numberOfCards = 2;

			int result = pickWinner(dealer, player);

			Assert::AreEqual(1, result);
		}

		TEST_METHOD(WinConditions_SPECIAL_WIN)
		{
			HAND dealer, player;
			dealer.hand_status = NOTBUST;
			dealer.totalCardValue = 20;
			dealer.numberOfCards = 2;

			player.hand_status = BLACKJACK;
			player.totalCardValue = 21;
			player.numberOfCards = 2;

			int result = pickWinner(dealer, player);

			Assert::AreEqual(2, result);
		}
	};
}
