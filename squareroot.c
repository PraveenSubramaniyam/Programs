#include <stdio.h>
#include <math.h>


int isSquare(int n)
{
    int temp;
    temp = sqrt(n);

    if(temp*temp == n)
    	return 1;
    else
    	return 0;
}


int min(int a, int b, int c)
{
  if(a<b && a<c)
    return a;
  else if (b<a && b < c)
    return b;
  else
	  return c;
}

int computeValue(int x, int y, int z)
{
	if((isSquare(x+y) == 1) && (isSquare(x-y) == 1) && (isSquare(x+z) == 1) && (isSquare(x-z) == 1) && (isSquare(y+z) == 1)
			&& (isSquare(y-z) == 1))
		return x+y+z;
	else
		return min(computeValue(x+1,y+1,z+1), computeValue(x+1,y+1,z), computeValue(x+1,y,z));
}

void main()
{
	//printf("Minimum Value is: %d\n",computeValue(3,2,1));
	long x, y, z;
	int sol=0;
	for (x=434657;!sol;x++)
	{
		printf("%ld\n",x);
		for (y=x-1;y>1;y--)
		{
			for (z=y-1;z>1;z--)
			{
				if((isSquare(x+y) == 1) && (isSquare(x-y) == 1) && (isSquare(x+z) == 1) && (isSquare(x-z) == 1) && (isSquare(y+z) == 1)
							&& (isSquare(y-z) == 1))
				{
					sol =1 ;
					break;
				}
			}
			if(sol==1)
				break;
		}
	}
}
