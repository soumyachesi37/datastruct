#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEN 100

int binsearch(int*, int, int, int);
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
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
    qsort(array,len,sizeof(int),cmpfunc);
    printf("/The Array/\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",*(array+i));
    }
    
    printf("\nEnter element to get position ");
    scanf("%d",&x);

    pos = binsearch(array,0,len-1,x);
    
    if(pos>=0)
        printf("The element %d is present in cell %d",x,pos);
    else
        printf("The element is not present in the array");
    return 0;
} 
 
int binsearch(int* A, int low, int high, int key)
{
    int mid;
    if(key>=A[low]&&key<=A[high])
    {
        mid = high - low;
        if(key == A[mid])
        {
            return(mid);
        }
        else if(key > A[mid])
        {
            low = mid+1;
            binsearch(A,low,high,key);
        }
        else if(key < A[mid])
        {
            high = mid-1;
            binsearch(A,low,high,key);
        }
    }   
    else
        return (-1);
}