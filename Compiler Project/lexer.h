//Name: Alekh Maheshwari
//ID: 2015A7PS0097P

#include "lexerDef.h"



void hash(char k[], char ***hashArray);
void addInHash(char ***hashArray);
bool isKeyword(char t[], char ***hashArray);
FILE* getStream(FILE *fp, char* buffer);
void bufferEndCheck(FILE *fp, char* buffer);
void removeWhiteSpace(FILE *fp, char* buffer);
struct tokenInfo makeToken(struct tokenInfo token, char tokenName[], char lexeme[], int line);
struct tokenInfo getNextToken(FILE *fp, char* buffer, char ***hashArray);
void removeComments(char *testcaseFile);

