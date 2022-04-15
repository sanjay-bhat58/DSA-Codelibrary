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

NODE *insert_end(NODE *head)
{
    NODE *temp = create_node(),*p = head;
    if(head==NULL)
        head=temp;
    else
    {
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
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

/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
*/

NODE *problem1(NODE *head)
{
    if(head == NULL)
        return head;
    NODE *odd = head, *even = head->link, *evenHead = even;
    while(even != NULL && even->link != NULL)
    {
        odd->link = even->link;
        odd = odd->link;
        even->link = odd->link;
        even = even->link;
    }
    odd->link = evenHead;
    return head;
}

void main()
{
    NODE *head=NULL;
    int choice;
    while(1)
    {
        printf("\nPress:\n- 1 - : Insert Element\n- 2 - : Display\n- 3 - : Problem 1 Function\n- 4 - : Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
            head = insert_end(head);
        else if(choice == 2)
            display(head);
        else if(choice == 4)
        {
            printf("Thank you\n Exiting.....");
            exit(0);
        }
        else if(choice == 3)
            head = problem1(head);
    }
}
