#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
void display(struct node* q)
{
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
    return;
}
void addNode(struct node **q, int num)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = num;    
    if (*q==NULL)
    {
        newnode -> next = *q;
        *q = newnode;
        return;
    }
    else if(num <= (*q)->data)
    {
        if (num==((*q)->data))
        {
            printf("same value\n");
            free(newnode);
            return;
        }
        newnode -> next = *q;
        *q = newnode;
        return;
    }
    else
    {
        struct node* temp = *q;
        while(temp->next!=NULL && num >= (temp->next)->data) 
        {
            if (num==(temp->next)->data)
            {
                printf("same value\n");
                free(newnode);
                return;
            }
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return;
    }       
}
int count(struct node* q)
{
    int i=0;
    while(q!=NULL)
    {
        i++;
        q=q->next;
    }
    return i;
}
void mergeNode (struct node *p, struct node *q, struct node **s)
{
    while(p!=NULL)
    {
        addNode(s,p->data);
        p=p->next;
    }    
    while(q!=NULL)
    {
        addNode(s,q->data);
        q=q->next;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int x;
    char choice;
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    printf("taking values for first linked list\n");
    do
    {
        printf("enter num ");
        scanf("%d",&x);
        addNode(&head1, x);
        printf("continue? ");
        scanf(" %c",&choice);
    }
    while(choice == 'y');
    printf("taking values for second linked list\n");
    do
    {
        printf("enter num ");
        scanf("%d",&x);
        addNode(&head2, x);
        printf("continue? ");
        scanf(" %c",&choice);
    }
    while(choice == 'y');
    printf("new merged linked list");
    mergeNode(head1,head2,&head3);
    display(head3);
    return 0;
}
