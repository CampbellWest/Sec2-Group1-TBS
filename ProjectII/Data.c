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

void SetFileBalance(User player, FILE* fp)
{
	fprintf(fp, "%d\n", player.balance);
}

void SetFileName(User player, FILE* fp)
{
	fprintf(fp, "%s\n", player.name);
}

void UpdateFile(User player)
{
	FILE* fp = fopen("AccountData.txt", "w");
	if (fp == NULL) {
		printf("Unable to open file.\n");
		exit(1);
	}

	SetFileName(player, fp);
	SetFileBalance(player, fp);

	fclose(fp);
}

bool VerifyName(char name[])
{
	for (int i = 0; i < MAXNAME; i++) {
		if (isdigit(strlen(name)))
			return false;
	}

	return true;
}

char* CreateAccountName(void)
{
	char name[MAXNAME];
	do {
		printf("The name for your account must not include numbers.\n");
		printf("Please enter a name for your account: ");
		//scanf_s("%s", name, MAXNAME);
		fgets(name, MAXNAME, stdin);
		//clearBuffer();
	} while (!VerifyName(name));

	return name;
}

void CreateNewFile(void) {
	FILE* fp = fopen("AccountData.txt", "w");
	if (fp == NULL) {
		printf("Unable to open file.\n");
		exit(1);
	}
	fclose(fp);
}

bool IsFileEmpty(void)
{
	CreateNewFile();
	FILE* fp = fopen("AccountData.txt", "r");
	if (fp == NULL) {
		printf("Unable to open file.\n");
		return false;
	}

	fseek(fp, 0, SEEK_END);
	long int size = ftell(fp);
	fclose(fp);

	if (size == 0)
		return true;

	return false;
}

User CreateUserFromFile()
{
	FILE* fp = fopen("AccountData.txt", "r");
	if (fp == NULL) {
		printf("Unable to open file.\n");
		exit(1);
	}

	char name[MAXNAME];
	fscanf(fp, "%s\n", &name);

	unsigned int balance;
	fscanf(fp, "%u\n", &balance);
	fclose(fp);

	User player;
	UpdateUser(&player, name, balance);

	return player;
}

User CreateNewUser(void)
{
	User player;
	if (!IsFileEmpty()) {
		player = CreateUserFromFile();
		return player;
	}

	char name[MAXNAME];
	strncpy(name, CreateAccountName(), MAXNAME);

	UpdateUser(&player, name, NEWBALANCE);
	return player;
}