// I/O stream ADT Header
// 
//Zongping Cui - Group Project II
#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100
#define MAXMENUREAD	5

typedef enum readStatus {
	LINEFINISH = 1, LINENOTEND = 2, NOTREAD = 0
} READSTATUS;

// return '\0' when format fail
char selectOption();

// read part of stream
// return int:  1 finish reading a line
//				2 buffer full but line not end
//				0 error
int ReadStream(char* buffer, int size, FILE* fp);

// read only letters
bool ReadLettersInStream(char* buffer, int size, FILE* fp);

// convert and write
bool WriteToOutput(char* buffer, FILE* fp);

// remove trailing new line in buffer
void rmNewline(char* buffer);

bool format_check_letter(char* buffer);