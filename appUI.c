#ifndef appUI_C
#define appUI_C

#include <stdio.h>
#include <conio.h>
#include <windows.h>

void titleScreen(){
    int i = 6;
    char *title = "Text/titleScreen.txt";
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
    char *title = "Text/mainMenu.txt";
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

void howTo(){

    ass:
    system("cls");
    fflush(stdin);

    int i = 6;
    char *title = "Text/HowToUse.txt";
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

    int pilihan;
    scanf("%d", &pilihan);
    

    switch(pilihan){
        case 1:
        system("cls");
        htCalc();
        break;

        case 2:
        system("cls");
        htConv();
        break;

        default:
        goto ass;

    }
    getch();
    return;
}

void htCalc(){
    int i = 6;
    char *title = "Text/HowToUseCalc.txt";
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

void htConv(){
    int i = 6;
    char *title = "Text/HowToUseConvCalc.txt";
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
#endif