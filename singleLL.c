#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
void display(struct node** head)
{
    struct node* temp = *head;
    if(temp->next==NULL){
        free(temp);
        printf("Empty LL\n");
        return;
    }
    while(temp->next != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    free(temp);
}
void insertSLLbegin(struct node** head, int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = *head;
    *head = newnode;
}
void insertSLLmid(struct node** head, int x, int pos)
{
    
}
int main()
{
    struct node* head = NULL;
    int choice=1,x,pos;
    printf("\n/Implementation of Singly Linked List/\n");
    while (choice)
    {
        printf("1-insertB 2-insertM 2-delete 3-display 0-exit\nchoice - ");
        scanf("%1d",&choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            printf("insert - ");
            scanf("%1d",&x);
            insertSLLbegin(&head, x);
            break;
        case 2:
            printf("insert - ");
            scanf("%4d",&x);
            printf("position - ");
            scanf("%2d",&pos);
            insertSLLmid(&head,x,pos);
            break;
        case 3: 
            display(&head);
            break;
        default:
            break;
        }
    }
    
    return 0;
}