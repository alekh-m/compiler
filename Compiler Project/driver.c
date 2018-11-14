//Name: Alekh Maheshwari
//ID: 2015A7PS0097P

#include "lexer.h"
#include "parser.h"

int main(int arg, char *argv[])
{
	printf("Both lexical and syntax analysis modules implemented.\n");	
	
	
	//driver details from parser
	//hash non terminals
	struct nonterminal **nthash=(struct nonterminal**)malloc(NTHASH*sizeof(struct nonterminal*));
	for (int q=0; q<NTHASH; q++){
    	nthash[q] = (struct nonterminal*)malloc(2*sizeof(struct nonterminal));
    }
	addin_nthash(nthash);
	
	//hash terminals
	struct terminal **thash=(struct terminal**)malloc(THASH*sizeof(struct terminal*));
	for (int q=0; q<THASH; q++){
		thash[q] = (struct terminal*)malloc(2*sizeof(struct terminal));
	}
	addin_thash(thash);
	
	//fill grammar array
	int **grammar = (int **)malloc(TOTAL_RULES* sizeof(int *));
	for (int q=0; q<TOTAL_RULES; q++){
		grammar[q] = (int *)malloc(15*sizeof(int));
	}
		
	for(int q=0; q<TOTAL_RULES; q++)
	{
		for(int j=0; j<15; j++)
		{
			grammar[q][j]=0;
		}
	}
	
	FILE* grammarfp=fopen("grammar.txt", "r+");
	char* linebuffer=(char*)malloc(150*sizeof(char));
	for(int f1=0; f1<150; f1++)
	{
		linebuffer[f1]='\0';
	}
	fillGrammar(grammarfp, linebuffer, grammar, nthash, thash);
	fclose(grammarfp);
	
	//create first sets
	int **first = (int **)malloc(46* sizeof(int *));
	for (int q=0; q<46; q++){
		first[q] = (int *)malloc(40*sizeof(int));
	}
	for(int q=0; q<46; q++)
	{
		for(int j=0; j<40; j++)
		{
			first[q][j]=0;
		}
	}
	fillFirst(first, grammar);
	
	
	//create follow sets
	int **follow = (int **)malloc(46* sizeof(int *));
	for (int q=0; q<46; q++){
		follow[q] = (int *)malloc(40*sizeof(int));
	}
	for(int q=0; q<46; q++)
	{
		for(int j=0; j<40; j++)
		{
			follow[q][j]=0;
		}
	}
	fillFollow(follow, first, grammar);
	
	
	//create parse table
	int **parsetable = (int **)malloc(46* sizeof(int *));
	for (int q=0; q<46; q++){
		parsetable[q] = (int *)malloc(41*sizeof(int));
	}
	for(int q=0; q<46; q++)
	{
		for(int j=0; j<41; j++)
		{
			parsetable[q][j]=ERROR;
		}
	}
	createParseTable1(grammar,parsetable,first,follow);
	
	
	//declare stack
	struct mystack* stack=(struct mystack*)malloc(sizeof(struct mystack));
	stack->first=NULL;
	stack->count=0;
	push(stack,140);
	push(stack,1);
	
	
	//declare parsetree and put value corresponding to <mainFunction> in first node
	struct tnode* parsetree=(struct tnode*)malloc(sizeof(struct tnode));
	parsetree->val=1;// value corresponding to <mainFunction>
	mystrcpy(parsetree->lexeme,31,"---");
	parsetree->line=0;
	parsetree->parent=NULL;
	parsetree->num=-1;
	parsetree->rnum=-1;
	for(int q=0; q<15; q++)
	{
		parsetree->child[q]=NULL;
	}	
		
	
	//for tokenNo to token
	char **store1 = (char **)malloc(141* sizeof(char *));
	for (int q=0; q<141; q++){
		store1[q] = (char *)malloc(31*sizeof(char));
	}
	for(int q=0; q<141; q++)
	{
		for(int j=0; j<31; j++)
		{
			store1[q][j]='\0';
		}
	}
	addinstore1(store1);
	
	
	
	
	//driver lines from lexer
	//for keywords like num, rnum etc.
	char ***hashArray = (char ***)malloc(HASH_SIZE*sizeof(char **));
	for (int q1=0; q1<HASH_SIZE; q1++)
	{
		hashArray[q1] = (char **)malloc(2*sizeof(char*));
		for(int q2=0; q2<2; q2++)
		{
			hashArray[q1][q2]= (char *)malloc(20*sizeof(char));
		}
	}
	
	for(int q1=0; q1<HASH_SIZE; q1++)
	{
		for(int q2=0; q2<2; q2++)
		{
			for(int q3=0; q3<20; q3++)
			{
				hashArray[q1][q2][q3]='\0';
			}
		}
	}
	
	//initialize i
	i=0;
	//make buffer
	char *buffer=(char*)malloc(BUF_SIZE*sizeof(char));
	
	//hash keywords
	addInHash(hashArray);
	
	
	//print tokens in for loop(not while)
	/*for(int q=0;q<130;q++)
	{
		struct tokenInfo t1=getNextToken(fp,buffer);
		printf("%s,%s,%d\n",t1.tokenName, t1.lexeme, t1.line);
		
	}*/
	
	
	//driver details
	printf("Select an option\n");
	printf("1. Remove comments\n");
	printf("2. Print token list\n");
	printf("3. Parse to verify syntactic correctness\n");
	printf("4. Print parse tree\n");
	int option;
	scanf("%d",&option);
	
	if(option==1)
	{
		removeComments(argv[1]);
	}
	
	if(option==2)
	{
		FILE *printtokens=fopen(argv[1],"r+");
		printtokens=getStream(printtokens,buffer);
		struct tokenInfo tk=getNextToken(printtokens, buffer,hashArray);
		//while(strcmp(tk.tokenName,"$")!=0)
		for(int kl=0; kl<500; kl++)
		{
			if(strcmp(tk.tokenName,"$")!=0)
				printf("Token=%s, Lexeme=%s, Line=%d\n",tk.tokenName, tk.lexeme, tk.line);
			tk=getNextToken(printtokens, buffer,hashArray);
		}
		fclose(printtokens);
	}
	
	if(option==3)
	{
		FILE* testcasefp=fopen(argv[1],"r+");
		testcasefp=getStream(testcasefp,buffer);
		parseInputSourceCode(grammar,parsetable,stack,thash, testcasefp,buffer, parsetree, follow, hashArray,store1);
		fclose(testcasefp);
	}
	
	if(option==4)
	{
		FILE* testcasefp=fopen(argv[1],"r+");
		testcasefp=getStream(testcasefp,buffer);
		parseInputSourceCode(grammar,parsetable,stack,thash, testcasefp,buffer, parsetree, follow, hashArray,store1);
		struct tnode* trav2=parsetree;
		FILE* parsetreefp=fopen(argv[2],"w");
		printParseTree(trav2,parsetreefp, store1);
		fclose(testcasefp);
		fclose(parsetreefp);
	}
	
	return 0;
}
