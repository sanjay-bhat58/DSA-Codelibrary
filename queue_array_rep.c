#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
void enqueue(int queue[5]);
void dequeue(int queue[5]);
void display(int queue[5]);

void main()
{
    int queue[5],choice;
    while(1)
    {
        printf("\n1.enqueue Operation.\n2.dequeue Operation.\n3.Display Operation.\n4.Exit the Program.\n");
        printf("Enter Your choice of action:");
        scanf("%d",&choice);
        if(choice==1)
            enqueue(queue);
        else if(choice==2)
            dequeue(queue);
        else if(choice==3)
            display(queue);
        else if(choice==4)
        {
            printf("Thank You!!!!!");
            exit(0);
        }
        else
            continue;
    }
}

void enqueue(int queue[5])
{
    int ele;
    if(rear==-1)
    {
        front=0;
        rear=0;
        printf("Enter the element to be inserted:");
        scanf("%d",&ele);
        queue[rear]=ele;
        return;
    }
    if(rear>5)
        printf("queue OverFlow!!! New element cannot be added.\n");
    else
    {
        printf("Enter the element to be inserted:");
        scanf("%d",&ele);
        rear+=1;
        queue[rear]=ele;
    }
}

void dequeue(int queue[5])
{
    int ele;
    if(front>rear || front==-1)
        printf("queue UnderFlow!!!! There is no elements in the queue.\n");
    else
    {
        ele=queue[front];
        front+=1;
        printf("Deleted Element in the queue is: %d\n",ele);
    }
}

void display(int queue[5])
{
    if(rear==-1 || front>rear)
        printf("Sorry!! The queue is empty.\n");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
}

