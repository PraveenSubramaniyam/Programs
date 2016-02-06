#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) 
{
    int *iptr;
    char *cptr;
    bool h = true;
#if 0    
#if defined(__GNUC__)
# if defined(__i386__)
    /* Enable Alignment Checking on x86 */
    __asm__("pushf\norl $0x40000,(%esp)\npopf");
	printf("alignment checking in 32 bit");
# elif defined(__x86_64__) 
     /* Enable Alignment Checking on x86_64 */
    __asm__("pushf\norl $0x40000,(%rsp)\npopf");
    printf("elignment chcking in 64 bit");
# endif
#endif
#endif
    /* malloc() always provides aligned memory */
    cptr = malloc(sizeof(int) + 1);
    
    /* Increment the pointer by one, making it misaligned */
   // iptr = (int *) ++cptr;

    /* Dereference it as an int pointer, causing an unaligned access */
//    printf("%d",*iptr);
     printf("sizof bool:%d\n",sizeof(bool));
    /*
       Following accesses will also result in sigbus error.
       short *sptr;
       int    i;

       sptr = (short *)&i;
       // For all odd value increments, it will result in sigbus.
       sptr = (short *)(((char *)sptr) + 1);
       *sptr = 100;
    
    */

    return 0;
}
