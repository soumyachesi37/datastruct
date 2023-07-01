#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEN 100

int insertsort(int*, int);
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
    
    insertsort(array,len);
    
    printf("\n/The Sorted Array/\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",*(array+i));
    }        
}

int insertsort(int* A, int L)
{
    int key, i, j;
    for (i = 1; i < L; i++) 
    {
        key = *(A+i);
        j = i - 1;
        while (j >= 0 && *(A+j) > key)
        {
            *(A+j+1) = *(A+j);
            j--;
        }
        *(A+j+1) = key;

        printf("\n/Pass %d/\n",i);
        for (int i = 0; i < L; i++)
        {
            printf("%d ",*(A+i));
        }
    }
}