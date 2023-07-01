#include<stdio.h>
#include<stdlib.h>

struct dnode {
struct dnode *prev;
int data;
struct dnode *next;
};

/*adds a new node at the end of the doubly linked list*/
void d_append(struct dnode **s, struct dnode **e, int num)
{
    struct dnode* newnode = (struct dnode*)malloc(sizeof(struct dnode));
    newnode->data = num;
    if(*s==NULL)
    {
        *s = newnode;
        *e = *s;
        newnode->next = NULL;
        newnode->prev = NULL;
        return;
    }
    (*e)->next = newnode;
    newnode->prev = *e;
    newnode->next = NULL;
    *e = newnode;
}
/*adds a new node at the beginning of the doubly linked list*/
void d_addatbeg(struct dnode **s, int num)
{
    struct dnode* newnode = (struct dnode*)malloc(sizeof(struct dnode));
    newnode->data = num;
    if(*s==NULL)
    {
        *s = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
        return;
    }
    newnode->next = *s;
    (*s)->prev = newnode;
    newnode->prev = NULL;
    *s = newnode;    
}
/*displays the contents of the linked list*/
void d_display (struct dnode *q)
{
    if(q==NULL)
    {
        printf("Empty LL\n");
        return;
    }
    do
    {
        printf("%d ",q->data);
        q=q->next;
    } while (q!=NULL); 
    printf("\n");      
}
/*adds a new node after the specified number of nodes (loc; loc = 3 => add the new
node after 3 nodes in the existing list*/
void d_addafter(struct dnode **q, struct dnode **e, int loc, int num) //loc is not equal to 0
{
    struct dnode* temp = *q;
    if(loc == 0 || temp==NULL)
        return;
    while(temp->next!=NULL && loc>1)
    {
        temp = temp->next;
        loc--;
    }
    if(temp->next==NULL && loc==1   )
    {
        d_append(q,e,num);
        return;
    }
    if(loc>1) 
    {
        printf("position doesnt exist\n");
        return;
    }
    struct dnode* newnode = (struct dnode*)malloc(sizeof(struct dnode));
    newnode->data = num;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

/*counts the number of nodes present in the linked list*/
int d_count (struct dnode *q)
{
    if(q==NULL)
    {
        printf("Empty LL\n");
        return 0;
    }
    int i=0;
    do
    {
        i++;
        q=q->next;
    } while (q!=NULL);
    return i;
}
///*deletes the specified node from the doubly linked list with the value num*/
int d_delete(struct dnode **s, struct dnode** e, int num)
{
    if(*s==NULL)
    {
        printf("Empty LL\n");
        return 0;
    }
    struct dnode* temp = *s;
    if(*s==*e)
    {
        int x = temp->data;
        free(temp);
        *s = NULL;
        *e = NULL;
        return x;
    }
    while(temp!=NULL && temp->data!=num)
    {
        temp = temp->next;
    }
    int x = temp->data;
    if(temp->next==NULL)
    {
        temp->prev->next = NULL;
        *e = temp->prev;
        free(temp);
        return x;    
    }
    if(temp->prev==NULL)
    {
        temp->next->prev = NULL;
        *s = temp->next;
        free(temp);
        return x;   
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return x;
}

int main()
{
    struct dnode* head = NULL;
    struct dnode* tail = NULL;
    int choice=1,x,pos;
    printf("/Implementation of Doubly Linked List/\n");
    while (choice)
    {
        printf("1-Append 2-Add@End 3-AddAfter 4-DeleteNum 5-Display 6-Count 0-exit\nchoice - ");
        scanf("%1d",&choice);
        switch (choice)
        {
        case 0:
            break;
        case 1:
            printf("num - ");
            scanf("%d",&x);
            d_append(&head,&tail,x);
            break;
        case 2:
            printf("num - ");
            scanf("%d",&x);
            d_addatbeg(&head,x);
            break;
        case 3:
            printf("num - ");
            scanf("%d",&x);
            printf("position - ");
            scanf("%d",&pos);
            d_addafter(&head,&tail,pos,x);
            break;
        case 4:
            printf("num - ");
            scanf("%d",&pos);
            d_delete(&head,&tail,pos);
            break;
        case 5: 
            d_display(head);
            break;
        case 6:
            printf("no of nodes is %d\n",d_count(head));
        default:
            break;
        }
    }
    
    return 0;
}