#include <stdio.h>
#include <string.h>
#include <time.h>
#include "CalcTree.h"

struct history{
    char input[200];
    double hasil;
    char waktu[200];
}Record;

int saveHistory(char *_input, double _hasil){
    FILE* storage = 0;
    struct history Record;
    time_t _time;

    time(&_time);
    struct tm *tmi;
        tmi = localtime(&_time);
    strftime(Record.waktu,100,"%d %b %Y %H:%M",tmi);
    strcpy(Record.input,_input);
    Record.hasil = _hasil;

    fopen_s(&storage,"history.dat","ab+");
    if(!storage){
        return 1;
    }

    fwrite(&Record,sizeof(Record),1,storage);
    fclose(storage);

    return 0;
}

int readHistory(){  //
    system("cls");
    FILE* pFile = 0;
    int i = 1;
    pFile = fopen("history.dat","ab+"); // append and update binary, can be read
    if(!pFile)
      return 1; //fopen error
    printf("\n\n\t===============================================\n");
    printf("\n\t\t          History\n\n");
		printf(" \t===============================================\n\n");
    printf( "  \xDA\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n" );
    printf( "  \xB3 %-3s\xB3        %-12s\xB3         %-31s\xB3      %-14s\xB3\n", "No","Time", "Arithmetic Expression", "Result");
    printf( "  \xC3\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n" );

    do{
        fseek(pFile,(-i)*sizeof(Record),SEEK_END);
        fread(&Record,sizeof(Record),1,pFile);
        if(!feof(pFile) && i <= 30){
            if (ceil(Record.hasil) > Record.hasil)
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19f\xB3\n", i++, Record.waktu, Record.input, Record.hasil);
            else
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19d\xB3\n", i++, Record.waktu, Record.input, (int)Record.hasil);
        }
    }while(!feof(pFile) && i <= 30);
    printf( "  \xC0\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" );
        
    fclose(pFile);

    printf("\n\n\n  [] Tekan tombol apapun untuk kembali []"); 

    return 0;
}

