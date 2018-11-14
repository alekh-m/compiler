//Name: Alekh Maheshwari
//ID: 2015A7PS0097P

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#include "lexer.h"
#include "parser.h"


//stack functions
void push (struct mystack *stack, int ele)
{
	
	struct snode *link=(struct snode*)malloc (sizeof(struct snode));
	link->val=ele;
	link->next=stack->first;
	stack->first=link;
	stack->count++;
}

void pop (struct mystack *stack)
{
	if(stack->first==NULL)
	{
		//printf("ERROR: STACK EMPTY");
	}
	else
	{
		struct snode*templink=(struct snode*)malloc(sizeof(struct snode));
		templink=stack->first;
		stack->first=templink->next;
		stack->count --;
		free(templink);
	}
}

int top (struct mystack *stack)
{
	if(stack->first==NULL)
	{return 0;}
	else
	{
		return stack->first->val;
	}
}

//copies only string and rest all is \0
void mystrcpy(char *a, int a_size , char *b)
{
	for(int f1=0; f1<a_size; f1++)
	{
		a[f1]='\0';
	}
	
	for(int f1=0; f1<strlen(b)+1; f1++)
	{
		a[f1]=b[f1];
	}
}


/*
int chartonum(char c)
{
	if(c=='0')
		return 0;
	if(c=='1')
		return 1;
	if(c=='2')
		return 2;
	if(c=='3')
		return 3;
	if(c=='4')
		return 4;
	if(c=='5')
		return 5;
	if(c=='6')
		return 6;
	if(c=='7')
		return 7;
	if(c=='8')
		return 8;
	if(c=='9')
		return 9;
}

int getnum(char *s)
{
	char k[100];
	mystrcpy(k,100,s);
	int i1=0;
	int num=0;
	int ten=1;
	while(k[i1]!='\0')
	{
		i1++;
	}
	i1--;
	for(int i2=i1; i2>=0; i2--)
	{
		num=num+ten*chartonum(k[i2]);
		ten=ten*10;
	}
	return num;
}

float getrnum(char *s)
{
	char k[100];
	mystrcpy(k,100,s);
	int i1=0;
	int num=0;
	int ten=1;
	while(k[i1]!='\0')
	{
		i1++;
	}
	i1--;
	
	for(int i2=i1; i2>=i1-1; i2--)
	{
		num=num+ten*chartonum(k[i2]);
		ten=ten*10;
	}
	
	float after=(float)num/100.0;
	num=0;
	i1=i1-3;
	ten=1;
	for(int i2=i1; i2>=0; i2--)
	{
		num=num+ten*chartonum(k[i2]);
		ten=ten*10;
	}
	return (float)num+after;	
}*/


//for tokenNo to token
void addinstore1(char** store1)
{
	mystrcpy(store1[0],31, "");
	mystrcpy(store1[1],31, "<mainFunction>");
	mystrcpy(store1[2],31, "<stmtsAndFunctionDefs>");
	mystrcpy(store1[3],31, "<ext_stmtsAndFunctionDefs>");
	mystrcpy(store1[4],31, "<stmtOrFunctionDef>");
	mystrcpy(store1[5],31, "<stmt>");
	mystrcpy(store1[6],31, "<functionDef>");
	mystrcpy(store1[7],31, "<parameter_list>");
	mystrcpy(store1[8],31, "<type>");
	mystrcpy(store1[9],31, "<remainingList>");
	mystrcpy(store1[10],31, "<declarationStmt>");
	mystrcpy(store1[11],31, "<var_list>");
	mystrcpy(store1[12],31, "<more_ids>");
	mystrcpy(store1[13],31, "<assignmentStmt_type1>");
	mystrcpy(store1[14],31, "<assignmentStmt_type2>");
	mystrcpy(store1[15],31, "<leftHandSide_singleVar>");
	mystrcpy(store1[16],31, "<leftHandSide_listVar>");
	mystrcpy(store1[17],31, "<rightHandSide_type1>");
	mystrcpy(store1[18],31, "<rightHandSide_type2>");
	mystrcpy(store1[19],31, "<sizeExpression>");
	mystrcpy(store1[20],31, "<ifStmt>");
	mystrcpy(store1[21],31, "<ext_ifStmt>");
	mystrcpy(store1[22],31, "<otherStmts>");
	mystrcpy(store1[23],31, "<ioStmt>");
	mystrcpy(store1[24],31, "<funCallStmt>");
	mystrcpy(store1[25],31, "<inputParameterList>");
	mystrcpy(store1[26],31, "<listVar>");
	mystrcpy(store1[27],31, "<arithmeticExpression>");
	mystrcpy(store1[28],31, "<ext_arithmeticExpression>");
	mystrcpy(store1[29],31, "<arithmeticTerm>");
	mystrcpy(store1[30],31, "<ext_arithmeticTerm>");
	mystrcpy(store1[31],31, "<factor>");
	mystrcpy(store1[32],31, "<operator_lowPrecedence>");
	mystrcpy(store1[33],31, "<operator_highPrecedence>");
	mystrcpy(store1[34],31, "<booleanExpression>");
	mystrcpy(store1[35],31, "<constrainedVars>");
	mystrcpy(store1[36],31, "<var>");
	mystrcpy(store1[37],31, "<matrix>");
	mystrcpy(store1[38],31, "<rows>");
	mystrcpy(store1[39],31, "<ext_rows>");
	mystrcpy(store1[40],31, "<row>");
	mystrcpy(store1[41],31, "<ext_row>");
	mystrcpy(store1[42],31, "<remainingColElements>");
	mystrcpy(store1[43],31, "<matrixElement>");
	mystrcpy(store1[44],31, "<logicalOp>");
	mystrcpy(store1[45],31, "<relationalOp>");
	
	mystrcpy(store1[101],31, "ASSIGNOP");
	mystrcpy(store1[102],31, "FUNID");
	mystrcpy(store1[103],31, "ID");
	mystrcpy(store1[104],31, "NUM");
	mystrcpy(store1[105],31, "RNUM");
	mystrcpy(store1[106],31, "STR");
	mystrcpy(store1[107],31, "END");
	mystrcpy(store1[108],31, "INT");
	mystrcpy(store1[109],31, "REAL");
	mystrcpy(store1[110],31, "STRING");
	mystrcpy(store1[111],31, "MATRIX");
	mystrcpy(store1[112],31, "MAIN");
	mystrcpy(store1[113],31, "SQO");
	mystrcpy(store1[114],31, "SQC");
	mystrcpy(store1[115],31, "OP");
	mystrcpy(store1[116],31, "CL");
	mystrcpy(store1[117],31, "SEMICOLON");
	mystrcpy(store1[118],31, "COMMA");
	mystrcpy(store1[119],31, "IF");
	mystrcpy(store1[120],31, "ELSE");
	mystrcpy(store1[121],31, "ENDIF");
	mystrcpy(store1[122],31, "READ");
	mystrcpy(store1[123],31, "PRINT");
	mystrcpy(store1[124],31, "FUNCTION");
	mystrcpy(store1[125],31, "PLUS");
	mystrcpy(store1[126],31, "MINUS");
	mystrcpy(store1[127],31, "MUL");
	mystrcpy(store1[128],31, "DIV");
	mystrcpy(store1[129],31, "SIZE");
	mystrcpy(store1[130],31, "AND");
	mystrcpy(store1[131],31, "OR");
	mystrcpy(store1[132],31, "NOT");
	mystrcpy(store1[133],31, "LT");
	mystrcpy(store1[134],31, "LE");
	mystrcpy(store1[135],31, "EQ");
	mystrcpy(store1[136],31, "GT");
	mystrcpy(store1[137],31, "GE");
	mystrcpy(store1[138],31, "NE");
	mystrcpy(store1[139],31, "E");
	mystrcpy(store1[140],31, "$");
}

char* numtostring(char** store1, int k)
{
	return store1[k];
}


//hash non terminals
void fn_nthash(struct nonterminal** nthash, char *k1, int q)
{
	int index1;
	char k[30];
	mystrcpy(k,30,k1);
	index1=(int)k[2]+(int)k[3]*2+(int)k[7]*4+(int)k[17]*5;
	index1=index1%NTHASH;
	//printf("%s",k);
	if(nthash[index1][0].n==0)
	{
		for(int f1=0; f1<30; f1++)
		{
			nthash[index1][0].name[f1]='\0';
		}
		mystrcpy(nthash[index1][0].name,30,k);
		
		nthash[index1][0].n=q;
	}
	else
	{
		for(int f1=0; f1<30; f1++)
		{
			nthash[index1][1].name[f1]='\0';
		}
		mystrcpy(nthash[index1][1].name,30,k);
		nthash[index1][1].n=q;
	}
}

void addin_nthash(struct nonterminal** nthash)
{
	for(int q=0;q<NTHASH; q++)
	{
		for(int j=0; j<2;j++)
		{
			for(int m=0;m<30;m++)
				nthash[q][j].name[m]='\0';
			nthash[q][j].n=0;
		}
	}
	fn_nthash(nthash, "<mainFunction>", 1);
	fn_nthash(nthash, "<stmtsAndFunctionDefs>", 2);
	fn_nthash(nthash, "<ext_stmtsAndFunctionDefs>",3);
	fn_nthash(nthash, "<stmtOrFunctionDef>",4);
	fn_nthash(nthash, "<stmt>",5);
	fn_nthash(nthash, "<functionDef>",6);
	fn_nthash(nthash, "<parameter_list>",7);
	fn_nthash(nthash, "<type>",8);
	fn_nthash(nthash, "<remainingList>",9);
	fn_nthash(nthash, "<declarationStmt>",10);
	fn_nthash(nthash, "<var_list>",11);
	fn_nthash(nthash, "<more_ids>",12);
	fn_nthash(nthash, "<assignmentStmt_type1>",13);
	fn_nthash(nthash, "<assignmentStmt_type2>",14);
	fn_nthash(nthash, "<leftHandSide_singleVar>",15);
	fn_nthash(nthash, "<leftHandSide_listVar>",16);
	fn_nthash(nthash, "<rightHandSide_type1>",17);
	fn_nthash(nthash, "<rightHandSide_type2>",18);
	fn_nthash(nthash, "<sizeExpression>",19);
	fn_nthash(nthash, "<ifStmt>",20);
	fn_nthash(nthash, "<ext_ifStmt>",21);
	fn_nthash(nthash, "<otherStmts>",22);
	fn_nthash(nthash, "<ioStmt>",23);
	fn_nthash(nthash, "<funCallStmt>",24);
	fn_nthash(nthash, "<inputParameterList>",25);
	fn_nthash(nthash, "<listVar>",26);
	fn_nthash(nthash, "<arithmeticExpression>",27);
	fn_nthash(nthash, "<ext_arithmeticExpression>",28);
	fn_nthash(nthash, "<arithmeticTerm>",29);
	fn_nthash(nthash, "<ext_arithmeticTerm>",30);
	fn_nthash(nthash, "<factor>",31);
	fn_nthash(nthash, "<operator_lowPrecedence>",32);
	fn_nthash(nthash, "<operator_highPrecedence>",33);
	fn_nthash(nthash, "<booleanExpression>",34);
	fn_nthash(nthash, "<constrainedVars>",35);
	fn_nthash(nthash, "<var>",36);
	fn_nthash(nthash, "<matrix>",37);
	fn_nthash(nthash, "<rows>",38);
	fn_nthash(nthash, "<ext_rows>",39);
	fn_nthash(nthash, "<row>",40);
	fn_nthash(nthash, "<ext_row>",41);
	fn_nthash(nthash, "<remainingColElements>",42);
	fn_nthash(nthash, "<matrixElement>",43);
	fn_nthash(nthash, "<logicalOp>",44);
	fn_nthash(nthash, "<relationalOp>",45);
}


//hash terminals
void fn_thash(struct terminal** thash, char *k1, int q)
{
	int index1;
	char k[10];
	mystrcpy(k,10,k1);
	index1=(int)k[0]+(int)k[1]*2+(int)k[2]*3;
	index1=index1%THASH;
	if(thash[index1][0].n==0)
	{
		for(int f1=0; f1<10; f1++)
		{
			thash[index1][0].name[f1]='\0';
		}
		mystrcpy(thash[index1][0].name ,10,k);
		thash[index1][0].n=q;
	}
	else
	{
		for(int f1=0; f1<10; f1++)
		{
			thash[index1][1].name[f1]='\0';
		}
		mystrcpy(thash[index1][1].name,10,k);
		thash[index1][1].n=q;
	}
}

void addin_thash(struct terminal** thash)
{
	for(int q=0;q<THASH; q++)
	{
		for(int j=0; j<2;j++)
		{
			for(int m=0;m<10;m++)
				thash[q][j].name[m]='\0';
			thash[q][j].n=0;
		}
	}
	fn_thash(thash, "ASSIGNOP", 101);
	fn_thash(thash, "FUNID", 102);
	fn_thash(thash, "ID", 103);
	fn_thash(thash, "NUM", 104);
	fn_thash(thash, "RNUM", 105);
	fn_thash(thash, "STR", 106);
	fn_thash(thash, "END", 107);
	fn_thash(thash, "INT", 108);
	fn_thash(thash, "REAL", 109);
	fn_thash(thash, "STRING", 110);
	fn_thash(thash, "MATRIX", 111);
	fn_thash(thash, "MAIN", 112);
	fn_thash(thash, "SQO", 113);
	fn_thash(thash, "SQC", 114);
	fn_thash(thash, "OP", 115);
	fn_thash(thash, "CL", 116);
	fn_thash(thash, "SEMICOLON", 117);
	fn_thash(thash, "COMMA", 118);
	fn_thash(thash, "IF", 119);
	fn_thash(thash, "ELSE", 120);
	fn_thash(thash, "ENDIF", 121);
	fn_thash(thash, "READ", 122);
	fn_thash(thash, "PRINT", 123);
	fn_thash(thash, "FUNCTION", 124);
	fn_thash(thash, "PLUS", 125);
	fn_thash(thash, "MINUS", 126);
	fn_thash(thash, "MUL", 127);
	fn_thash(thash, "DIV", 128);
	fn_thash(thash, "SIZE", 129);
	fn_thash(thash, "AND", 130);
	fn_thash(thash, "OR", 131);
	fn_thash(thash, "NOT", 132);
	fn_thash(thash, "LT", 133);
	fn_thash(thash, "LE", 134);
	fn_thash(thash, "EQ", 135);
	fn_thash(thash, "GT", 136);
	fn_thash(thash, "GE", 137);
	fn_thash(thash, "NE", 138);
	fn_thash(thash, "E", 139);
	fn_thash(thash, "$", 140);
}


//get number associated with each terminal or non terminal when we dont know whether its a terminal or non terminal
int getnum(char *word, struct nonterminal **nthash,  struct terminal **thash)
{
	int index1;
	if(word[0]=='<')
	{
		index1=(int)word[2]+(int)word[3]*2+(int)word[7]*4+(int)word[17]*5;
		index1=index1%NTHASH;
		if(strcmp(nthash[index1][0].name,word)==0)
		{
			return nthash[index1][0].n;
		}
		else if(strcmp(nthash[index1][1].name,word)==0)
		{
			return nthash[index1][1].n;
		}
		else
			return 0;
	}
	else
	{
		index1=(int)word[0]+(int)word[1]*2+(int)word[2]*3;
		index1=index1%THASH;
		if(strcmp(thash[index1][0].name,word)==0)
		{
			return thash[index1][0].n;
		}
		else if(strcmp(thash[index1][1].name,word)==0)
		{
			return thash[index1][1].n;
		}
		else
			return 0;
	}
}

//to fill a line of grammar array.. this function is called by fillGrammar
void fillLine(char* linebuffer, int** grammar, int rule, struct nonterminal **nthash,  struct terminal **thash)
{
	char word[30];
	int m;
	int g=0;
	int q=0;
	int w=0;
	while(true)
	{
		w=0;
		for(int j=0; j<30; j++)
			word[j]='\0';
		while(linebuffer[q]!=' ' && linebuffer[q]!='\n' && linebuffer[q]!='\r')
		{
			word[w]=linebuffer[q];
			q++;
			w++;
		}
		q++;
		//printf("%s ",word);
		if(word[0]!='=')
		{
			m=getnum(word, nthash, thash);
			grammar[rule][g]=m;
			g++;
		}
		if(linebuffer[q]=='\0' || linebuffer[q]=='\n' || linebuffer[q]=='\r')
			break;
		
	}
	for(int f1=0; f1<150; f1++)
	{
		linebuffer[f1]='\0';
	}
}

//fill grammar array
void fillGrammar(FILE *grammarfp, char* linebuffer, int** grammar, struct nonterminal **nthash,  struct terminal **thash)
{
	int rule=0;
	while(fgets(linebuffer, 150, grammarfp)!=NULL)
	{
		fillLine(linebuffer, grammar, rule, nthash, thash);
		rule++;
	}
}

bool isT(int k)
{
	if(k>100)
		return true;
	else
		return false;
}

bool isNT(int k)
{
	if(k<100)
		return true;
	else
		return false;
}

//is epsilon
bool isE(int k)
{
	if(k==139)
		return true;
	else
		return false;
}

//compute first of a particular NT
void compute_first(int **grammar, int nt, int arr[], int *indexf, int *indexr)
{ 
	//check every rule
	for(int rn=0; rn<TOTAL_RULES; rn++)
	{
		*indexr=1; //index of column of a particular grammar rule
		if(grammar[rn][0]==nt)
		{
			//terminal and not e
			if(isT(grammar[rn][*indexr]) && !isE(grammar[rn][*indexr]))
			{
				arr[*indexf]=grammar[rn][*indexr];
				*indexf=*indexf+1;
			}
			
			//non terminal
			else if(isNT(grammar[rn][*indexr]))
			{
				compute_first(grammar, grammar[rn][*indexr], arr, indexf, indexr);
			}
			
			//empty terminal
			else if(isE(grammar[rn][*indexr]))
			{
				arr[*indexf]=grammar[rn][*indexr];
				*indexr=*indexr+1;
				*indexf=*indexf+1;
			}
			
		}
	}
}

//fill first
void fillFirst(int **first, int **grammar)
{
	//compute for all rules
	
	for(int nt=1; nt<=45; nt++)
	{
		int indexf=0; //index of column of first of a particular NT (where to put next terminal obtained)
		int indexr=1; //index of column of a particular grammar rule
		int arr[40];
		for(int f1=0; f1<40; f1++)
		{
			arr[f1]=0;
		}
		compute_first(grammar, nt, arr, &indexf, &indexr);
		for(int f1=0; f1<40; f1++)
		{
			first[nt][f1]=arr[f1];
			//printf("%d ",arr[f1]);
		}
		
		
	}
	first[41][2]=0;//printf("\n");
}



//ALL these for computing FOLLOW
void remove_duplicates(int followset[])
{
	int c,d;
	int count=0;
	int tarr[500];
	for(int temp=0; temp<500; temp++)
	{
		tarr[temp]=0;
	}
	for(c=0;c<500;c++)
   	{
      for(d=0;d<count;d++)
      {
         if(followset[c]==tarr[d])
            break;
      }
      if(d==count)
      {
         tarr[count] = followset[c];
         count++;
      }
   	}
   	for(int temp=0; temp<500; temp++)
	{
		followset[temp]=tarr[temp];
	}
}

void appendfirst1(int followset[], int** first, int k, int* index3)
{
	int j=0;
	while(first[k][j]!=0 )
	{
		if(first[k][j]!=139)
		{
			followset[*index3]=first[k][j];
			j++;
			*index3=*index3+1;
		}
		else
		{
			j++;
		}
	}
}

//to check if first of a non terminal contains e
bool hasE(int** first, int k)
{
	for(int t=0;t<40;t++)
	{
		if(first[k][t]==139)
			return true;
	}
	return false;
}

void compute_follow(int **grammar, int** first, int nt, int followset[], int *index3, int depth)
{		
		for(int ri=0; ri<TOTAL_RULES; ri++)
		{
			for(int rj=1; rj<15; rj++)
			{
				if(grammar[ri][rj]==nt)
				{
					int followingrule[40];
					for(int temp=0; temp<40; temp++)
					{
						followingrule[temp]=0;
					}
					int followingrulestart=rj+1;
					for(int fr=0; fr<40-followingrulestart; fr++)
					{
						followingrule[fr]=grammar[ri][followingrulestart];
						followingrulestart++;
					}
					if(followingrule[0]==0)
					{
						if(depth>20)
							{return;}
						depth=depth+1;
						compute_follow(grammar, first, grammar[ri][0], followset, index3, depth);
					}
					else if(isT(followingrule[0]) && !isE(followingrule[0]) && followingrule[0]!=0)
					{
						followset[*index3]=followingrule[0];
						*index3=*index3+1;
					}
					else if(isNT(followingrule[0]) && followingrule[0]!=0)
					{
						for(int temp=0; temp<40; temp++)
						{
							if(followingrule[temp]==0)
							{
								if(depth>20)
									{return;}
								depth=depth+1;
								compute_follow(grammar, first, grammar[ri][0], followset, index3, depth);
								break;
							}
							if(isT(followingrule[temp]))
							{
								followset[*index3]=followingrule[temp];
								*index3=*index3+1;
								break;
							}
							//dont append epsilon
							appendfirst1(followset, first, followingrule[temp], index3);
							if(!hasE(first, followingrule[temp]))
								break;
						}
					}
				}
			}
		}
}

void fillFollow(int **follow, int**first, int **grammar)
{
	
	for(int nt=1; nt<=45; nt++)
	{
		int index3=0;
		int followset[500];
		for(int f1=0; f1<500; f1++)
		{
			followset[f1]=0;
		}
		follow[1][0]=140;
		int depth=0;
		compute_follow(grammar, first, nt, followset, &index3, depth);
		remove_duplicates(followset);
		for(int f1=0; f1<40; f1++)
		{
			follow[nt][f1]=followset[f1];
		}
	}
	
}

/*void createParseTable(int **grammar, int** parsetable, int** first, int** follow)
{
	int nt,flag,nextsym,followj,firstj; 
	for(int r=0; r<TOTAL_RULES; r++)
	{
		flag=0;
		nt=grammar[r][0];//LHS of production rule
		nextsym=grammar[r][1];//first symbol in RHS of production rule
		
		if(isT(nextsym) && !isE(nextsym))
		{
			parsetable[nt][nextsym-100]=r;
		}
		
		if(isE(nextsym))
		{
			followj=0;
			//follow[nt][followj] is a T
			while(follow[nt][followj]!=0)
			{
				parsetable[nt][follow[nt][followj]-100]=r;
				followj++;
			}
		}
		
		if(isNT(nextsym))
		{
			firstj=0;
			//first[nextsym][firstj] is a T
			while(first[nextsym][firstj]!=0)
			{
				if(first[nextsym][firstj]==139)
					flag=1;
				else
				{
					parsetable[nt][first[nextsym][firstj]-100]=r;
				}
				firstj++;
			}
			if(flag==1)
			{
				followj=0;
				//follow[nextsym][followj] is a T
				while(follow[nextsym][followj]!=0)
				{
					parsetable[nt][follow[nextsym][followj]-100]=r;
					followj++;
				}
			}
		}
				
	}
}*/



void call1(int **grammar, int** parsetable, int** first, int** follow, int rj, int nt, int r)
{
	int nextsym=grammar[r][rj];//first symbol in RHS of production rule
		if(isT(nextsym) && !isE(nextsym))
		{
			parsetable[nt][nextsym-100]=r;
		}
		
		if(isE(nextsym))
		{
			int followj=0;
			//follow[nt][followj] is a T
			while(follow[nt][followj]!=0)
			{
				parsetable[nt][follow[nt][followj]-100]=r;
				followj++;
			}
		}
		
		if(isNT(nextsym))
		{
			int firstj=0;
			int flag=0;
			//first[nextsym][firstj] is a T
			while(first[nextsym][firstj]!=0)
			{
				if(first[nextsym][firstj]==139)
					flag=1;
				else
				{
					parsetable[nt][first[nextsym][firstj]-100]=r;
				}
				firstj++;
			}
			if(flag==1)
			{
				rj++;
				call1(grammar, parsetable, first, follow, rj, nt, r);
			}
		}	
}

void createParseTable1(int **grammar, int** parsetable, int** first, int** follow)
{
	int nt,rj; 
	for(int r=0; r<TOTAL_RULES; r++)
	{
		nt=grammar[r][0];//LHS of production rule
		rj=1;
		
		call1(grammar, parsetable, first, follow, rj, nt, r);
		
	}
}


//for token to tokenNo
int stringtonum(char* c,struct terminal **thash)
{
	char k[10];
	mystrcpy(k, 10, c);
	int index1;
	index1=(int)k[0]+(int)k[1]*2+(int)k[2]*3;
	index1=index1%THASH;
	if(strcmp(thash[index1][0].name,k)==0)
	{
		return thash[index1][0].n;
	}
	else
	{
		return thash[index1][1].n;
	}
}


//findSuitableNode in parse tree to where we have to add next rule
struct tnode* findSuitableNode(struct tnode* trav, int* flag)
{
	if(isNT(trav->val) && trav->child[0]==NULL && *flag==0)
	{
		*flag=1;
		return trav;
	}
	if(isNT(trav->val))
	{
		for(int c=0; c<15; c++)
		{
			if(trav->child[c]!=NULL && isNT(trav->child[c]->val) && *flag==0)
			{
				trav=findSuitableNode(trav->child[c], flag);
			}
			if(trav->child[c]!=NULL && isT(trav->child[c]->val) && *flag==0)
			{
				continue;
			}
			if(trav->child[c]==NULL && *flag==0)
			{
				return trav->parent;
			}
		}
	}
	return trav;
}

/*struct tnode* findNodeToCopyDetails(struct tnode* trav1, int globalcount, int *localcount, int* flag1)
{
	if(isT(trav1->val) && *localcount==globalcount && *flag1==0)
	{
		*flag1=1;
		return trav1;
	}
	if(isNT(trav1->val))
	{
		for(int c=0; c<15; c++)
		{
			if(trav1->child[c]!=NULL && isNT(trav1->child[c]->val) && *flag1==0)
			{
				trav1=findNodeToCopyDetails(trav1->child[c],globalcount,localcount, flag1);
			}
			if(trav1->child[c]!=NULL && isT(trav1->child[c]->val) && *flag1==0)
			{
				if(*localcount==globalcount && *flag1==0)
				{
					*flag1=1;
					return trav1->child[c];
				}
				else
				{
					*localcount=*localcount+1;
				}
			}
			if(trav1->child[c]==NULL && *flag1==0)
			{
				return trav1->parent;
			}
		}
	}
	return trav1;
}*/

//find Node in parse tree where we have to Copy Details of the next token received by getNextToken
struct tnode* findNodeToCopyDetails12(struct tnode* trav1, int globalcount, int *localcount, int* flag1)
{
	if(*flag1==1)
		return trav1;
	for(int c=0; c<15; c++)
	{
		if(trav1->child[c]!=NULL && *flag1==0)
		{
			trav1=findNodeToCopyDetails12(trav1->child[c],globalcount,localcount,flag1);
			if(*flag1==1)
				return trav1;
		}
	}
	
	
	if(isT(trav1->val) && !isE(trav1->val))
	{
		if(globalcount==*localcount && *flag1==0)
		{
			*flag1=1;
			return trav1;
		}
		if(globalcount!=*localcount && *flag1==0)
		{
			*localcount=*localcount+1;
			return trav1->parent;	
		}	
	}
	
	return trav1->parent;
}

char* isLeaf(int k)
{
	if(isT(k))
		return "yes";
	else
		return "no";
}

bool inFollow(int** follow, int nt, int t)
{
	for(int f1=0; f1<40; f1++)
	{
		if(follow[nt][f1]==t)
			return true;
	}
	return false;
}


//parse source code- make stack and parse tree
void parseInputSourceCode(int** grammar, int **parsetable, struct mystack* stack, struct terminal **thash, FILE* testcasefp, char* buffer, struct tnode* parsetree, int** follow ,char*** hashArray, char** store1)
{
	int flagcorrect=0;
	struct tnode* trav;
	struct tnode* trav1;
	int ti,tj,ri,rj,localcount;
	struct tokenInfo t1=getNextToken(testcasefp,buffer, hashArray);
	//HERE
	while(strcmp(t1.tokenName,"")==0){
		t1=getNextToken(testcasefp,buffer, hashArray);
	}
	char token[10];
	mystrcpy(token,10,t1.tokenName);
	int tokenNo=stringtonum(token, thash);
	char lexeme[31];
	mystrcpy(lexeme,31,t1.lexeme);
	int line=t1.line;
	tj=tokenNo-100;
	
	int globalcount=0;
	
	while(tokenNo!=140)
	{
		if(isNT(top(stack)))
		{
			ti=top(stack);
			ri=parsetable[ti][tj];
			if(ri!=ERROR)
			{
				//fill stack in reverse
				rj=1;
				while(grammar[ri][rj]!=0)
				{
					rj++;
				}
				rj--;
				pop(stack);
				while(rj!=0)
				{
					if(grammar[ri][rj]!=139)
					{
						push(stack, grammar[ri][rj]);
					}
					rj--;
				}
				
				//add nodes to parse tree
				rj=1;
				trav=parsetree;//dont change 'parsetree' node ever... it contains first NT, i.e, <mainFunction>
				int flag=0;
				struct tnode* res=trav;
				res=findSuitableNode(trav,&flag);
				
				while(grammar[ri][rj]!=0)
				{
					struct tnode* temp=(struct tnode*)malloc(sizeof(struct tnode));
					temp->val=grammar[ri][rj];
					temp->parent=res;
					strcpy(temp->lexeme,"---");
					temp->line=0;
					temp->num=-1;
					temp->rnum=-1;
					for(int q=0; q<15; q++)
					{
						temp->child[q]=NULL;
					}
					res->child[rj-1]=temp;
					rj++;
					
				}
				
				continue; //dont get next token
			}
			else
			{
				//int count3=0;
				//error entry in parse table
				flagcorrect=1;
				printf("SYNTAX ERROR: Line %d: The token %s for lexeme %s unexpected. \n", line, token, lexeme);
				//get next token until it is not in follow set of NT present at top of stack
				while(!inFollow(follow, top(stack), tokenNo) )//&& count3<200)
				{
					t1=getNextToken(testcasefp,buffer, hashArray);
					//HERE
					while(strcmp(t1.tokenName,"")==0)
					{
						t1=getNextToken(testcasefp,buffer, hashArray);
					}
					mystrcpy(token,10,t1.tokenName);
					tokenNo=stringtonum(token, thash);
					mystrcpy(lexeme,31,t1.lexeme);
					line=t1.line;
					tj=tokenNo-100;
					
					//count3++;
				}
				//if found in follow set, pop stack
				pop(stack);
				continue;
			}
		}
		
		if(isT(top(stack)))
		{
			if(top(stack)==tokenNo)
			{
				pop(stack);
				
				//find Node To Copy Details
				trav1=parsetree;//dont change parsetree node ever... it contains first NT, i.e, <mainFunction>
				localcount=0;
				int flag1=0;
				struct tnode* res1=trav1;
				res1=findNodeToCopyDetails12(trav1,globalcount, &localcount, &flag1);
				
				//copy those details to found node
				
				if(res1->val==104)
					res1->num=atoi(lexeme);
				if(res1->val==105)
					res1->rnum=atof(lexeme);
				mystrcpy(res1->lexeme,10,lexeme);
				res1->line=line;
				
				globalcount++;
			}
			else
			{
				
				//top of stack is terminal and it does not matches with next token
				flagcorrect=1;
				printf("SYNTAX ERROR: Line %d: The token %s for lexeme %s does not match. The expected token here is %s\n", line, token, lexeme, numtostring(store1, top(stack)));
				//pop stack and get next token simultaneously until both Terminals matches
				
				//pop stack
				pop(stack);
				
				//get next token
				t1=getNextToken(testcasefp,buffer, hashArray);
				//HERE
				while(strcmp(t1.tokenName,"")==0)
				{
					t1=getNextToken(testcasefp,buffer, hashArray);
				}
				mystrcpy(token,10,t1.tokenName);
				tokenNo=stringtonum(token, thash);
				mystrcpy(lexeme,31,t1.lexeme);
				line=t1.line;
				tj=tokenNo-100;					
				
				continue;
			}
		}
		if(top(stack)==140)
		{
			//stack becomes empty
			//printf("SYNTAX ERROR: Line %d: Stack empty\n", line);
			//flagcorrect=1;
		}
		
		//keep at end of while loop
		t1=getNextToken(testcasefp,buffer, hashArray);
		//HERE
		while(strcmp(t1.tokenName,"")==0)
		{
			t1=getNextToken(testcasefp,buffer, hashArray);
		}
		mystrcpy(token,10,t1.tokenName);
		tokenNo=stringtonum(token, thash);
		mystrcpy(lexeme,31,t1.lexeme);
		line=t1.line;
		tj=tokenNo-100;
	}
	
	if(tokenNo==140 && top(stack)!=140)
	{
		//stack not empty
		//printf("SYNTAX ERROR: Line %d: End of file but stack is not empty\n", line);
		//flagcorrect=1;
	}
	
	if(tokenNo==140 && top(stack)==140 && flagcorrect==0)
	{
		printf("Input source code is syntactically correct...\n");
	}
}


//print parse tree in INORDER
void printParseTree(struct tnode* trav2, FILE* parsetreefp, char** store1)
{
	if(trav2==NULL)
		return;
	//print first child
	printParseTree(trav2->child[0], parsetreefp, store1);
	
	
	//print node info
	if(trav2->val==1)
		fprintf(parsetreefp, "LexemeCurrentNode=%s	|	LineNo=%d	|	Token/NodeSymbol=%s	|	ParentNodeSymbol=ROOT	|	isLeafNode=no\n", trav2->lexeme, trav2->line, numtostring(store1, trav2->val));
	else
	{
		if(trav2->num!=-1)
			fprintf(parsetreefp, "LexemeCurrentNode=%s	|	LineNo=%d	|	Token/NodeSymbol=%s	|	Value=%d	|	ParentNodeSymbol=%s	|	 isLeafNode=%s\n",trav2->lexeme, trav2->line, numtostring(store1, trav2->val), trav2->num, numtostring(store1, trav2->parent->val), isLeaf(trav2->val));
		else if(trav2->rnum!=-1)
			fprintf(parsetreefp, "LexemeCurrentNode=%s	|	LineNo=%d	|	Token/NodeSymbol=%s	|	Value=%.2f	|	parentNodeSymbol=%s	|	isLeafNode=%s\n",trav2->lexeme, trav2->line, numtostring(store1, trav2->val), trav2->rnum, numtostring(store1, trav2->parent->val), isLeaf(trav2->val));
		else
			fprintf(parsetreefp, "LexemeCurrentNode=%s	|	LineNo=%d	|	Token/NodeSymbol=%s	|	ParentNodeSymbol=%s	|	isLeafNode=%s\n",trav2->lexeme, trav2->line, numtostring(store1, trav2->val), numtostring(store1, trav2->parent->val), isLeaf(trav2->val));
	}
	
	//print remaining child
	for(int c=1; c<15; c++)
	{
		printParseTree(trav2->child[c], parsetreefp, store1);
	}
	
}

