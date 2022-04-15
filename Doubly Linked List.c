#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *nlink,*plink;
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
void rev_display(NODE *head);
int count(NODE* head);
float average(NODE *head);
int search(NODE* head,int key);
void highest(NODE *head);
void lowest(NODE *head);
NODE *delete_key(NODE *head);
NODE* sort(NODE *head);

void main()
{
    NODE *head=NULL;
    int choice,cnt,key,pos;
    float avg;
    while(1)
    {
        printf("\n1.Insert Front.\n2.Insert End.\n3.Insert Middle.\n4.Delete Front.\n5.Delete End.\n6.Delete Middle.\n7.Display.\n8.Count.\n9.Average\n10.Search within the list.\n11.Delete the element with given data.\n12.Highest among the List.\n13.Lowest among the List.\n14.Reverse Display.\n15.Sort the Data.\n16.Exit.\n");
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
                    printf("Average of the node values:%.2f\n",avg);
                    break;
            case 10:printf("Enter the key to be searched:");
                    scanf("%d",&key);
                    pos=search(head,key);
                    break;
            case 11:head=delete_key(head);
                    break;
            case 12:highest(head);
                    break;
            case 13:lowest(head);
                    break;
            case 14:rev_display(head);
                    break;
            case 15:head=sort(head);
                    break;
            case 16:printf("Thank You");
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
    n1->nlink=n1->plink=NULL;
    return n1;
}

NODE* insert_front(NODE *head)
{
    NODE *temp;
    temp=create_node();
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

NODE *insert_end(NODE *head)
{
    NODE *temp,*p;
    p=head;
    temp=create_node();
    if(head == NULL)
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
    }
    else if(pos==1)
    {
        temp->nlink=head;
        head->plink=temp;
        head=temp;
    }
    else
    {
        while(i<pos-1)
        {
            p=p->nlink;
            i++;
        }
        temp->nlink = p->nlink;
        p->nlink = temp;
        temp->plink = p;
        if(temp->nlink!=NULL)
        {
            temp->nlink->plink=temp;
        }
    }
    return head;
}

NODE* delete_front(NODE *head)
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
        printf("Deleted Value: %d\n",temp->data);
        free(temp);
    }
    return head;
}

NODE* delete_end(NODE *head)
{
    NODE *temp;
    temp=head;
    if(temp==NULL)
        printf("List is empty!! Deletion cannot be performed!!\n");
    else if(temp->nlink == NULL)
    {
        head=NULL;
        printf("Deleted value is:%d\n",temp->data);
        free(temp);
    }
    else
    {
        while(temp->nlink != NULL)
    {
        temp=temp->nlink;
    }
    temp->plink->nlink=NULL;
    temp->plink=NULL;
    printf("The deleted value is:%d\n",temp->data);
    free(temp);
    }
    return head;
}

NODE* delete_middle(NODE *head)
{
    NODE *p,*temp;
    int pos,cnt,i=1;
    p=temp=head;
    cnt=count(head);
    printf("Enter the position to be deleted:");
    scanf("%d",&pos);
    if(pos<1 || pos>cnt)
        printf("Invalid position !!! Cannot perform deletion.\n");
    else if(head == NULL)
        printf("List is empty hence nothing to delete!!\n");
    else if(pos==1)
    {
        head=temp->nlink;
        temp->nlink=NULL;
        if(head!=NULL)
            head->plink=NULL;
        printf("deleted element is: %d\n",temp->data);
        free(temp);
    }
    else
    {
        while(i<pos-1)
        {
            p=p->nlink;
            i++;
        }
        temp=p->nlink;
        p->nlink=temp->nlink;
        temp->plink=temp->nlink=NULL;
        printf("deleted element is: %d\n",temp->data);
        if(p->nlink!=NULL)
        {
            p->nlink->plink=p;
        }
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
       while(temp!=NULL)
       {
           printf("%d\t",temp->data);
           temp=temp->nlink;
       }
       printf("\n");
    }
}

void rev_display(NODE *head)
{
    NODE *temp=head;
    if(head==NULL)
        printf("List is Empty!!!\n");
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

int count(NODE *head)
{
    int cnt=0;
    NODE *temp=head;
    while(temp != NULL)
    {
        cnt++;
        temp=temp->nlink;
    }
    return cnt;
}

int search(NODE* head,int key)
{
    int c=0,pos=1;
    NODE* temp=head;
    while(temp!=NULL)
        {
            if(temp->data==key)
            {
                c=1;
                break;
            }
             temp=temp->nlink;
             pos++;
        }

    if(c==1)
        {
            printf("'%d' is present in the List at the position:%d\n",key,pos);
            return pos;
        }
    else
        {
            printf("'%d' is not present in the list\n",key);
            return 0;
        }
}

float average(NODE *head)
{
    int cnt,sum=0;
    float avg=0.00;
    cnt=count(head);
    NODE *temp;
    temp=head;
    if(head==NULL)
        return avg;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        temp=temp->nlink;
    }
    avg=(float)sum/cnt;
    return avg;
}

void highest(NODE *head)
{
    NODE *temp;
    int high;
    if(head==NULL)
       {
           printf("There is no elements to compare for highest!!!\n");
       }
    else
    {
    high=head->data;
    temp=head->nlink;
    while(temp!=NULL)
    {
        if(temp->data > high)
            high =temp->data;
        temp=temp->nlink;
    }
        printf("Highest among the list is: %d.\n",high);
    }
}

void lowest(NODE *head)
{
    NODE *temp;
    int low;
    if(head==NULL)
       {
           printf("There is no elements to compare for Lowest!!!\n");
       }
    else
    {
    low=head->data;
    temp=head->nlink;
    while(temp!=NULL)
    {
        if(temp->data < low)
            low =temp->data;
        temp=temp->nlink;
    }
    printf("Lowest among the list is: %d.\n",low);
    }
}

NODE *delete_key(NODE *head)
{
    NODE *temp=head;
    int key,flag;
    printf("Enter the key to be deleted from the list:");
    scanf("%d",&key);
    if(temp == NULL)
    {
        printf("List is empty, nothing to delete!!!");
        return head;
    }
    else if(temp->data == key)
    {
        head=temp->nlink;
        if(head != NULL)
            temp->nlink->plink=NULL;
        temp->nlink=NULL;
        printf("deleted element is: %d\n",temp->data);
        free(temp);
        flag=1;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data == key)
            {
               temp->plink->nlink = temp->nlink;
               if(temp->nlink != NULL)
                    temp->nlink->plink = temp->plink;
               temp->nlink = temp->plink = NULL;
               printf("deleted element is: %d\n",temp->data);
               free(temp);
               flag=1;
               break;
            }
             temp=temp->nlink;
        }
    }
    if(flag != 1)
        printf("Entered key isn't present in the list!!");
    return head;
}

NODE* sort(NODE *head)
{
    int a;
    NODE *temp1,*temp2;
    for(temp1=head;temp1!=NULL;temp1=temp1->nlink)
        for(temp2=temp1->nlink;temp2!=NULL;temp2=temp2->nlink)
            if(temp2->data < temp1->data)
            {
                a=temp1->data;
                temp1->data=temp2->data;
                temp2->data=a;
            }
    if(head!=NULL)
        printf("List is Sorted.\n");
    else
        printf("Sorry List is empty.\n");
    return head;
}
