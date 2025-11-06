#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"

// Hintergrundfarben
#define ANSI_BG_BLACK      "\x1b[40m"
#define ANSI_BG_RED        "\x1b[41m"
#define ANSI_BG_GREEN      "\x1b[42m"
#define ANSI_BG_YELLOW     "\x1b[43m"
#define ANSI_BG_BLUE       "\x1b[44m"
#define ANSI_BG_MAGENTA    "\x1b[45m"
#define ANSI_BG_CYAN       "\x1b[46m"
#define ANSI_BG_WHITE      "\x1b[47m"

// Texteffekte
#define ANSI_BOLD          "\x1b[1m"
#define ANSI_FAINT         "\x1b[2m"
#define ANSI_ITALIC        "\x1b[3m"
#define ANSI_UNDERLINE     "\x1b[4m"
#define ANSI_BLINK         "\x1b[5m"
#define ANSI_INVERT        "\x1b[7m"
#define ANSI_HIDDEN        "\x1b[8m"
#define ANSI_STRIKETHROUGH "\x1b[9m"

// Zurücksetzen
#define ANSI_RESET         "\x1b[0m"

const char* Colors[] = { ANSI_RESET,ANSI_COLOR_BLACK,ANSI_COLOR_RED,ANSI_COLOR_GREEN,ANSI_COLOR_YELLOW,ANSI_COLOR_BLUE,ANSI_COLOR_MAGENTA,ANSI_COLOR_CYAN,ANSI_COLOR_WHITE };

void RandomScreen(int l){
    for(int i = 0;i<l;i++){
        for(int j = 0;j<l;j++){
            int r = rand() % (sizeof(Colors) / sizeof(const char*));
            const char* col = Colors[r];
            printf("%s█",col);
        }
        printf("\n");
    }
}

int main() {
    //printf("Normaler Text ");
    //printf(ANSI_COLOR_RED "Rotes Text" ANSI_COLOR_RESET " Normaler Text ");
    //printf(ANSI_COLOR_GREEN "Grüner Text" ANSI_COLOR_RESET " Normaler Text\n");

    RandomScreen(20);

    return 0;
}
