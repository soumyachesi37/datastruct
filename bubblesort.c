#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEN 100

int bubblesort(int*, int);
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
    
    bubblesort(array,len);
    
    printf("\n/The Sorted Array/\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",*(array+i));
    }        
}

int bubblesort(int *A, int L)
{
    int temp;
    for (int i = 0; i < L-1; i++)
    {
        for (int j = 0; j < L-i-1; j++)
        {
            if (*(A+j) > *(A+j+1))
            {
               temp = *(A+j);
               *(A+j) = *(A+j+1);
               *(A+j+1) = temp;
            }
        }
        printf("\n/Pass %d/\n",i+1);
        for (int i = 0; i < L; i++)
        {
            printf("%d ",*(A+i));
        }
    }
}