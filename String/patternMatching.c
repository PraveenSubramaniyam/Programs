#include <stdio.h>
#include <string.h>


void patternNaive(char *str, char *sub)
{
	int k,j ;
	for (int i = 0; i<strlen(str);i++)
	{
		k = i;
		for (j = 0 ; j < strlen(sub); j++)
		{
			if (str[k++] != sub[j] )
				break;
		}
		if ( j == strlen(sub))
			printf("Found pattern at index: %d\n",i);
	}
}


void patternKMP (char *str, char *sub)
{

}

void main()
{
	char str[]= "AABAACAADAABAABA";
	char sub[] = "AABA";
	patternNaive (str, sub);
}
