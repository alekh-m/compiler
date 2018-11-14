//Name: Alekh Maheshwari
//ID: 2015A7PS0097P

#include "parserDef.h"

void push (struct mystack *stack, int ele);
void pop (struct mystack *stack);
int top (struct mystack *stack);
void mystrcpy(char *a, int a_size , char *b);
void addinstore1(char** store1);
char* numtostring(char** store1, int k);
void fn_nthash(struct nonterminal** nthash, char *k1, int q);
void addin_nthash(struct nonterminal** nthash);
void fn_thash(struct terminal** thash, char *k1, int q);
void addin_thash(struct terminal** thash);
int getnum(char *word, struct nonterminal **nthash,  struct terminal **thash);
void fillLine(char* linebuffer, int** grammar, int rule, struct nonterminal **nthash,  struct terminal **thash);
void fillGrammar(FILE *grammarfp, char* linebuffer, int** grammar, struct nonterminal **nthash,  struct terminal **thash);
bool isT(int k);
bool isNT(int k);
bool isE(int k);
void compute_first(int **grammar, int nt, int arr[], int *indexf, int *indexr);
void fillFirst(int **first, int **grammar);
void remove_duplicates(int followset[]);
void appendfirst1(int followset[], int** first, int k, int* index3);
bool hasE(int** first, int k);
void compute_follow(int **grammar, int** first, int nt, int followset[], int *index3, int depth);
void fillFollow(int **follow, int**first, int **grammar);
void call1(int **grammar, int** parsetable, int** first, int** follow, int rj, int nt, int r);
void createParseTable1(int **grammar, int** parsetable, int** first, int** follow);
int stringtonum(char* c,struct terminal **thash);
struct tnode* findSuitableNode(struct tnode* trav, int* flag);
struct tnode* findNodeToCopyDetails12(struct tnode* trav1, int globalcount, int *localcount, int* flag1);
char* isLeaf(int k);
bool inFollow(int** follow, int nt, int t);
void parseInputSourceCode(int** grammar, int **parsetable, struct mystack* stack, struct terminal **thash, FILE* testcasefp, char* buffer, struct tnode* parsetree, int** follow, char*** hashArray, char** store1);
void printParseTree(struct tnode* trav2, FILE* parsetreefp, char** store1);
