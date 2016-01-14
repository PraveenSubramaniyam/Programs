#include <stdio.h>
#include<stdlib.h>
#include <math.h>


float inter(int n, int amount_size,int *amount, int ucostSize, char **ucost)
{
  int lNum = 0,i;
  int gNum = 2001;
  int gIndex = -1;
  int lIndex = -1;
  float val,val1;
  float out;

  if(n < 2 || n > 2000)
  {
    printf("wrong n ");
    return 0;
  }



  for( i = 0; i < amount_size;i++)
  {
    if(amount[i] == n && atof(ucost[i]) > 0)
    {
      return atof(ucost[i]);
    }
    else
    {
      if(amount[i] > n && amount[i] < gNum && atof(ucost[i]) > 0)
      {
        gNum = amount[i];
        gIndex = i;
      }

      if(amount[i] < n && amount[i] > lNum && atof(ucost[i]) > 0)
      {
        lNum = amount[i];
        lIndex = i;
      }
    }
  }
  printf("lNum:%d\n",lNum);
  printf("gNum:%d\n",gNum);
  if(lNum == 0)
  {
    lIndex = 0;
    while(atof(ucost[lIndex]) <= 0 && lIndex < amount_size)
    {
      lIndex++;
    }
    if(lIndex == amount_size)
      return 0;

    gIndex = lIndex+1;
    if(gIndex == amount_size)
      return atof(ucost[lIndex]);

    while(atof(ucost[gIndex]) <= 0 && gIndex < amount_size)
      gIndex++;

    if(gIndex == amount_size)
      return atof(ucost[lIndex]);

    val = atof(ucost[gIndex]) - atof(ucost[lIndex]) ;
    val1 = (float)(amount[lIndex] - n )/ (amount[gIndex] - amount[lIndex]);
    out = atof(ucost[lIndex]) + val * val1;
    return roundf(out * 100) / 100;
  }
  else if(gIndex == -1)
  {
    gIndex = amount_size - 1;

    while(atof(ucost[gIndex]) <= 0 && gIndex >= 0)
    {
      gIndex--;
    }

    if(gIndex < 0)
      return 0;

     lIndex = gIndex -1;
     if(lIndex < 0)
       return atof(ucost[gIndex]);

     while(atof(ucost[lIndex]) <= 0 && lIndex >= 0)
       lIndex++;

    if(lIndex < 0 )
      return atof(ucost[gIndex]);

    lIndex = amount_size - 2;
    val = atof(ucost[lIndex]) - atof(ucost[gIndex]) ;
    val1 = (float)(n - amount[gIndex]) / (amount[gIndex] - amount[lIndex]);
    printf("val:%f, val1:%f\n",val,val1);
    out = atof(ucost[gIndex]) - val *val1;
    return roundf(out * 100) / 100;
  }

  else
  {
    val = (float)(n-amount[lIndex])/(amount[gIndex]-amount[lIndex]);
    return (atof(ucost[lIndex]) + (float) val* (float)(atof(ucost[gIndex]) - atof(ucost[lIndex])));
  }
}


void main()
{
  int n = 5;
  int i;
  char *ucost[5] = {"17","0","20","22","29.15"};
  int amt[5] = {10,25,50,100,500};
  for (i = 0;i<5;i++)
  {
    printf("%d:%s ",amt[i],ucost[i]);
  }
  printf("\n ");
  printf("last: %0.2f",inter(n,5,amt,5,ucost));
}
