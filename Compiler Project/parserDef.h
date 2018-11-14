//Name: Alekh Maheshwari
//ID: 2015A7PS0097P

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define NTHASH 137
#define THASH 63
#define TOTAL_RULES 88
#define ERROR 200

//for hash table
struct nonterminal{
	char name[30];
	int n;
};

//for hash table
struct terminal{
	char name[10];
	int n;
};


//for parse tree
struct tnode
{
	int val;
	char lexeme[31];
	int line;
	int num;
	float rnum;
	struct tnode *child[15];
	struct tnode *parent;
};


//for stack
struct snode
{
	int val;
	//char lexeme[31];
	//int line;
	struct snode *next;
};

//stack head
struct mystack
{
	int count;
	struct snode *first;
};
