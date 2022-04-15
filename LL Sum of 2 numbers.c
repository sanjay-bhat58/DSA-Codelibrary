#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE *create_node(int n)
{
    NODE *n1 = (NODE *)malloc(sizeof(NODE));
    if(n1==NULL)
    {
        printf("Couldn't allocate memory");
        exit(0);
    }
    n1->data = n;
    n1->link=NULL;
    return n1;
}

NODE *insert_front(NODE *head,int n)
{
    NODE *temp = create_node(n);
    if(head==NULL)
        head=temp;
    else
    {
        temp->link = head;
        head = temp;
    }
    return head;
}

void display(NODE *head)
{
    if(head == NULL)
        return;
    display(head->link);
    printf("%d",head->data);
}

NODE *problem2(NODE *L1, NODE *L2)
{
    /*int x = 0, y = 0, res=0;
    int count = 0;
    NODE *a = L1, *b = L2;
    while(a != NULL)
    {
        x = a->data * pow(10,count) + x;
        count++;
        a = a->link;
    }
    x = x+1;
    count = 0;
    while(b != NULL)
    {
        y = y + (b->data *pow(10,count));
        count++;
        b = b->link;
    }
    y = y+1;
    res = x+y;
    NODE *res_head = create_node(0), *temp = res_head;
    while(res > 0)
    {
        temp->link = create_node(res%10);
        res = res/10;
        temp = temp->link;
    }
    return res_head->link;*/
    NODE *res = create_node(0), *a = L1, *b = L2, *temp = res;
    int carry = 0,x,y, sum;
    while(a !=  NULL && b != NULL)
    {
        x = (a != NULL)? a->data : 0;
        y = (b != NULL)? b->data : 0;
        sum = carry + x + y;
        carry = sum / 10;
        temp->link = create_node(sum % 10);
        temp = temp->link;
        if(a != NULL)
            a = a->link;
        if(b != NULL)
            b = b->link;
    }
    if(carry > 0)
        temp->link = create_node(carry);
    return res->link;
}

void main()
{
    NODE *head1=NULL, *head2 = NULL;
    int choice,n;
    while(1)
    {
        printf("\nPress:\n- 1 - : Insert Element to list 1\n- 2 - : Insert Element to list 2\n- 3 - : Display SUM\n- 4 - : Exit\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter Element Value:");
            scanf("%d",&n);
            head1 = insert_front(head1,n);
        }
        else if(choice == 2)
        {
            printf("Enter element value:");
            scanf("%d",&n);
            head2 = insert_front(head2,n);
        }
        else if(choice == 4)
        {
            printf("Thank you\n Exiting.....");
            exit(0);
        }
        else if(choice == 3)
            display(problem2(head1,head2));
    }
}
