#include <stdio.h>

void mymemcpy(void *src,void *dst,int nbits)
{
  while(nbits/8 > 0)
  {
    *dst++ = *src++;
    nbits-=8;
  }

  *dst = (*dst & ~0 << 8-nbits )| (*src & ~0>>8-nbits);
}

int main()
{

    printf("%d\n", my_sizeof());
    return 0;
}
