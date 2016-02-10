#include <stdio.h>

/* Write a program to swap odd and even bits of a 32-bit unsigned integer
 * with as few instructions as possible. (bit-0 and bit-1 are swapped,
 * bit-2 and bit-3 are swapped and so on)
 */

int main()
{
  int i = 5;
  i = (i & 0xAAAAAAAA)>>1 | (i & 0x55555555) << 1;
  printf("SwappedVal:%d\n",i);
}
