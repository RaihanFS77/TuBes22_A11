#include <stdio.h>
#include <string.h>
#include <time.h>
#include "CalcTree.h"

struct history{
    char input[200];
    double hasil;
    char waktu[200];
}Record;

int saveHistory(char *_input, double _hasil);
int readHistory();