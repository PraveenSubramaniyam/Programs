#if  0
unsigned  long  long  *  dst,  *src;
//  overlapping  -  dst  should  contain  the  data.-  All  src  should  be  copied
//  ALignment  issues
//  size  alignment
memcpy(void  *dst,  void  *src,int  size)
{
    while(src%8  !=  0  )
    {
        dst++  =  *((src)++;
    }

    while(size/8)
    {
        *((double*)dst)++  =  *((double*)src)++;        //  sigbus  src  =  0x803,  dst  =  0x100000,  size  =  15          ---  src  -  char,  dest  int
        size  =  size  -  8;
    }

    while(size--)
    {
        *((char*))dst++  =  *((char*)src)++;
    }
}
#endif

if ((src | dst) & 7) {
    if ((src ^ dst) & 7 || size < 8)
      src = size;
    else
    src = 8 - (src & 7);
    size -= 7;
    TLOOP1(*dst++ = *src++);
}
