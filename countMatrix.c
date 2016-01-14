#include <stdio.h>

void calculate(int n)
{
  double array[n][n];
  int i,j;
  memset(array,0,sizeof(array));
  for( i = 0;i<n;i++)
    array[i][0] = 1;
  for( i = 0;i<n;i++)
    array[0][i] =  1;
  
  for(i = 1;i<n;i++)
  {
    for(j=1;j<n;j++)
    {
      array[i][j] = array[i-1][j] + array[i][j-1];
    }
  }
  printf("%ld",array[n-1][n-1]);
}
void main()
{
  calculate(31);
}
