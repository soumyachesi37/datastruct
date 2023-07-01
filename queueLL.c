#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head, int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if(*head==NULL)
    {
        *head = newnode;
        newnode->next = NULL;
        return;
    }
    struct node* temp = *head;
    while(temp->next!=NULL) {
        temp=temp->next;
    } 
    temp->next = newnode;
    newnode->next = NULL;
}
void display(struct node* head)
{
    if(head == NULL)
    {
        printf("Empty LL\n");
        return;
    }
    while(head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }printf("\n");
    return;
}
int pop(struct node** head) 
{
    if (*head == NULL) {
        printf("Empty LL\n");
        return 0;
    }
    if((*head)->next == NULL)
    {
        int x = (*head)->data;
        free(*head);
        *head = NULL;
        return x;
    }
    struct node* temp = *head;
    struct node* prev = *head;
    while(temp->next!=NULL) {
        prev = temp;
        temp=temp->next;
    }
    int x = temp->data;
    prev->next = NULL;
    free(temp);
    return x;
}
int main()
{
    struct node* head = NULL;
    int choice=1,x; 
    printf("/Implementation of a Queue using Linked List/\n");
    while(choice != 0)
    {
        printf("[1-Push 2-Delete 3-Display 0-Exit] ? ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                break;
            case 1: 
                printf("Enter Number ");
                scanf("%d",&x);
                push(&head,x);
                break;
            case 2: 
                printf("%d popped\n",pop(&head));
                break;
            case 3: 
                display(head);
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }   
}

