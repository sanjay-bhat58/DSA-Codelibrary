#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE *create_node();
NODE *insert_front(NODE *head);
NODE *insert_end(NODE *head);
NODE *insert_middle(NODE *head);
NODE* delete_front(NODE *head);
NODE* delete_end(NODE *head);
NODE* delete_middle(NODE *head);
void display(NODE *head);
int count(NODE* head);
float average(NODE *head);
void search(NODE* head);

void main()
{
    NODE *head=NULL;
    int choice,cnt,key;
    float avg;
    while(1)
    {
        printf("\n1.Insert Front.\n2.Insert End.\n3.Insert Middle.\n4.Delete Front.\n5.Delete End.\n6.Delete Middle.\n7.Display.\n8.Count.\n9.Average\n10.Search within the list.\n11.Exit.\n");
        printf("\nEnter Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=insert_front(head);
                    break;
            case 2:head=insert_end(head);
                    break;
            case 3:head=insert_middle(head);
                    break;
            case 4:head=delete_front(head);
                    break;
            case 5:head=delete_end(head);
                    break;
            case 6:head=delete_middle(head);
                    break;
            case 7:display(head);
                    break;
            case 8:cnt=count(head);
                    printf("No. of Nodes=%d\n",cnt);
                    break;
            case 9:avg=average(head);
                    printf("Average of the node values:%.2f",avg);
                    break;
            case 10:search(head);
                    break;
            case 11:printf("Thank you");
                    exit(0);
            default:printf("Invalid Choice\n");
                    break;
        }
    }
}
NODE *create_node()
{
    NODE *n1;
    n1=(NODE *)malloc(sizeof(NODE));
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
NODE* insert_front(NODE *head)
{
    NODE *p,*temp;
    p=head;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
        temp->link=head;
    }
    else
    {
        while(p->link!=head)
        {
            p=p->link;
        }
        p->link=temp;
        temp->link=head;
        head=temp;
    }
    return head;
}
NODE *insert_end(NODE *head)
{
    NODE *temp,*p;
    p=head;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
        temp->link=head;
    }
    else
    {
        temp->link=head;
        while(p->link!=head)
            p=p->link;
            p->link=temp;
    }
    return head;
}
NODE *insert_middle(NODE *head)
{
    int pos,cnt,i=1;
    cnt=count(head);
    NODE *p=head,*temp;
    printf("Enter the position for the insertion:");
    scanf("%d",&pos);
    temp=create_node();

    if(pos<1 || pos>cnt+1)
        printf("Sorry!! Invalid Position");
    else if(pos==1 && head==NULL)
    {
        head=temp;
        temp->link=head;
    }
    else if(pos==1)
    {
        while(p->link!=head)
            p=p->link;
        p->link=temp;
        temp->link=head;
        head=temp;
    }
    else
    {
        while(i<pos-1)
        {
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
    }
    return head;
}
NODE* delete_front(NODE *head)
{
    NODE* temp,*p;
    temp=head;
    p=head;
    if(temp==NULL)
        printf("List is empty!! Hence deletion is not possible\n");
    else if(temp->link==head)
    {
        head=NULL;
        printf("Deleted Value: %d\n",temp->data);
        temp->link=NULL;
        free(temp);
    }
    else
    {
        while(p->link!=head)
        p=p->link;
        p->link=temp->link;
        head=temp->link;
        printf("Deleted Value: %d\n",temp->data);
        temp->link=NULL;
        free(temp);
    }
    return head;
}
NODE* delete_end(NODE *head)
{
    NODE *p,*temp;
    temp=head;
    if(temp==NULL)
        printf("List is empty!! Deletion cannot be performed!!\n");
    else if(temp->link==head)
    {
        head=NULL;
        printf("Deleted value is:%d\n",temp->data);
        temp->link==NULL;
        free(temp);
    }
    else
    {
        while(temp->link!=head)
    {
        p=temp;
        temp=temp->link;
    }
    p->link=head;
    temp->link=NULL;
    printf("The deleted value is:%d\n",temp->data);
    free(temp);
    }
    return head;
}
NODE* delete_middle(NODE *head)
{
    NODE *p,*temp;
    int pos,cnt,i=1;
    temp=p=head;
    cnt=count(head);
    printf("Enter the position to be deleted:");
    scanf("%d",&pos);
    if(pos<1 || pos>cnt)
        printf("Invalid position !!! Cannot perform deletion.\n");
    else if(head == NULL)
        printf("List is empty hence nothing to delete!!\n");
    else if(pos==1 && temp->link==head)
    {
        head=NULL;
        printf("deleted value is: %d\n",temp->data);
        temp->link==NULL;
        free(temp);
    }
    else if(pos==1)
    {
        while(p->link!=head)
            p=p->link;
        p->link=temp->link;
        head=temp->link;
        printf("deleted value is: %d\n",temp->data);
        temp->link==NULL;
        free(temp);

    }
    else
    {
          while(i<pos-1)
        {
            p=p->link;
            i++;
        }
        temp=p->link;
        p->link=temp->link;
        printf("deleted value is: %d\n",temp->data);
        temp->link=NULL;
        free(temp);
    }
    return head;
}
void display(NODE *head)
{
    NODE *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is Empty!!!\n");
    }
    else
    {
        do
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }while(temp!=head);
        printf("\n");
    }
}
int count(NODE *head)
{
    int cnt=0;
    NODE *temp;
    temp=head;
    if(head != NULL)
    {
       do
       {
           cnt++;
           temp=temp->link;
       } while(temp!=head);
    }
    return cnt;
}
float average(NODE *head)
{
    int cnt,sum=0;
    float avg;
    cnt=count(head);
    NODE *temp;
    temp=head;
    if(temp==NULL)
        printf("List is Empty!!!");
    else
    {
    do
    {
        sum=sum+temp->data;
        temp=temp->link;
    }while(temp!=head);
    avg=(float)sum/cnt;
    return avg;
    }
}
void search(NODE* head)
{
    int c=0,key,pos=1;
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    NODE* temp=head;
    while(temp!=NULL)
        {
            if(temp->data==key)
            {
                c=1;
                break;
            }
             temp=temp->link;
             pos++;
        }

    if(c==1)
        printf("The entered key is present in the List at the position:%d\n",pos);
    else
        printf("The entered key is not present in the list\n");
}
