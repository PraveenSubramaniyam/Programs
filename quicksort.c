#include <stdio.h>


int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    int j = low;

    while (j<=(high-1))
    {
    	if(arr[j] <= pivot)
    	{
    		i++;
    		arr[i] = arr[i] ^ arr[j];
    		arr[j] = arr[i] ^ arr[j];
    		arr[i] = arr[i] ^ arr[j];
    	}
    	j++;
    }
    arr[i] = arr[i] ^ arr[high];
    arr[high] = arr[i] ^ arr[high];
    arr[i] = arr[i] ^ arr[high];
    return i+1;
}


void quicksort(int *arr, int low, int high)
{
	if(low<high)
	{
        int pivot = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1, high);
	}
}



void main()
{
    int arr[] = {2,5,1,4,3,7,6};
    int high = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,high-1);

}
