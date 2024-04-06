#define _CRT_SECURE_NO_WARNINGS

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

namespace DataUnitTests
{
	TEST_CLASS(DataUnitTests)
	{
	public:

		// Integration Test DS-001
		// Tests the Set and Get user balance functions to ensure they can properly acces the user's balance
		TEST_METHOD(Set_and_Get_UserBalance)
		{
			User p;
			unsigned int balance = 50;
			SetUserBalance(&p, balance);
			Assert::AreEqual(balance, GetUserBalance(p));
		};

		// Tests the Set and Get user name functions to ensure they can properly acces the user's name
		TEST_METHOD(Set_and_Get_UserName)
		{
			User p;
			char name[MAXNAME] = "Placeholder";
			SetUserName(&p, name);
			Assert::AreEqual(name, GetUsersName(p));
		};

		// Tests the UpdateUser() function to ensure it can properly acces change the user's information
		TEST_METHOD(UpdateUser_test)
		{
			User p;
			char name[MAXNAME] = "Placeholder";
			unsigned int balance = 50;
			UpdateUser(&p, name, balance);
			Assert::AreEqual(name, GetUsersName(p));
			Assert::AreEqual(balance, GetUserBalance(p));
		};

		// Tests the UpdateFile() function's ability to properly update the contents of a file
		TEST_METHOD(UpdateFile_test)
		{
			User p;
			char name[MAXNAME] = "Placeholder";
			unsigned int balance = 50;
			UpdateUser(&p, name, balance);
			UpdateFile(p);

			FILE* fp = fopen("AccountData.txt", "r");
			char buff[MAXNAME];
			fscanf(fp, "%s\n", &buff);

			unsigned int temp;
			fscanf(fp, "%u\n", &temp);

			Assert::AreEqual(name, buff);
			Assert::AreEqual(balance, temp);
		};

		// Tests the UpdateFile() function's ability to properly update the contents of a file
		TEST_METHOD(CreateUserFromFile_test)
		{
			User p;
			char name[MAXNAME] = "Placeholder";
			unsigned int balance = 50;
			UpdateUser(&p, name, balance);
			UpdateFile(p);

			FILE* fp = fopen("AccountData.txt", "r");
			User q = CreateUserFromFile(fp);

			Assert::AreEqual(name, GetUsersName(q));
			Assert::AreEqual(balance, GetUserBalance(q));
		};

		// Integration Test DS-002
		// Tests that VerifyBet returns true when given a number <= user balance
		TEST_METHOD(VerifyBet_True)
		{
			User p;
			SetUserBalance(&p, 500);
			Assert::IsTrue(VerifyBet(p, 500));
		};

		// Integration Test DS-002
		// Tests that VerifyBet returns false when given a number > user balance
		TEST_METHOD(VerifyBet_False)
		{
			User p;
			SetUserBalance(&p, 500);
			Assert::IsFalse(VerifyBet(p, 501));
		};

		// Integration Test DS-002
		// Tests that VerifyBet returns false when given a negative number
		TEST_METHOD(VerifyBet_Negative)
		{
			User p;
			SetUserBalance(&p, 500);
			Assert::IsFalse(VerifyBet(p, -1));
		};
	};
}
