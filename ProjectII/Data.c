#include "Data.h"

unsigned int GetUserBalance(User player)
{
	return player.balance;
}

void SetUserBalance(User* player, unsigned int balance)
{
	player->balance = balance;
}

char* GetUsersName(User player)
{
	return player.name;
}

void SetUserName(User* player, char name[])
{
	strncpy(player->name, name, MAXNAME);
}

void UpdateUser(User* player, char name[], unsigned int balance)
{
	SetUserName(player, name);
	SetUserBalance(player, balance);
}

void UpdateFile(User player)
{
	FILE* fp = fopen("AccountData.txt", "w");
	if (fp == NULL) {
		printf("Unable to open file.\n");
		exit(1);
	}

	fprintf(fp, "%s\n", player.name);
	fprintf(fp, "%d\n", player.balance);

	fclose(fp);
}

// redundant
bool VerifyName(char name[])
{
	//for (int i = 0; i < MAXNAME; i++) {
	//	if (isdigit(strlen(name)))
	//		return false;
	//}

	return true;
}
//

char* CreateAccountName(void)
{
	char name[MAXNAME];
	do {
		printf("Please enter a name for your account: ");
		ReadStream(name, MAXNAME, stdin);
	} while (!VerifyName(name));
	clearScreen(0, screen_h, 0, screen_w);
	return name;
}

User CreateUserFromFile(FILE* fp)
{
	char name[MAXNAME];
	ReadStream(name, MAXNAME, fp);

	unsigned int balance;
	fscanf(fp, "%u\n", &balance);

	User player;
	UpdateUser(&player, name, balance);

	return player;
}

User CreateNewUser(void)
{
	User player;
	FILE* fp = fopen("AccountData.txt", "r");
	if (fp != NULL) {			// if the file is not empty
		player = CreateUserFromFile(fp);
		fclose(fp);
		return player;
	}

	char name[MAXNAME];
	strncpy(name, CreateAccountName(), MAXNAME);

	UpdateUser(&player, name, NEWBALANCE);
	UpdateFile(player);
	return player;
}