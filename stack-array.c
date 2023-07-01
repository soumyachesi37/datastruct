#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK 5

struct stack 
{
    int data[MAX_STACK];
    int top;
};
void push(struct stack*, int);
int pop(struct stack*);
int peek(struct stack*);
int isEmpty(struct stack*);
void display(struct stack);

int main()
{
    struct stack s;
    s.top = -1;
    int choice=1,x,i; 
    printf("/Stack Implementation using Array/");
    while(choice != 0)
    {
        printf("\n1-Push 2-Pop 3-Peek 4-CheckIfEmpty 5-Display 0-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: //push
                printf("Enter Number ");
                scanf("%d",&x);
                push(&s,x);
                break;
            case 2: 
                printf("%d popped",pop(&s));    
                break;
            case 3: //peek
                printf("Element on top is %d",peek(&s));
                break;
            case 4: //isempty
                if(isEmpty(&s))
                    printf("Stack is empty");
                else
                    printf("Stack is not empty");
                break;
            case 5: 
                display(s);
                break;
            case 0:
                break;
            default:
                printf("Invalid Input");
                break;
        }
    }   
}   


void push(struct stack *pt, int x)
{
    if (pt->top == MAX_STACK-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    pt->data[++pt->top] = x;
    printf("%d pushed to stack\n", x);
}
int pop(struct stack *pt)
{
    if (pt->top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return pt->data[pt->top--];
}
int peek(struct stack *pt)
{
    if (pt->top == -1)
        return 0;
    return pt->data[pt->top];
}
int isEmpty(struct stack *pt)
{
    return pt->top == -1;
}
void display(struct stack s)
{
    if(s.top == -1) 
    {
        printf("Stack Empty\n");
        return;
    }
    int i = 0;
    while(i!=s.top+1)
        printf("%d ",s.data[i++]);
}
