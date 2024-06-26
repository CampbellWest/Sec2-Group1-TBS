#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Hand.h"
#include "StreamIO.h"

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

void UpdateFile(User);

bool VerifyName(char[]);
char* CreateAccountName(void);

User CreateUserFromFile(FILE*);
User CreateNewUser(void);