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
	SetUserBalance(player, balance);
	SetUserName(player, name);
}

unsigned int GetFileBalance(void)
{
	FILE* fp = fopen("AccountData.txt", "r");
	if (fp == NULL) {
		printf("Unable to read Account Balance\n");
		exit(1);
	}

	unsigned int balance;
	fscanf_s(fp, "%u", &balance);
	fclose(fp);

	return balance;
}

void SetFileBalance(User player) 
{
	FILE* fp = fopen("AccountData.txt", "w");
	if (fp == NULL) {
		printf("Unable to open file.\n");
		exit(1);
	}

	fprintf(fp, "%u\n", player.balance);
	fclose(fp);
}

char* GetFileName(void) 
{
	FILE* fp = fopen("AccountData.txt", "r");
	if (fp == NULL) {
		printf("Unable to read Account Balance\n");
		exit(1);
	}

	char buff[MAXNAME];
	fscanf(fp, "%s", &buff);
	fclose(fp);

	return buff;
}

void SetFileName(User player)
{
	FILE* fp = fopen("AccountData.txt", "w");
	if (fp == NULL) {
		printf("Unable to open file.\n");
		exit(1);
	}
	char buff[MAXNAME];
	strncpy(buff, player.name, MAXNAME);

	fprintf(fp, "%s\n", player.name);
	fclose(fp);
}

void UpdateFile(User player)
{
	SetFileName(player);
	SetFileBalance(player);
}

bool VerifyName(char name[])
{
	for (int i = 0; i < strlen(name); i++) {
		if (isdigit(name[i]))
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
		fgets(name,MAXNAME,stdin);
		//clearBuffer();
	} while (!VerifyName(name));
	
	return name;
}

bool IsFileEmpty(void)
{
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