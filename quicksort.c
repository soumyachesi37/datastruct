#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEN 100

void quicksort(int*, int, int, int);
void swap(int*, int*);
int partition(int*, int, int);

int main()
{
    int array[MAXLEN], len, x, pos;
    printf("Enter number of elements ");
    scanf("%d",&len);
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        *(array+i) = rand()%100;
    }
    printf("/The Array/\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",*(array+i));
    }
    
    quicksort(array,0,len-1,len);
    
}




void quicksort(int arr[], int low, int high, int len)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1,len);
		quicksort(arr, pi + 1, high,len);
        printf("\n");
        for (int i = 0; i < len; i++)
        {
            printf("%d ",*(arr+i));
        }        
	}
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
