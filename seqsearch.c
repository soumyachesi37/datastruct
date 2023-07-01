#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEN 100

int seqSearch(int*, int, int);
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
    
    printf("\nEnter element to get position ");
    scanf("%d",&x);

    pos = seqSearch(array,len,x);
    
    if(pos>=0)
        printf("The element %d is present in cell %d",x,pos);
    else
        printf("The element is not present in the array");
    return 0;
} 

int seqSearch(int* A, int L, int key)
{
    for (int i = 0; i < L; i++)
    {
        if (*(A+i)==key)
        {
            return(i);
        }      
    }
    return(-1);
}