#include <stdio.h>

#define MAXSIZE 10000

typedef struct n{
	short s_integer[MAXSIZE];
	short s_decimal[MAXSIZE];
}NUMBER;

int inputNum(NUMBER * f_num, int f_n);
short charToNum(char f_c);
void numFlip(short * f_num);
void transNum(NUMBER * f_number, NUMBER * f_resultNumber, int f_n, int f_m);
void printNum(short * f_num);
void printTheWholeNum(NUMBER * f_num, int f_m);