#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node NODE;

NODE *create_node(int x);
NODE *insert(NODE *root,int x);
void display(NODE *root);
NODE *delete_1(NODE *root,int key);
NODE *findmin(NODE *root);
NODE *findmax(NODE *root);

void main()
{
    NODE *root=NULL,*lowest,*highest;
    int x,choice,key;
    while(1)
    {
        printf("\n1.Insert element.\n2.Display.\n3.Delete a key from tree.\n4.Exit.\n");
        printf("Enter Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the element:");
                    scanf("%d",&x);
                    root=insert(root,x);
                    break;
            case 2:display(root);
                    break;
            case 4:printf("Thank you");
                    exit(0);
            case 3:printf("Enter the key to be deleted:");
                    scanf("%d",&key);
                    root=delete_1(root,key);
                    break;
            case 8:lowest=findmin(root);
                    printf("Smallest Value in the tree is:%d",lowest->data);
                    break;
            case 20:highest=findmax(root);
                    printf("Largest Value in the tree is:%d",highest->data);
                    break;
            default:printf("Invalid Choice\n");
                    break;
        }
    }
}

NODE *insert(NODE *root,int x)
{
    if(root==NULL)
        return create_node(x);
    else if(x<root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
    return root;
}

NODE *create_node(int x)
{
    NODE *n=(NODE *)malloc(sizeof(NODE));
    if(n==NULL)
    {
        printf("Memory allocation error!!!!");
        exit(0);
    }
    n->data=x;
    n->left=n->right=NULL;
    return n;
}

void display(NODE *root)
{
    if(root==NULL)
    {
        printf("Tree is empty!!\n");
        return;
    }
    else
    {
        if(root->left!=NULL)
            display(root->left);
        printf("%d\t",root->data);
        if(root->right!=NULL)
            display(root->right);
    }
}

NODE *findmin(NODE *root)
{
    NODE *temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}

NODE *findmax(NODE *root)
{
    NODE *temp=root;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp;
}

NODE *delete_1(NODE *root,int key)
{
    if(root==NULL)
    {
        printf("Tree is empty!!!");
        return root;
    }
    else if(key<root->data)
            root->left=delete_1(root->left,key);
    else if(key>root->data)
            root->right=delete_1(root->right,key);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            NODE *temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            NODE *temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else
        {
            NODE *temp=findmin(root->right);
            root->data=temp->data;
            free(temp);
        }
    }
    return root;
}
