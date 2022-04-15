#include<stdio.h>
#include<stdlib.h>

int top=-1;
void pop(int stack[5]);
void push(int stack[5]);
void display(int stack[5]);

void main()
{
    int stack[5],choice;
    while(1)
    {
        printf("\n1.Push Operation.\n2.Pop Operation.\n3.Display Operation.\n4.Exit the Program.\n");
        printf("Enter Your choice of action:");
        scanf("%d",&choice);
        if(choice==1)
            push(stack);
        else if(choice==2)
            pop(stack);
        else if(choice==3)
            display(stack);
        else if(choice==4)
        {
            printf("Thank You!!!!!");
            exit(0);
        }
        else
            continue;
    }
}

void push(int stack[5])
{
    int ele;
    if(top>=5)
        printf("Stack OverFlow!!! New element cannot be added.\n");
    else
    {
        printf("Enter the element to be inserted:");
        scanf("%d",&ele);
        top+=1;
        stack[top]=ele;
    }
}

void pop(int stack[5])
{
    int ele;
    if(top<0)
        printf("Stack UnderFlow!!!! There is no elements in the stack.\n");
    else
    {
        ele=stack[top];
        top-=1;
        printf("Deleted Element in the stack is: %d\n",ele);
    }
}

void display(int stack[5])
{
    if(top<0)
        printf("Sorry!! The stack is empty.\n");
    else
    {
        for(int i=top;i>=0;i--)
            printf("%d\t",stack[i]);
    }
}
