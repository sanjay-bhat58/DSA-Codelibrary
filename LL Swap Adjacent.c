#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE *create_node(int x)
{
    NODE *n1 = (NODE *)malloc(sizeof(NODE));
    if(n1==NULL)
    {
        printf("Couldn't allocate memory");
        exit(0);
    }
    n1->data = x;
    n1->link=NULL;
    return n1;
}

NODE *insert_end(NODE *head,int x)
{
    NODE *temp = create_node(x),*p = head;
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

NODE *problem4(NODE *head)
{
    NODE *dummy = create_node(0), *current = dummy;
    dummy->link = head;
    while(current->link != NULL && current->link->link != NULL)
    {
        NODE *first = current->link; //assign first node of the pair
        NODE *second = current->link->link; //assign second node of the pair
        first->link = second->link; // assign node after 2nd node of the pair to the link of first node of the pair
        current->link = second; //assign the 2nd node to the link of current node
        current->link->link = first; //assign the 1st node of the pair to the link of 2nd node of the pair
        current = current->link->link; //increment current by 2 nodes
    }
    return dummy->link; // return link of dummy node
}

void main()
{
    NODE *head=NULL;
    int choice,x;
    while(1)
    {
        printf("\nPress:\n- 1 - : Insert Element\n- 2 - : Display\n- 3 - : Problem 4 Function\n- 4 - : Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter the number:");
            scanf("%d",&x);
            head = insert_end(head,x);
        }
        else if(choice == 2)
            display(head);
        else if(choice == 4)
        {
            printf("Thank you\n Exiting.....");
            exit(0);
        }
        else if(choice == 3)
        {
            display(head);
            head = problem4(head);
            display(head);
        }
    }
}

