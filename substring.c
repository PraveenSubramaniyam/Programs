#include <stdio.h>
#include <string.h>

void main()
{
	char str[] = "hai hello how hello are you";
	char substring[] = "hello";
	char *ptr;
	char *ptr2 = str;
	while((ptr = strstr(ptr2,substring))!= NULL)
	{
     	*ptr = '\0';
		printf("%spraveen",ptr2);
		ptr2 = ptr + strlen(substring);
	}
	printf("%s\n",ptr2);
}
