#include<stdio.h>
#include <string.h>

void main()
{
	char str[]="a0Ba";
	int i, maxLen = 0, initialPos = 0, lastPos = 0 ;
	int upperFound = 0;
	for (i=0;i<strlen(str);i++)
	{
		if(!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
		{
			if(((lastPos - initialPos + 1) > maxLen) && upperFound)
				maxLen = lastPos-initialPos+1;
			upperFound = 0;
			initialPos = i+1;
		}
		else
		{
		  if(str[i] >= 'A' && str[i] <= 'Z')
			  upperFound = 1;
		  lastPos = i;
		}
	}

	if(((lastPos - initialPos+1) > maxLen) && upperFound)
		maxLen = lastPos-initialPos+1;
	printf("MaxLen: %d\n",maxLen);

}
