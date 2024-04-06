#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../ProjectII/Animation.h"
#include "../ProjectII/Betting.h"
#include "../ProjectII/Cards.h"
#include "../ProjectII/Data.h"
#include "../ProjectII/DealerHits.h"
#include "../ProjectII/Hand.h"
#include "../ProjectII/StreamIO.h"
#include "../ProjectII/WinConditions.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BettingUnitTests
{
	TEST_CLASS(BettingUnitTests)
	{
	public:

		// Tests that Blackjack can properly determine how to use Hit() when a player bust
		TEST_METHOD(Hit_Bust)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();

			
			Hit(&player, &deck, 10, 2);		//card value 10
			Hit(&player, &deck, 10, 2);		//card value 10 
			Hit(&player, &deck, 1, 2);		//card value 1
											//10 + 10 + 1 = 21
			bool result;
			char option = 'h';
			if (option == 'H' || option == 'h') {
				Hit(&player, &deck, 0, 2);	//if player hits again, should return bust bc over 21
				if (player.hand_status == BUST)
					result = true;
				else
					result = false;
			}
			Assert::IsTrue(result);
		};

		// Tests that Blackjack can properly determine how to use Hit() when a player notbust
		TEST_METHOD(Hit_NotBust)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();

			Hit(&player, &deck, 10, 2);	//card value 10

			bool result;
			char option = 'h';
			if (option == 'H' || option == 'h') {
				Hit(&player, &deck, 0, 2);	//if player hits again, shouldnt ever bust
				if (player.hand_status == BUST)
					result = true;
				else
					result = false;
			}
			Assert::IsFalse(result);
		};

		// Integration Test B-001
		// Tests that Blackjack can properly detect a player notbust
		TEST_METHOD(Stand_NotBust)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();

			Hit(&player, &deck, 10, 2);	//card value 10

			bool result;
			if (player.hand_status == NOTBUST)	//hand only has value of 10, so shouldn't bust
				result = true;
			else
				result = false;
			Assert::IsTrue(result);
		};

		// Integration Test B-001
		// Tests that Blackjack can properly detect a player bust
		TEST_METHOD(Stand_Bust)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();

			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 2, 2);	//card value 2: 10 + 10 + 2 = 22 = Bust

			bool result;
			if (player.hand_status == NOTBUST)	//hand has value of 22, should bust
				result = true;
			else
				result = false;
			Assert::IsFalse(result);
		};

		// Integration Test with WinConditions module
		// Tests whether the Betting module will return losing multiplier if player busts
		TEST_METHOD(ReturnValue_LOSS1)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();
			HAND dealer = NewHand();

			// simulated player hits
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 2, 2);	//card value 2:
											// 10 + 10 + 2 = 22 : Bust

			Stand(&deck, &dealer, player);

			int result = pickWinner(dealer, player);
			Assert::AreEqual(-1, result);
		}

		// Integration Test with WinConditions module
		// Tests whether the Betting module will return a losing multiplier if dealer has higher card values
		TEST_METHOD(ReturnValue_LOSS2)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();
			HAND dealer = NewHand();

			// simulated player hits
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 9, 2);	//card value 9
											// 10 + 9 = 19
			// simulated dealer hits
			Hit(&dealer, &deck, 10, 2);	//card value 10
			Hit(&dealer, &deck, 10, 2);	//card value 10
											// 10 + 10 = 20 -> higher card value

			int result = pickWinner(dealer, player);
			Assert::AreEqual(-1, result);
		}

		// Integration Test with WinConditions module
		// Tests whether the Betting module will return the winning multiplier if dealer busts
		TEST_METHOD(ReturnValue_WIN1)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();
			HAND dealer = NewHand();

			// simulated player hits
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 9, 2);	//card value 9
											// 10 + 9 = 19
			// simulated dealer hits
			Hit(&dealer, &deck, 10, 2);	//card value 10
			Hit(&dealer, &deck, 10, 2);	//card value 10
			Hit(&dealer, &deck, 10, 2);	//card value 10
											// 10 + 10 + 10 = 30 -> dealer bust

			int result = pickWinner(dealer, player);
			Assert::AreEqual(1, result);
		}

		// Integration Test with WinConditions module
		// Tests whether the Betting module will return the winning multiplier if player has higher card value
		TEST_METHOD(ReturnValue_WIN2)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();
			HAND dealer = NewHand();

			// simulated player hits
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 9, 2);	//card value 9
											// 10 + 9 = 19
			// simulated dealer hits
			Hit(&dealer, &deck, 10, 2);	//card value 10
			Hit(&dealer, &deck, 8, 2);	//card value 8
											// 10 + 8 = 18 -> lower card value

			int result = pickWinner(dealer, player);
			Assert::AreEqual(1, result);
		}

		// Integration Test with WinConditions module
		// Tests whether the Betting module will return the specialwin multiplier if player has blackjack
		TEST_METHOD(ReturnValue_BLACKJACK)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();
			HAND dealer = NewHand();

			// simulated player hits
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 14, 2);	//card value 11
											// 10 + 11 = 21 -> blackjack
			// simulated dealer hits
			Hit(&dealer, &deck, 10, 2);	//card value 10
			Hit(&dealer, &deck, 8, 2);	//card value 8
											// 10 + 8 = 18 -> lower card value

			int result = pickWinner(dealer, player);
			Assert::AreEqual(2, result);
		}

		// Integration Test with WinConditions module
		// Tests whether the Betting module will return the tie multiplier if player and dealer have blackjack
		TEST_METHOD(ReturnValue_TIE1)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();
			HAND dealer = NewHand();

			// simulated player hits
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 14, 2);	//card value 11
											// 10 + 11 = 21 -> blackjack
			// simulated dealer hits
			Hit(&dealer, &deck, 10, 2);	//card value 10
			Hit(&dealer, &deck, 14, 2);	//card value 11
											// 10 + 11 = 21 -> blackjack

			int result = pickWinner(dealer, player);
			Assert::AreEqual(0, result);
		}

		// Integration Test with WinConditions module
		// Tests whether the Betting module will return the tie multiplier if player and dealer have same card value
		TEST_METHOD(ReturnValue_TIE2)
		{
			DECK deck = InitDeck();
			HAND player = NewHand();
			HAND dealer = NewHand();

			// simulated player hits
			Hit(&player, &deck, 10, 2);	//card value 10
			Hit(&player, &deck, 10, 2);	//card value 10
											// 10 + 10 = 20
			// simulated dealer hits
			Hit(&dealer, &deck, 10, 2);	//card value 10
			Hit(&dealer, &deck, 10, 2);	//card value 10
											// 10 + 10 = 20

			int result = pickWinner(dealer, player);
			Assert::AreEqual(0, result);
		}
	};
}
