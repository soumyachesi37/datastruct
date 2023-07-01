#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEN 100

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

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
    
    mergeSort(array,0,len-1);
    
    printf("\n/The Sorted Array/\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",*(array+i));
    }        
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], M[n2];
    int i = 0, j = 0, k = left;
    
    for (int i = 0; i < n1; i++)
      L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
      M[j] = arr[mid + 1 + j];
    
    while (i < n1 && j < n2) 
    {
        if (L[i] <= M[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }   
    while (j < n2) 
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}