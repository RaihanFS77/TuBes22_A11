#ifndef appUI_C
#define appUI_C

#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include "appUI.h"

void titleScreen(){
    int i = 6;
    char *title = "titleScreen.txt";
    FILE *fp = fopen(title,"r");

    if (fp == NULL){
        printf("Error : File could not be read");
        return;
    }

    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    while(i > 0){
        printf("\n");
        i--;
    }
    
    while(fgets(buffer,MAX_LENGTH,fp)){
        printf("%s", buffer);
    }
    themeSong();
    fclose(fp);
    sleep(1);
    system("cls");

    return;
}

void themeSong(){
    Beep(698,600);
    Beep(523,500);
    Beep(880,300);
    Beep(523,200);
    Beep(698,150);
    Beep(783,400);

    return;
}

void mainMenu(){
    int i = 6;
    char *title = "mainMenu.txt";
    FILE *fp = fopen(title,"r");

    if (fp == NULL){
        printf("Error : File could not be read");
        return;
    }

    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    while(i > 0){
        printf("\n");
        i--;
    }
    
    while(fgets(buffer,MAX_LENGTH,fp)){
        printf("%s", buffer);
    }
    fclose(fp);
    sleep(1);

    return;

}

int optMenu(){
    mainMenu();
    fflush(stdin);
    int pilihan;
    scanf("%d", &pilihan);

    return pilihan;
}
#endif