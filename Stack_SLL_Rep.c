#include<stdio.h>
#include<stdlib.h>

struct stack
{
    struct stack *nlink;
    int data;
};
typedef struct stack NODE;

NODE *create();
NODE* push(NODE *head);
NODE* pop(NODE *head);
void display(NODE *head);

void main()
{
    NODE *head=NULL;
    int choice;
    while(1)
    {
        printf("\n1.Push Operation.\n2.Pop Operation.\n3.Display Operation.\n4.Exit the Program.\n");
        printf("Enter Your Choice of Operation:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=push(head);
                    break;
            case 2:head=pop(head);
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
    n->nlink=NULL;
    return n;
}

NODE *push(NODE *head)
{
    NODE *temp;
    temp=create_node(x);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->nlink=head;
        head->plink=temp;
        head=temp;
    }
    return head;
}

NODE *pop(NODE *head)
{
    NODE* temp;
    temp=head;
    if(temp==NULL)
        printf("List is empty!! Hence deletion is not possible\n");
    else
    {
        head=temp->nlink;
        temp->nlink=NULL;
        if(head!=NULL)
        head->plink=NULL;
        free(temp);
    }
    return head;
}

void display(NODE *head)
{
    NODE *temp=head;
    if(head==NULL)
        printf("EMPTY\n");
    else
    {
        while(temp->nlink != NULL)
            temp=temp->nlink;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->plink;
        }
        printf("\n");
    }
}
