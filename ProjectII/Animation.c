#define _CRT_SECURE_NO_WARNINGS
#include "Animation.h"

char screen[screen_h][screen_w] = { 0 };
char screenB[screen_h][screen_w*2] = { 0 };

//SCREEN NewScreen() {
//    SCREEN s = { 0 };
//    return s;
//}

void clearScreen(int y, int height, int x, int width) {
    // For Windows use system("cls");
    //system("clear"); // For Unix/Linux use system("clear");

    for (int i = y; i < height; i++) {
        for (int j = x; j < width; j++) {
            screen[i][j] = ' ';
        }
    }

    system("cls");
}

void Display() {
    for (int i = 0; i < screen_h; i++) {

        for (int j = 0; j < screen_w; j++)
            printf("%c", screen[i][j]);

        printf("\n");
    }
}

// 4/10
void DisplayYX(int y, int x) {
    for (int i = 0; i < y; i++) {

        for (int j = 0; j < x; j++)
            printf("%c", screenB[i][j]);

        printf("\n");
    }
}




// 12 x 17
char blank_card[CARD_H][CARD_W] =
{
    " ______________ \0",
    "|  __________  |\0",
    "| |          | |\0",
    "| |          | |\0",
    "| |          | |\0",
    "| |          | |\0",
    "| |          | |\0",
    "| |          | |\0",
    "| |          | |\0",
    "| |          | |\0",
    "| |__________| |\0",
    "|______________|\0"
};

//12x19
char deck[CARD_H][CARD_W + 2] =
{
    " ________________ \0",
    "|  __________  |||\0",
    "| |          | |||\0",
    "| |          | |||\0",
    "| |          | |||\0",
    "| |          | |||\0",
    "| |   deck   | |||\0",
    "| |          | |||\0",
    "| |          | |||\0",
    "| |          | |||\0",
    "| |__________| |||\0",
    "|______________|_|\0"
};

char spades_card[CARD_H][CARD_W] =
{
    " ______________ \0",
    "|              |\0",
    "|              |\0",
    "|              |\0",
    "|      /\\      |\0",
    "|     /  \\     |\0",
    "|    /    \\    |\0",
    "|   (_/||\\_)   |\0",
    "|     /__\\     |\0",
    "|              |\0",
    "|              |\0",
    "|______________|\0"
};

char hearts_card[CARD_H][CARD_W] =
{
    " ______________ \0",
    "|              |\0",
    "|              |\0",
    "|              |\0",
    "|    _    _    |\0",
    "|   (  )(  )   |\0",
    "|    \\    /    |\0",
    "|     \\  /     |\0",
    "|      \\/      |\0",
    "|              |\0",
    "|              |\0",
    "|______________|\0"
};

char diamonds_card[CARD_H][CARD_W] =
{
    " ______________ \0",
    "|              |\0",
    "|              |\0",
    "|              |\0",
    "|      /\\      |\0",
    "|     /  \\     |\0",
    "|    /    \\    |\0",
    "|    \\    /    |\0",
    "|     \\  /     |\0",
    "|      \\/      |\0",
    "|              |\0",
    "|______________|\0"
};

char clubs_card[CARD_H][CARD_W] =
{
    " ______________ \0",
    "|              |\0",
    "|              |\0",
    "|              |\0",
    "|      __      |\0",
    "|    _(  )_    |\0",
    "|   {  }{  }   |\0",
    "|    - )( -    |\0",
    "|     /__\\     |\0",
    "|              |\0",
    "|              |\0",
    "|______________|\0"
};

// 6 x 8 image
char suits[4][6][8 + 1] =
{
    {
        "        \0",
        "   /\\   \0",
        "  /  \\  \0",
        " /    \\ \0",
        "(_/||\\_)\0",
        "  /__\\  \0"
    },

    {
        " _    _ \0",
        "(  )(  )\0",
        " \\    / \0",
        "  \\  /  \0",
        "   \\/   \0",
        "        \0"
    },

    {
        "   /\\   \0",
        "  /  \\  \0",
        " /    \\ \0",
        " \\    / \0",
        "  \\  /  \0",
        "   \\/   \0"
    },

    {
        "   __   \0",
        " _(  )_ \0",
        "{  }{  }\0",
        " - )( - \0",
        "  /__\\  \0",
        "        \0"
    }
};



int DrawACardFromDeck_A(CARD c, int num, int n) {

    //
    HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cinfo;
    cinfo.bVisible = 0;
    cinfo.dwSize = 1;
    if (SetConsoleCursorInfo(fd, &cinfo))
        ;
    //
    

    //int cardX = 0, cardY = 0;
    //int amount = 1;
    char p = ' ';
    int i = 0;

    // print part

    int image_h = CARD_H;
    int image_w = CARD_W;

    // 15 cards 20 x 20
    char images[MAXPRINTNUM][IMAGESIZE][IMAGESIZE] = { 0 };


    for (i = 0; i < image_h; i++) {
        if (c.suit == DIAMONDS)
            strcpy(images[0][i], diamonds_card[i]);
        else if (c.suit == SPADES)
            strcpy(images[0][i], spades_card[i]);
        else if (c.suit == CLUBS)
            strcpy(images[0][i], clubs_card[i]);
        else if (c.suit == HEARTS)
            strcpy(images[0][i], hearts_card[i]);
    }

    if (c.value == 1)
        images[0][1][1] = 'A';
    else if (c.value == 11)
        images[0][1][1] = 'J';
    else if (c.value == 12)
        images[0][1][1] = 'Q';
    else if (c.value == 13)
        images[0][1][1] = 'K';
    else if (c.value == 10) {
        images[0][1][1] = '1';
        images[0][1][2] = '0';
    }
    else
        images[0][1][1] = c.value + 48; //2-9


    // blank
    for (i = 0; i < image_h; i++) {
        strcpy(images[1][i], blank_card[i]);
    }


    // from deck
    drawing_A(images[1], 0, 0, 0);


    clearScreen(0, CARD_H, 0, screen_w);

    // to hand
    drawing_A(images[0], 1, num, 15 * n);

    //for (int i = 0; i < 4; i++) {
    //    for (int j = 0; j < 6; j++) {
    //        printf(suits[i][j]);
    //        printf("\n");
    //    }
    //}


    //const int width = 60;
    //const int height = 40;
    //int x = 0, y = 0;
    //int step_size_x = 5, velocityY = 1;

    return 0;
}

void printHand(HAND h) {

    for (int i = 0; i < h.numberOfCards; i++);


}

void printCardToScreen(char card[CARD_H][CARD_W], int y, int x) {
    for (int i = 0; i < CARD_H; i++) { //y
        for (int j = 0; j < CARD_W; j++) { //x
            screen[i + y][j + x] = card[i][j];
        }
    }
}

void printDeckToScreen(int y, int x) {
    for (int i = 0; i < CARD_H; i++) { //y
        for (int j = 0; j < CARD_W + 2; j++) { //x
            screen[i + y][j + x] = deck[i][j];
        }
    }
}



void drawing_A(char image[IMAGESIZE][IMAGESIZE], int to_hand, int cardNum, int num_newline) {
    char p = ' ';
    //int amount = 1;
    int blank_space = 0;

    //int num_newline = 0;

    if (!to_hand) {
        blank_space = 0;

    }
    else
        blank_space = screen_w;

    int is_finished = 0;
    //int is_blank_card = direction;


    while (!is_finished) {


        if (to_hand) {  //to user
            blank_space--;
            //num_newline = 15;
        }
        else {  //from deck
            blank_space++;
            cardNum = 0;
        }


        int printed_w = 0;
        int printed_h = num_newline;

        if (to_hand && (blank_space < cardNum * 2) || !to_hand && blank_space >= screen_w) {
            break;
        }

        clearScreen(num_newline, CARD_H, 0, CARD_W);

        printDeckToScreen(0, 0);
        int fix_pixel = CARD_W;

        for (int i = 0; i < CARD_H; i++) { //row

            printed_w = 0;

            for (int j = 0; j < blank_space; j++) {
                if (screen[printed_h][printed_w] != ' ' && screen[printed_h][printed_w] != '\0' && printed_w <= fix_pixel) {
                    printed_w++; //skip exist none-space pixel
                }
                else {
                    screen[printed_h][printed_w++] = ' ';
                }
            }

            //for (int j = 0;j < amount;j++) { // amount
            for (int k = 0; k < CARD_W; k++) { // column
                //p = *(*(image+i)+cardX);

                // next pixel of screen
                p = image[i][k];

                //out of screen
                if (printed_w < screen_w) {
                    //printf("%c", p);
                    screen[printed_h][printed_w++] = p;
                }
            }
            //}
            //next line
            printed_h++;
        }

        Display();
        Sleep(1);
    }
}



void overPrint(char* content, int y, int x, int length) {

    for (int j = 0; j < length; j++) {
        screen[y][j + x] = content[j];
    }
}


// 4/10
char skull[20][45] = {
"                      :::!~!!!!!:.          \0",
"                  .xUHWH!! !!?M88WHX:.      \0",
"                .X*#M@$!!  !X!M$$$$$$WWx:.  \0",
"               :!!!!!!?H! :!$!$$$$$$$$$$8X: \0",
"              !!~  ~:~!! :~!$!#$$$$$$$$$$8X:\0",
"             :!~::!H!<   ~.U$X!?R$$$$$$$$MM!\0",
"             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM!\0",
"               !:~~~ .:!M\"T#$$$$WX??#MRRMMM!\0",  
"               ~?WuxiW*`   `\"#$$$$8!!!!??!!!\0",  
"             :X- M$$$$       `\"T#$T~!8$WUXU~\0",
"            :%`  ~#$$$m:        ~!~ ?$$$$$$ \0",
"          :!`.-   ~T$$$$8xx.  .xWW- ~\"\"##*\" \0",
".....   -~~:<` !    ~?T#$$@@W@*?$$      /`  \0",
"W$@@M!!! .!~~ !!     .:XUW$W!~ `\"~:    :    \0",  
"#\"~~`.:x % `!!!H:   !WM$$$$Ti. : .!WUn+!`   \0",
":::~:!!`:X~ .: ?H.!u \"$$$B$$$!W:U!T$$M~     \0",
".~~   :X@!.-~   ?@WTWo(\"*$$$W$TH$! `        \0",  
"Wi.~!X$?!-~    : ?$$$B$Wu(\"**$RM!           \0",
"$R@i.~~ !     :   ~$$$$$B$$en:``            \0",
"?MXT@Wx.~    :     ~\"##*$$$$M~              \0"
};



/* draw image*/
void draw_big_image() {
    //for (int i = 0; i < 20; i++) {
    //    printf(Skull[i]);
    //    printf("\n");
    //}


    char p = ' ';
    //int amount = 1;
    int blank_space = 50;

    int is_finished = 0;
    //int is_blank_card = direction;


    while (!is_finished) {


        blank_space--;


        int printed_w = 0;
        int printed_h = 0;

        if (blank_space < 0) {
            break;
        }

        clearScreen(0, CARD_H, 0, CARD_W);


        for (int i = 0; i < 20; i++) { //row

            printed_w = 0;

            for (int j = 0; j < blank_space; j++) {
                //if (screen[printed_h][printed_w] != ' ' && screen[printed_h][printed_w] != '\0' && printed_w <= fix_pixel) {
                //    printed_w++; //skip exist none-space pixel
                //}
                //else {
                screenB[printed_h][printed_w++] = ' ';
                //}
            }

            //for (int j = 0;j < amount;j++) { // amount
            for (int k = 0; k < 45; k++) { // column
                //p = *(*(image+i)+cardX);

                // next pixel of screen
                p = skull[i][k];

                //out of screen
                if (printed_w < screen_w*2) {
                    //printf("%c", p);
                    screenB[printed_h][printed_w++] = p;
                }
            }
            //}
            //next line
            printed_h++;
        }

        DisplayYX(20,50);
        Sleep(1);
    }
}

#define BOMB 10

char nuclear[BOMB][44] = {
"              _. - ^ ^-- - ....,,-- - _   \n", 
"           _--                  --_       \n", 
"          <          BUST!>)              \n",
"           \\._                   _. /     \n",    
"              ```- - . . ,; .--'''        \n",
"                    | |   |               \n",  
"                 . -= ||  | |= -.         \n", 
"                 `- = #$ % &%$# = -'      \n", 
"                    | ;  : |              \n",
"           _____.,-# % &$@ % # & #~,._____\n"
};


void drawBust() {
    Sleep(500);
    clearScreen(0,0,0,0);

    for (int i = BOMB-1;i >= 0;i--) {
        clearScreen(0, 0, 0, 0);

        for (int j = 0; j < i; j++)
            printf("\n");
        for (int k = 0; k < BOMB - i; k++)
            printf(nuclear[k]);
        Sleep(200);
    }
}

