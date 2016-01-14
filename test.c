/*
 * test.c
 *
 *  Created on: Nov 10, 2015
 *      Author: praveen
 */


#include <stdio.h>

int solution(int *a,int x,int d, int n)
{
  int i;
  int tmp[x];
  int jumplen = 0;
  int leafReached = 0;
  int loop = 1;

  memset(tmp,-1,sizeof(tmp));
  /*{1,3,1,4,5,2}*/
  /*{42,30,35,6,24,13,18}*/
  for (i = 0;i < n; i++)
  {
    /* to prevent second time loop for the same variable*/
    if(leafReached < a[i] && leafReached + d >= a[i] && tmp[a[i]] == -1)
    {
      leafReached = a[i];
      while(jumplen < d) {
        if(tmp[a[i]+loop] == -1 && a[i]+loop < x) {
          loop++;
          jumplen++;
        }
        else {
          leafReached = a[i]+loop;
          jumplen = 0;
          loop++;
          if(leafReached == x)
            return i;
        }
      }
      jumplen = 0;
      loop = 1;
    }
    tmp[a[i]] = i;
  }
  return -1;
}

void main()
{
  int a[6] = {1,3,1,4,5,2};
  printf("result: %d\n",solution(a,7,3,6));
}


