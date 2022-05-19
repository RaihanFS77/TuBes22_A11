#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h> //untuk parsing dari input string

#define KURUNG_BUKA '('
#define KURUNG_TUTUP ')'
#define PointDecimal '.'
#define PLUS '+'
#define MINUS '-'
#define KALI '*'
#define BAGI '/'
#define AKAR_KUADRAT 'v'
#define PANGKAT '^'
#define PERSENTASE '%'

#define MAX 0x3f3f3f3f

#ifndef CalcTree_H
#define CalcTree_H

typedef struct TNode* addrNode;

typedef struct TNode{
    bool isSymbol;
    double number;
    char symbol; 
    addrNode leftChild;
    addrNode rightChild;
}Node;

double result;
char UserInput[100];

#endif
