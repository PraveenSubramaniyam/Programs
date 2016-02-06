 
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>  // for uintptr_t type, needed for boolean
                       // operations on pointers
 
 
/* Aligning pointer to  nbyte memory boundary
   padding = n - (offset & ( -1)) = -offset & (n-1)
   aligned offset = (offset + n-1) & ~(n-1)
 */
void * mallocaligned(size_t size, int align) {
    if (align < sizeof(int)) 
        align = sizeof(int);
    /* allocate pointer with space to store original address at top and
     * to move to align-byte boundary */
    void *ptr1 = malloc(size + align + align - 1);
    printf("%d bytes of memory allocated at %p\n", size+2*align-1, ptr1);
    /* align pointer to align-byte boundary */
    void *ptr2 = (void *)(((uintptr_t)ptr1 + align - 1) & ~(align-1));
    /* store there the original address from malloc */
    *(unsigned int *)ptr2 = (unsigned int)ptr1;
    /* move pointer to next align-byte boundary */
    ptr2 = ptr2 + align;
    printf("aligned memory at %p\n", ptr2);
 
    return ptr2;
}
 
void freealigned(void *ptr, int align) {
    /* move pointer back align bytes */
    ptr = (void *)((uintptr_t)ptr - align);
    /* retreive from there the original malloced pointer */
    ptr = (void *)(*(unsigned int *)ptr);
    printf("free memory at address %p\n", ptr);
    /* free that pointer */
    free(ptr);
}
 
int main() {
    void *ptr = mallocaligned(1000, 64);
    printf("allocated pointer at %p", ptr);
    freealigned(ptr, 64);
    return 0;
}
