#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE *create_node()
{
    NODE *n1 = (NODE *)malloc(sizeof(NODE));
    if(n1==NULL)
    {
        printf("Couldn't allocate memory");
        exit(0);
    }
    printf("Enter the number:");
    scanf("%d",&n1->data);
    n1->link=NULL;
    return n1;
}

NODE *problem_3(NODE *head)
{
    NODE *temp = head,*p,*n = create_node();
    if(temp==NULL)
        head=n;
    else if(temp->link==NULL || temp->data > n->data)
    {
        if(n->data > temp->data)
            temp->link=n;
        else
        {
            n->link=head;
            head=n;
        }
    }
    else
    {
        while(temp->link!=NULL)
        {
            p=temp;
            temp=temp->link;
            if(p->data < n->data && n->data < temp->data)
            {
                n->link = p->link;
                p->link = n;
                break;
            }
        }
        if(temp->data < n->data)
            temp->link = n;
    }
    return head;
}

void display(NODE *head)
{
    NODE *temp;
    temp=head;
    if(temp==NULL)
        printf("List is Empty!!!\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void main()
{
    NODE *head=NULL;
    int choice;
    while(1)
    {
        printf("\nPress:\n- 1 - : Insert Element\n- 2 - : Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            head = problem_3(head);
            display(head);
        }
        else if(choice == 2)
        {
            printf("Thank you\n Exiting.....");
            exit(0);
        }
    }
}
