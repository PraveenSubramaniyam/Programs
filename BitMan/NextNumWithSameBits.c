#include <stdio.h>


int nextNum(int num)
{
    int rightMostSetBit = num & -(signed)num;
    int rightMostBitplusnum = num + rightMostSetBit;
    int rightmostPattern = num ^ rightMostBitplusnum;
    rightmostPattern = rightmostPattern / rightMostSetBit;
    rightmostPattern >>= 2;
    return rightMostBitplusnum | rightmostPattern;
}


void main()
{
  int num = 156;
  printf("Num: %d, NextNum:%d\n",num,nextNum(num));
}
