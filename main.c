#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char operator[15] = "+-*/(){}<>&=[],";
char keyword[32][12] = {"auto", "break", "case", "char", "const", "continue", "default", "do", 
		"double", "else", "enum", "extern", "float", "for", " goto", "if",
		"int", "long","register", "return", "short", "signed", "sizeof", "static", 
		"struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
char format_specifier[8][3] = {"%d", "%f", "%s", "%c", "%ld", "%x", "%o", "%i"};

void preprocessor(char *buffer, int size);
int keyword_checking(char*buffer);
char* operator_checking(char*buffer);

int main(int argc, char *argv[])
{
	int i = 0, ch, dist;
	FILE *fp1, *fp;
	char *buffer;



	//	char operator[15] = "+-*/(){}<>&=[],";


	if (argc == 1)
	{
		printf("Insufficient Arguments..Provide a .c file\n");
		return -1;
	}

	fp = fopen(argv[1], "r");
	fp1 = fopen(argv[1], "r");

	while((ch=fgetc(fp1)) != EOF)
	{
		if (ch == '\n')
		{
			dist = ftell(fp1) - ftell(fp) - 1;

			buffer = malloc((dist) * sizeof(char));
			fseek(fp1, -(dist + 1), SEEK_CUR);
			fread(buffer, dist, 1, fp1);
			//Compare for preprocessor directives
					if(buffer[0] == '#')
					{
			preprocessor(buffer, dist);
					}
					else
					{
						printf("inside else");
					//	while (buffer[i] != " " || operator_checking(buffer[i]))
					while(i <= dist)
						{
							char *word = malloc(50 * sizeof(char));
							char *ch = '\0';
							int j = i;
							int k = 0;

						while (buffer[i] != ' ' && (ch = operator_checking(&buffer[i])))
							{ 
						printf("inside ");
								word[k++] = buffer[i++];
							//	j++;
							//	k++;
							}
						word[k] = '\0';

						if (isdigit(word[0]))
						{
							printf("constant : %s \n", word);
						}
						else
						{
							keyword_checking(word);
						}

						if (*ch != '\0')
						{
							printf("operator : %s \n",ch);
						}
						}

					}




					fseek(fp1,1,SEEK_CUR);
					//		printf("%s\n", buffer);
					fseek(fp, dist + 1, SEEK_CUR);


		}


	}
}


//Searching for preprocessor
void preprocessor(char *buffer, int size)
{
	int i = 0, j;
	//header file 
	if(buffer[i] == '#')
	{
		printf("Preprocessor directive : ");
		while(buffer[i] != ' ')
		{
			printf("%c", buffer[i]);
			i++;
		}
		printf("\n");
		i++;
		if(buffer[i] == '<' || buffer[i] == '"')
		{
			printf("Header file : %s\n", &buffer[i]);
		}
	}
}
int keyword_checking(char*buffer)
{
	for (int i = 0; i < 32; i++)
	{
		if (!(strcmp(buffer,&keyword[i][12])))
		{
			printf("Keyword : %s\n", buffer);
			return 0;
		}
	}
	printf("Identifier: %s\n", buffer);
	return -1;
}


char* operator_checking(char*buffer)
{
	for (int i = 0; i < 15; i++)
	{
		if (*buffer == operator[i])
		{
			return buffer;
		}
	}
	return 0;
}

