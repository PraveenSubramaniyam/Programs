#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int i = 0 ;
    int *returnArray = NULL;
    *returnSize = 0;
    while (i < numsSize)
    {
        if (nums[i] != nums[nums[i]-1])
        {
          int temp = nums[i] ;
          nums[i] =  nums[nums[i]-1];
          nums[temp-1] = temp;
        }

        else
            i++;
    }

    i = 0;
    while(i<numsSize)
    {
        if(nums[i] != i + 1)
        {
           ++(*returnSize);
           returnArray = (int *) realloc(returnArray, (*returnSize)*sizeof(int));
           returnArray[(*returnSize)-1] = nums[i];
        }
        i++;
    }
    return returnArray;

}

void main()
{
    int arr[] = {4,3,2,7,8,2,3,1};
    int retCount = 0;
    int *retArray = findDuplicates(arr,8,&retCount);
    printf("RetCount: %d\n",retCount);
}




