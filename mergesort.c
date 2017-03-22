#include <stdio.h>


void merge (int *arr,int l, int m, int r)
{
	int n1 = m-l+1;
	int n2 = r -m;
	int l1[n1], l2[n2];
	int i, j,k;

	for (i = 0;i<n1;i++)
		l1[i] = arr[l+i];

	for (j = 0;j < n2;j++)
		l2[j] = arr[m+1+j];

	i = 0;
	j = 0;
	k=l;

	while(i<n1 && j <n2)
	{
		if(l1[i] <= l2[j])
		{
			arr[k] = l1[i];
			i++;
		}
		else
		{
			arr[k] = l2[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = l1[i];
		k++;
		i++;
	}

	while (j < n2)
	{
		arr[k] = l2[j];
		k++;
		j++;
	}

}


void mergesort(int *arr, int l, int r)
{
	if (l<r)
	{
		int m = l+(r-l)/ 2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

void print(int *arr, int r)
{
	int i;
	for (i = 0; i<r;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
void main()
{
	int arr[] = {2,8,3,1,6,7,9};
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    print(arr,arrsize);
	mergesort(arr,0,arrsize-1);
	print(arr,sizeof(arr)/sizeof(arr[0]));
}
