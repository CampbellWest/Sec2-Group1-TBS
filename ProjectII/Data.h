#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Functionality.h"

#define MAXNAME 25
#define NEWBALANCE 500

typedef struct user {
	char name[MAXNAME];
	unsigned int balance;
}User;

unsigned int GetUserBalance(User);
void SetUserBalance(User*, unsigned int);
char* GetUsersName(User);
void SetUserName(User*, char[]);
void UpdateUser(User*, char[], unsigned int);

unsigned int GetFileBalance(void);
void SetFileBalance(User);
char* GetFileName(void);
void SetFileName(User);
void UpdateFile(User);

bool VerifyName(char[]);
char* CreateAccountName(void);
bool IsFileEmpty(void);

User CreateUserFromFile();
User CreateNewUser(void);