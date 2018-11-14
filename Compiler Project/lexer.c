//Name: Alekh Maheshwari
//ID: 2015A7PS0097P

#include "lexer.h"

int i; //definition here

//for hashing keywords
void hash(char k[], char ***hashArray)
{
	int index1;
	index1=(int)k[0]+(int)k[1]*3;
	index1=index1%HASH_SIZE;
	if(strcmp(hashArray[index1][0],"")==0)
	{
		strcpy(hashArray[index1][0],k);
	}
	else
	{
		strcpy(hashArray[index1][1],k);
	}
}

void addInHash(char ***hashArray)
{
	for(int q=0;q<HASH_SIZE; q++)
	{
		for(int j=0; j<2;j++)
		{
			strcpy(hashArray[q][j],"");
		}
	}
	hash("end", hashArray);
	hash("int", hashArray);
	hash("real", hashArray);
	hash("string", hashArray);
	hash("matrix", hashArray);
	hash("_main", hashArray);
	hash("if", hashArray);
	hash("else", hashArray);
	hash("endif", hashArray);
	hash("read", hashArray);
	hash("print", hashArray);
	hash("function", hashArray);
}

bool isKeyword(char t[], char ***hashArray)
{
	int index1;
	index1=(int)t[0]+(int)t[1]*3;
	index1=index1%HASH_SIZE;
	if((strcmp(hashArray[index1][0],t)==0)||(strcmp(hashArray[index1][1],t)==0))
		return true;
	else
		return false;
}

FILE* getStream(FILE *fp, char* buffer)
{
	//for(int z=0; z<BUF_SIZE; z++)
	//{buffer[z]='\0';}
	int n=fread(buffer, sizeof(char), BUF_SIZE-1, fp);
	buffer[n]='&';//End of buffer
	if(n<BUF_SIZE-1)
	{
		buffer[n]='$';//end of file
	}
	return fp;
}


//To refill buffer.
void bufferEndCheck(FILE *fp, char* buffer)
{
	if(buffer[i]=='&')
	{
		i=0;
		fp=getStream(fp, buffer);
	}
}


void removeWhiteSpace(FILE *fp, char* buffer)
{
	for(int q=0; q<3; q++)
	{
	bufferEndCheck(fp, buffer);
	while(buffer[i]=='\0')
	{i++;
	bufferEndCheck(fp, buffer);}
	while(buffer[i]=='\r')
	{i++; 
	bufferEndCheck(fp, buffer);}
	while(buffer[i]=='\n')
	{i++; 
	bufferEndCheck(fp, buffer);
	line++;}
	while(buffer[i]==' ')
	{i++;
	bufferEndCheck(fp, buffer);}
	while(buffer[i]=='\t')
	{i++;
	bufferEndCheck(fp, buffer);}
	}
}


struct tokenInfo makeToken(struct tokenInfo token, char tokenName[], char lexeme[], int line)
{
	strcpy(token.tokenName, tokenName);
	strcpy(token.lexeme, lexeme);
	token.line=line;
	return token;
}


struct tokenInfo getNextToken(FILE *fp, char* buffer, char*** hashArray)
{
	//initializations
	struct tokenInfo token;
	
	//Remove white spaces
	removeWhiteSpace(fp, buffer);
	
	//initialize buffer
	bufferEndCheck(fp, buffer);
	
	
	if(buffer[i]=='#')
	{
		while(buffer[i]!='\n')
		{
			i++;
			bufferEndCheck(fp, buffer);
			if(buffer[i]=='&')
				bufferEndCheck(fp, buffer);
		}
		i++;
		bufferEndCheck(fp, buffer);
		line++;
		return makeToken(token, "", "", line-1);
	}
	
	
	if(buffer[i]=='[')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "SQO", "[", line);
	}
	if(buffer[i]==']')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "SQC", "]", line);
	}
	if(buffer[i]=='(')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "OP", "(", line);
	}
	if(buffer[i]==')')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "CL", ")", line);
	}
	if(buffer[i]==';')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "SEMICOLON", ";", line);
	}
	if(buffer[i]==',')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "COMMA", ",", line);
	}
	if(buffer[i]=='+')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "PLUS", "+", line);
	}
	if(buffer[i]=='-')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "MINUS", "-", line);
	}
	if(buffer[i]=='*')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "MUL", "*", line);
	}
	if(buffer[i]=='/')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "DIV", "/", line);
	}
	if(buffer[i]=='@')
	{
		i++;
		bufferEndCheck(fp, buffer);
		return makeToken(token, "SIZE", "@", line);
	}
	
	//starts with .(logical operators)
	if(buffer[i]=='.')
	{
		i++;
		bufferEndCheck(fp, buffer);
		if(buffer[i]=='a')
		{
			i++;
			bufferEndCheck(fp, buffer);
			if(buffer[i]=='n')
			{
				i++;
				bufferEndCheck(fp, buffer);
				if(buffer[i]=='d')
				{
					i++;
					bufferEndCheck(fp, buffer);
					if(buffer[i]=='.')
					{
						i++;
						bufferEndCheck(fp, buffer);
						return makeToken(token, "AND", ".and.", line);
					}
					else
					{// !!!REPORT ERROR !!!
						printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); 
					}
				}
				else
				{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
			}
			else
			{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
		}
		else if(buffer[i]=='o')
		{
			i++;
			bufferEndCheck(fp, buffer);
			if(buffer[i]=='r')
			{
				i++;
				bufferEndCheck(fp, buffer);
				if(buffer[i]=='.')
				{
					i++;
					bufferEndCheck(fp, buffer);
					return makeToken(token, "OR", ".or.", line);
				}
				else
				{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
			}
			else
			{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
		}
		else if(buffer[i]=='n')
		{
			i++;
			bufferEndCheck(fp, buffer);
			if(buffer[i]=='o')
			{
				i++;
				bufferEndCheck(fp, buffer);
				if(buffer[i]=='t')
				{
					i++;
					bufferEndCheck(fp, buffer);
					if(buffer[i]=='.')
					{
						i++;
						bufferEndCheck(fp, buffer);
						return makeToken(token, "NOT", ".not.", line);
					}
					else
					{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
				}
				else
				{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
			}
			else
			{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
		}
		else
		{printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); }
	}
	
	//starts with =
	if(buffer[i]=='=')
	{
		i++;
		bufferEndCheck(fp, buffer);
		if(buffer[i]=='=')
		{
			i++;
			return makeToken(token, "EQ", "==", line);
		}
		else if(buffer[i]=='/')
		{
			i++;
			bufferEndCheck(fp, buffer);
			if(buffer[i]=='=')
			{
				i++;
				bufferEndCheck(fp, buffer);
				return makeToken(token, "NE", "=/=", line);
			}
			else
			{
				printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
				return makeToken(token, "", "", line); 
			}
		}
		else
		{
			return makeToken(token, "ASSIGNOP", "=", line);
		}
	}
	
	//starts with >
	if(buffer[i]=='>')
	{
		i++;
		bufferEndCheck(fp, buffer);
		if(buffer[i]=='=')
		{
			i++;
			bufferEndCheck(fp, buffer);
			return makeToken(token, "GE", ">=", line);
		}
		else
		{
			return makeToken(token, "GT", ">", line);
		}
	}
	
	//starts with <
	if(buffer[i]=='<')
	{
		i++;
		bufferEndCheck(fp, buffer);
		if(buffer[i]=='=')
		{
			i++;
			bufferEndCheck(fp, buffer);
			return makeToken(token, "LE", "<=", line);
		}
		else
		{
			return makeToken(token, "LT", "<", line);
		}
	}
	
	//string
	if(buffer[i]=='"')
	{
		i++;
		bufferEndCheck(fp, buffer);
		char temp[21]="";
		int k=0;
		if(((int)buffer[i]<97 || (int)buffer[i]>122) && buffer[i]!=' ')
		{
			printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
			return makeToken(token, "", "", line);
		}
		else
		{
			temp[k]=buffer[i];
			k++;
			i++;
			bufferEndCheck(fp, buffer);		
		}
		for(int j=0; j<17; j++)
		{
			if(buffer[i]=='"')
			{
				i++;
				bufferEndCheck(fp, buffer);
				return makeToken(token, "STR", temp, line); 
			}
			else if(((int)buffer[i]>=97 && (int)buffer[i]<=122)|| buffer[i]==' ')
			{
				temp[k]=buffer[i];
				k++;
				i++;
				bufferEndCheck(fp, buffer);
			}
			else
			{
				printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
				return makeToken(token, "", "", line);
			}
		}
		//length of string may be greater than 20
		printf("LEXICAL ERROR: Line %d: Length of string longer than 20 characters.\n",line);
		return makeToken(token, "", "", line);	
	}
	
	//funid
	if(buffer[i]=='_')
	{
		i++;
		bufferEndCheck(fp, buffer);
		char temp[31]="";
		int k=1;
		temp[0]='_';
		if((buffer[i]>=65 && buffer[i]<=90)||(buffer[i]>=97 && buffer[i]<=122))
		{
			temp[k]=buffer[i];
			k++;
			i++;
			bufferEndCheck(fp, buffer);
		}
		else
		{
			printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
			return makeToken(token, "", "", line);
		}
		for(int j=0; j<29; j++)
		{
			if((buffer[i]>=65 && buffer[i]<=90)||(buffer[i]>=97 && buffer[i]<=122)||(buffer[i]>=48 && buffer[i]<=57))
			{
				temp[k]=buffer[i];
				k++;
				i++;
				bufferEndCheck(fp, buffer);
			}
			else
			{
				if(strcmp(temp,"_main")==0)
				{
					
					return makeToken(token, "MAIN", temp, line);
				}	
				return makeToken(token, "FUNID", temp, line);
			}
		}
		printf("LEXICAL ERROR: Line %d: Function name too long.\n",line);
		return makeToken(token, "", "", line);
	}
	
	//num and rnum
	if(buffer[i]>=48 && buffer[i]<=57)
	{
		char temp[31]="";
		int k=0;
		temp[k]=buffer[i];
		i++;
		k++;
		bufferEndCheck(fp, buffer);
		for(int j=0; j<29; j++)
		{
			if(buffer[i]>=48 && buffer[i]<=57)
			{
				temp[k]=buffer[i];
				i++;
				k++;
				bufferEndCheck(fp, buffer);
			}
			else if(buffer[i]=='.')
			{
				temp[k]=buffer[i];
				k++;
				i++;
				bufferEndCheck(fp, buffer);
				if(buffer[i]>=48 && buffer[i]<=57)
				{
					temp[k]=buffer[i];
					k++;
					i++;
					bufferEndCheck(fp, buffer);
					if(buffer[i]>=48 && buffer[i]<=57)
					{
						temp[k]=buffer[i];
						i++;
						bufferEndCheck(fp, buffer);
						return makeToken(token, "RNUM", temp, line);
					}
					else
					{
						printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
						return makeToken(token, "", "", line); 
					}
				}
				else
				{
					printf("LEXICAL ERROR: Line %d: Unrecognised pattern.\n",line);
					return makeToken(token, "", "", line); 
				}
			}
			else
			{
				return makeToken(token, "NUM", temp, line);
			}
		}
		printf("LEXICAL ERROR: Line %d: Number too big.\n",line);
		return makeToken(token, "", "", line);
	}
	
	//id
	
	if((buffer[i]>=65 && buffer[i]<=90)||(buffer[i]>=97 && buffer[i]<=122))
	{
		char temp[21]="";
		int k=0;
		temp[k]=buffer[i];
		k++;
		i++;
		bufferEndCheck(fp, buffer);
		for(int j=0; j<19; j++)
		{
			if((buffer[i]>=65 && buffer[i]<=90)||(buffer[i]>=97 && buffer[i]<=122))
			{
				temp[k]=buffer[i];
				k++;
				i++;
				bufferEndCheck(fp, buffer);
			}
			else if(buffer[i]>=48 && buffer[i]<=57)
			{
				temp[k]=buffer[i];
				i++;
				bufferEndCheck(fp, buffer);
				return makeToken(token, "ID", temp, line);
			}
			else
			{
				if(isKeyword(temp, hashArray)==true)
				{
					int a=0;
   					char upper_temp[11]="";
   					while(temp[a]) 
   					{
     	 				upper_temp[a]=(char)toupper(temp[a]);
      					a++;
   					}
					return makeToken(token, upper_temp, temp, line);
				}
				else
				{
					return makeToken(token, "ID", temp, line);
				}
			}
		}
		printf("LEXICAL ERROR: Line %d: Variable name must not be greater than 20 characters.\n",line);
		removeWhiteSpace(fp, buffer);
		return makeToken(token, "", "", line);
	}
	
	//End marker returned as token
	if(buffer[i]=='$')
	{
		return makeToken(token,"$","$",line);
	}
	
	//make a default case
	printf("LEXICAL ERROR: Line %d: Unknown Symbol %c\n",line,buffer[i]);
	return makeToken(token, "", "", line);
}


void removeComments(char *testcaseFile)
{
	FILE* commentrem=fopen(testcaseFile,"r+");
	char ch;
	ch=fgetc(commentrem);
	while(!feof(commentrem))
	{
		if(ch=='#')
		{
			ch=fgetc(commentrem);
			while(ch!='\n')
			{
				ch=fgetc(commentrem);
			}
		}
		else
		{
			printf("%c",ch);
		}
		ch=fgetc(commentrem);
	}
	fclose(commentrem);
}

