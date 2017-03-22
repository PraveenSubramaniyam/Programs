#include <stdio.h>
#include <string.h>

void strrev(char *str)
{
	int start = 0;
	int end = strlen(str) -1;
	char temp;
	while(start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}

void reverseWords(char *str)
{
	strrev(str);
	int i = 0;
	int j = 0;
	int strl = strlen(str);
	while (i <= strl)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{
			str[i] = '\0';
			strrev(str+j);
			if(i != strl - 1  )
				str[i] = ' ';
			j = i+1;
		}
		i++;
	}
}
void main()
{
	char str[]="hello world";
    printf("String: %s\n",str);
    reverseWords(str);
	printf("After Rev String: %s\n",str);
}
