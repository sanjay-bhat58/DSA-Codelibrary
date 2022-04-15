#include<stdio.h>
#include<stdlib.h>

struct queue
{
    struct queue *nlink,*plink;
    int data;
};
typedef struct queue NODE;

NODE *create();
NODE* enqueue(NODE *head);
NODE* dequeue(NODE *head);
void display(NODE *head);

void main()
{
    NODE *head=NULL;
    int choice;
    while(1)
    {
        printf("\n1.enqueue Operation.\n2.dequeue Operation.\n3.Display Operation.\n4.Exit the Program.\n");
        printf("Enter Your Choice of Operation:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=enqueue(head);
                    break;
            case 2:head=dequeue(head);
                    break;
            case 3:display(head);
                    break;
            case 4:printf("Thank You!!!");
                    exit(0);
            default:printf("Sorry!! Invalid Choice");
                    break;
        }
    }
}

NODE *create()
{
    NODE *n;
    n=(NODE* )malloc(sizeof(NODE));
    if(n==NULL)
    {
        printf("Sorry!!! Memory cannot be allocated.");
        exit(0);
    }
    printf("Enter the element to be inserted:");
    scanf("%d",&n->data);
    n->nlink=n->plink=NULL;
    return n;
}

NODE *enqueue(NODE *head)
{
    NODE *temp=create(),*p=head;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(p->nlink!=NULL)
            p=p->nlink;
        p->nlink=temp;
        temp->plink=p;
    }
    return head;
}

NODE *dequeue(NODE *head)
{
    NODE *temp=head;
    if(head==NULL)
        printf("queue UnderFlow!!! There are no elements in the queue to perform dequeue Operation.\n");
    else
    {
        head=head->nlink;
        if(head!=NULL)
            head->plink=NULL;
        printf("dequeued element is: %d",temp->data);
        temp->nlink=NULL;
        free(temp);
    }
    return head;
}

void display(NODE *head)
{
    NODE *temp=head;
    if(head==NULL)
        printf("Sorry!! There are no elements in the queue.\n");
    else
    {
        while(temp!=NULL)
           {
               printf("%d\t",temp->data);
               temp=temp->nlink;
           }
        printf("\n");
    }
}

