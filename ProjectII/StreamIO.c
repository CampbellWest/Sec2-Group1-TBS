// I/O stream ADT implementation
// 
//Zongping Cui - Group Project II

#include "StreamIO.h"
#include <string.h>
#include <ctype.h>


char selectOption() {
	char letterChoice[MAXMENUREAD];
	// 11 30
	if (ReadStream(letterChoice, MAXMENUREAD, stdin) == NOTREAD) {
		letterChoice[0] = '\0';
	}
	return letterChoice[0];
}



// read part of stream and store value to buffer
// return int:  1 LINEFINISH finish reading a line,
//				2 LINENOTEND buffer full but line not end,
//				0 NOTREAD not read
int ReadStream(char* buffer, int arr_size, FILE* fp) {



	int read_status = NOTREAD; // not read yet, set read_status to 0

	// check if null pointer
	if (fp == NULL || buffer == NULL) {
		fprintf(stderr, "Error: stream or buffer is null\n");
	}
	// try read
	else if (fgets(buffer, arr_size, fp) == NULL) {
		fprintf(stderr, "Warn: fgets return null\n");  // TODO: EOF check?
	}
	else {
		// so far so good
		rmNewline(buffer);
		if ((int)strlen(buffer) == arr_size - 1  //buffer full
			&& buffer[arr_size - 2 != '\n']) {   // line not end£¬ ret -1
			read_status = LINENOTEND;
		}
		else {
			read_status = LINEFINISH; // reach end of line, ret 1
		}
	}

	return read_status;
}

// check if the buffer is all letters
bool format_check_letter(char* buffer) {
	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] != '\n') {
			if (!isalpha(buffer[i])) {
				return false;
			}
		}
	}
	return true;
}

// read stream and check format, if not all letters return false
bool ReadLettersInStream(char* buffer, int size, FILE* fp) {
	bool pass_format_check = false;

	if (ReadStream(buffer, size, fp) == NOTREAD) {
		printf("WARN: invalid input\n");
	}
	else {
		//check format
		if (format_check_letter(buffer)) {
			pass_format_check = true;
		}
		else {
			printf("WARN: input should only contain letters\n");
		}
	}
	return pass_format_check;

}

// write to stream
bool WriteToOutput(char* buffer, FILE* fp) {

	bool is_write = false;
	if (fp == NULL || buffer == NULL) {
		fprintf(stderr, "Error: stream or buffer is null\n");
	}
	else {
		printf(buffer);
		// write buffer
		fprintf(fp, buffer);
		is_write = true;
	}

	return is_write;

}

// remove trailing newline
void rmNewline(char* buffer) {
	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == '\n')
			buffer[i] = '\0';
	}
}
