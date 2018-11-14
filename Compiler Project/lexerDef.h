//Name: Alekh Maheshwari
//ID: 2015A7PS0097P

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>


#define BUF_SIZE 1024
#define HASH_SIZE 33 //for keywords

struct tokenInfo{
	char tokenName[10];
	char lexeme[31];
	int line;
};

static int line=1;

//extern= only declaration here, no definition
extern int i;
