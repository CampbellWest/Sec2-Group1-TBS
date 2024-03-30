#pragma once

#include <io.h>
#include <Windows.h>
#include <stdio.h>
#include "Cards.h"
#include "Hand.h"


#define CARD_H 12
#define CARD_W 17 //16+1

#define screen_w 25
#define screen_h 60

#define IMAGESIZE 20
#define MAXPRINTNUM 15

//typedef struct screen {
//	char pixels[screen_h][screen_w];
//	int printed_w;
//	int printed_h;
//}SCREEN;
//
//SCREEN NewScreen();


//typedef struct image {
//	char pixel[MAXPRINTCARD][MAXPRINTCARD];
//}IMAGE;


void clearScreen(int y, int height, int x, int width);
int DrawACardFromDeck_A(CARD c, int, int);
void drawing_A(char image[IMAGESIZE][IMAGESIZE], int to_hand, int, int);

void Display();

//Overlay
void overPrint(char*, int y, int x, int length);

//int InitWindows(int mode);
