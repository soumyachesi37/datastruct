#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEN 100

int greedysort(int*, int);
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
    
    greedysort(array,len);
    
    printf("\n/The Sorted Array/\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ",*(array+i));
    }        
}


int greedysort(int* A, int L)
{
    int min, temp;

    for (int i = 0; i < L-1; i++)
    {
        min = i;
        for (int j = i+1; j < L; j++)
        {
            if (*(A+j) < *(A+min))
            {
                min = j;
            }
        }
        temp = *(A+i);
        *(A+i) = *(A+min);
        *(A+min) = temp;
    }
}