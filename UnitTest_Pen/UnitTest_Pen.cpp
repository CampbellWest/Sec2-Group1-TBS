#include "pch.h"
#include "CppUnitTest.h"

typedef enum suit {
	SPADES, HEARTS, DIAMONDS, CLUBS
}SUIT;

#define DECKNUM 52

typedef struct card {
	int value;
	SUIT suit;
	bool inDeck;
}CARD;

typedef struct deck {
	CARD cards[DECKNUM];
}DECK;


extern "C" CARD newCard(int value, SUIT suit);
extern "C" DECK InitDeck();

extern "C" CARD * DrawFromDeck(DECK * d, int flag);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPen_CardAndDeck
{
	TEST_CLASS(CardAndDeck)
	{
	public:
		
		// UT 101
		// REQ-101 A card structure shall represent one of 13 values and one of 4 suits
		// new card by parameter constructer
		TEST_METHOD(newCard_test)
		{
			CARD SPADES_Ace = newCard(1, SPADES);
			Assert::AreEqual(0, (int)SPADES_Ace.suit);
			Assert::AreEqual(1, SPADES_Ace.value);

			// test all card
			for (int i = 1; i < DECKNUM+1; i ++) {
				int suits = (i - 1) / 13;

				CARD tmp = newCard(i - suits * 13, (SUIT)((i-1)/13));
				Assert::AreEqual(suits, (int)tmp.suit);
				Assert::AreEqual(i - suits*13, tmp.value);
			}

		}

		// UT 1021
		// REQ-102 The deck structure shall contain all 52 cards organized within an array.
		TEST_METHOD(InitDeck_test)
		{
			DECK deck = InitDeck();

			// test all card in deck
			for (int i = 1; i < DECKNUM+1; i++) {
				int suits = (i-1) / 13;
				Assert::AreEqual(suits, (int)deck.cards[i - 1].suit);
				Assert::AreEqual(i - suits * 13, deck.cards[i-1].value);

			}

		}

		// UT 1022
		//test draw, to draw each card from one deck
		TEST_METHOD(DrawFromDeck_test)
		{
			DECK deck = InitDeck();

			// test all card in deck
			for (int i = 1; i < DECKNUM + 1; i++) {
				int suits = (i - 1) / 13;
				CARD* tmp = DrawFromDeck(&deck, i);
				Assert::AreEqual(suits, (int)tmp->suit);
				Assert::AreEqual(i - suits * 13, tmp->value);
			}

		}
	};
}




#define MAX_CARDS 5 

typedef enum status {
	BUST, NOTBUST, BLACKJACK
} HANDSTATUS;

typedef struct hand {
	CARD cards[MAX_CARDS];
	int numberOfCards;  // 0 - 5
	int totalCardValue; //bust or no
	HANDSTATUS hand_status;

}HAND;


extern "C" HAND NewHand();
extern "C" int GetNumOfCards(HAND h);
extern "C" int GetTotalHandValue(HAND h);
extern "C" bool Draw(HAND* h, DECK* d, int flag, int);

namespace UnitTestPen_Hand
{
	TEST_CLASS(Hand)
	{
	public:

		// CD-02
		// REQ-101 The hand structure shall hold a collection of cards, with a maximum capacity of 5
		// new had test, a empty hand with 0 card and 0 value
		TEST_METHOD(NewHand_test)
		{
			
			HAND h = NewHand();
			Assert::AreEqual(0, GetNumOfCards(h));
			Assert::AreEqual(0, GetTotalHandValue(h));

		}


		// CD-03 a 
		// REQ-105 The module shall offer methods to draw cards from deck to hand. 
		// test draw
		TEST_METHOD(Draw_test)
		{
			HAND h = NewHand();
			DECK deck = InitDeck();
			Draw(&h, &deck, 2, 0);
			Assert::AreEqual(1, GetNumOfCards(h)); //one card
			Assert::AreEqual(2, GetTotalHandValue(h)); //which is 2
			Assert::AreEqual(0, (int)h.cards[0].suit); // spades 2
		}

		// CD-03 b
		// REQ-105 When a card is drawn from the deck to a hand, 
		// it should not be possible to draw the same card from that deck again, to prevent duplication. 
		// test duplicated draw
		TEST_METHOD(Draw_test_duplication)
		{
			HAND h = NewHand();
			DECK deck = InitDeck();
			Draw(&h, &deck, 2, 0); // first draw
			bool draw_same = Draw(&h, &deck, 2, 0); // second
			Assert::IsFalse(draw_same);
		}

		// UT 1051
		// test boundary, draw -1 card and 53 card
		TEST_METHOD(Draw_test_boundary)
		{
			HAND h = NewHand();
			DECK deck = InitDeck();
			Assert::IsFalse(Draw(&h, &deck, -1, 0));
			Assert::IsFalse(Draw(&h, &deck, 53, 0));
		}


		// UT 1052
		// REQ-104 The hand structure shall hold a collection of cards, with a maximum capacity of 5
		// test boundary, draw more than 5 card to 1 hand
		// by input 0, the draw will work in random mode
		TEST_METHOD(Draw_test_exceed_hand_limit)
		{
			HAND h = NewHand();
			DECK deck = InitDeck();
			for (int i = 0; i < 5;i++) {
				Assert::IsTrue(Draw(&h, &deck, 0, 0));
			}
			Assert::IsFalse(Draw(&h, &deck, 0, 0));
		}


		// UT 1053
		// draw all card
		// by input 0, the draw will work in random mode
		// draw 52 time will made the deck empty
		TEST_METHOD(Draw_test_all)
		{
			
			DECK deck = InitDeck();
			for (int i = 0; i < DECKNUM; i ++) {
				HAND tmpH = NewHand();
				Assert::IsTrue(Draw(&tmpH, &deck, 0, 0));
			}
			for (int i = 0; i < DECKNUM; i++) {
				Assert::IsFalse(deck.cards[i].inDeck);
			}
		}
	};

	TEST_CLASS(Hand_score)
	{
	public:

		// CD-05 a
		// REQ-106 An Ace (A) should represent a value of 11, provided that the total value of the hand remains 21 or less.
		// draw A twice, first time the total value is 11, second time it change to 12
		TEST_METHOD(Ace_test)
		{
			DECK deck = InitDeck();
			HAND h = NewHand();
			Draw(&h, &deck, 1, 0); //spades Ace
			Assert::AreEqual(11, GetTotalHandValue(h));

			Draw(&h, &deck, 14, 0); //hearts Ace
			Assert::AreEqual(12, GetTotalHandValue(h));

		}

		// CD-05 b
		// when hand is about to bust, if there exists one A in hand is 11, it change to 1
		TEST_METHOD(Ace_test_Ace_switch)
		{
			DECK deck = InitDeck();
			HAND h = NewHand();
			Draw(&h, &deck, 1, 0); //spades Ace
			Assert::AreEqual(11, GetTotalHandValue(h));
			Draw(&h, &deck, 6, 0); //spades 6
			Draw(&h, &deck, 7, 0); //spades 7   11 + 6 + 7 = 24  bust
			Assert::AreEqual(14, GetTotalHandValue(h));// 23 - 10 = 14
		}

		// CD-05 c
		// 2A and a 10, both Ace value 1 
		TEST_METHOD(Ace_test_Ace_switch2)
		{
			DECK deck = InitDeck();
			HAND h = NewHand();
			Draw(&h, &deck, 1, 0); //spades Ace
			Assert::AreEqual(11, GetTotalHandValue(h));
			Draw(&h, &deck, 14, 0); //heaers Ace
			Draw(&h, &deck, 10, 0); //spades 10   11 + 1 + 10 = 22  bust
			Assert::AreEqual(12, GetTotalHandValue(h));// 22 - 10 = 12
		}
	};

	TEST_CLASS(Hand_status) {
	public:

		// CD-07 a
		// Test initialized hand
		TEST_METHOD(NewHand_notBust)
		{
			
			HAND h = NewHand();
			Assert::AreEqual(1, (int)h.hand_status); // 0 card, NOTBUST
			
		}

		// CD-07 b
		TEST_METHOD(NewHand_Bust)
		{
			DECK deck = InitDeck();
			HAND h = NewHand();
			Draw(&h, &deck, 11, 0); //spades J
			Draw(&h, &deck, 12, 0); //spades Q
			Draw(&h, &deck, 2, 0); //spades 2
			Assert::AreEqual(0, (int)h.hand_status); // 22 > 21, bust

		}

		// CD-07 c
		TEST_METHOD(NewHand_BlackJack)
		{
			DECK deck = InitDeck();
			HAND h = NewHand();
			Draw(&h, &deck, 13, 0); //spades K
			Draw(&h, &deck, 14, 0); //Hearts A
			Assert::AreEqual(2, (int)h.hand_status); // 21, BlackJack

		}
	};
}