#include <stdio.h>
#include <stdlib.h>

char operator[15] = "+-*/(){}<>&=[],";
void preprocessor(char *buffer, int size);
int main(int argc, char *argv[])
{
	int i = 0, j, ch, dist;
	FILE *fp1, *fp;
	char *buffer;


	char keyword[32][12] = {"auto", "break", "case", "char", "const", "continue", "default", "do", 
		"double", "else", "enum", "extern", "float", "for", " goto", "if",
		"int", "long","register", "return", "short", "signed", "sizeof", "static", 
		"struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

	//	char operator[15] = "+-*/(){}<>&=[],";

	char format_specifier[8][3] = {"%d", "%f", "%s", "%c", "%ld", "%x", "%o", "%i"};

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
			//		if(buffer[0] == '#')
			//		{
			preprocessor(buffer, dist);
			//		}


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
		if(buffer[i] == '<')
		{
			printf("Header file : %s\n", &buffer[i]);
			return 0;
		}
	}
	//Checking for alphabet
	if(isalpha(buffer[i]) == 0)
	{

	}


}











