    #include<stdio.h>
    #include<stdlib.h>

    struct node
    {
        int data;
        struct node* next;
    };

    void display(struct node *q)
    {
        if(q==NULL) {
            printf("Empty LL\n");
            return;
        }
        struct node* head = q;
        do {
            head = head->next;
            printf("%d ",head->data);
        } while(q!=head);
        printf("\n");
        return;
    }
    int deleteNode(struct node** q)
    {
        if(*q==NULL)
        {
            printf("Empty LL\n");
            return 0;
        }
        if((*q)->next==*q)
        {
            int x = (*q)->data;
            free(*q);
            *q = NULL;
            return x;
        }
        struct node* temp = *q;
        do {
            temp = temp->next;
        } while(temp->next != *q);
        int x = (*q)->data;
        temp->next = (*q)->next;
        free(*q);
        *q=temp;
        return x;
    }
    void appendNode (struct node **q, int num)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        if (*q==NULL)
        {
            *q = newnode;
            newnode->next = newnode;
            return;
        }
        newnode->next = (*q)->next;
        (*q)->next = newnode;
        (*q) = newnode;
        return;    
    }
    void reverseCLL(struct node **q)
    {
        if(*q==NULL)
        {
            printf("Empty LL\n");
            return;
        }
        if((*q)->next==*q) //for one
            return;
        if(((*q)->next)->next==*q) //for two
        {
            *q = (*q)->next;
            return;
        }
        struct node* back = *q; //5
        struct node* front = (*q)->next; //1
        struct node* temp;
        *q=(*q)->next;
        do{
            temp = front->next;
            front->next = back; //1->5
            back = front;
            front = temp;
        } while(front!=*q);
        return;
    }

    int main()
    {
        struct node* head = NULL;
        int x, choice = 1;
        
        printf("\n/Implementation of Cicular Linked List/\n");
        
        while(choice)
        {
            printf("1-append 2-delete 3-display 4-reverse 0-exit\nchoice - ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 0:
                break;
            case 1:
                printf("num - ");
                scanf("%d",&x);
                appendNode(&head, x);
                break;
            case 2:
                x = deleteNode(&head);
                printf("%d deleted\n",x);
                break;
            case 3: 
                display(head);
                break;
            case 4:
                reverseCLL(&head);
                break;
            default:
                break;
            }
        }
        return 0;
    }