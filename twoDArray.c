#include <stdio.h>
#include <stdlib.h>


void main()
{
	int **arr;
	int i,j;
	/*
	 * Create array of size 3 * 4
	 */
	arr = malloc(sizeof(int*)*3);
	for (i = 0; i < 3; i++)
	{
		arr[i] = malloc(sizeof(int)*4);
	}

	for (i = 0; i < 3; i++)
	{
		for (j=0;j<4;j++)
		{
			arr[i][j] = (i+1) * (j+1);
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j=0;j<4;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}
