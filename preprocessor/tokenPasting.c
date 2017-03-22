#include <stdio.h>

#define token(x) \
	printf("usage of tokenPasting.. Pasted var %s",##x)


void main()
{
	char *hhello = "hello";
	token(hello);
}
