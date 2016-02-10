#include <stdio.h>
int  max(char  a,  char  b)
{
  if(a<b)
    return  b;
  else
    return  a;
}

void  memcpyUtilRev(void *dst,  void  *src,int  size)
{
  dst = dst+size;
  src = src+size;

  int  align  =  min((size_t)dst  %  8,  (size_t)src  %  8);
  if(align  >  0)
  {
    while(align--)
    {
      *((char*)dst)--  =  *((char*)src)--;
    }
    size  =  size  -  align;
  }

  while(size/8)
  {
    dst -=8;
    src -=8;
    *((double*)dst)++  =  *((double*)src)++;
    size  =  size  -  8;
  }

  while(size--)
  {
    *((char*)dst)--  =  *((char*)src)--;
  }
}

void  memcpyUtil(void  *dst,  void  *src,int  size)
{

  int  align  =  max((size_t)dst  %  8,  (size_t)src  %  8);
  if(align  >  0)
  {
    while(align--)
    {
      *((char*)dst)++  =  *((char*)src)++;
    }
    size  =  size  -  align;
  }

  while(size/8)
  {
    *((double*)dst)++  =  *((double*)src)++;
    size  =  size  -  8;
  }

  while(size--)
  {
    *((char*)dst)++  =  *((char*)src)++;
  }
}

int overlap(void *dst, void *src, int size)
{
  return (src<=dst && src+size>dst);
}

void  memcpy(void  *dst,  void  *src,int  size)
{
  /*If the Source and destinations doesn't overlap go with
   * copying from small address to large address*/
  if(dst  <  src || !overlap(dst,src,size))
  {
    memcpyUtil(dst,src,size);
  }
  else
  {
    /*If the Source and destinations overlap go with
     * copying from large address to small address*/
    memcpyUtilRev(dst,src,size);
  }
}


