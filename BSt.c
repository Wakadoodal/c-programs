#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *Rlink,*Llink;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct  node));
    if(x==NULL)
    {
        printf("NO");
        exit(0);
    }
    return x;
}
NODE BST(NODE root,int ele)
{
    NODE temp=getnode();
    temp->info=ele;
    temp->Rlink=temp->Llink=NULL;
    if(root==NULL)
    {
        return temp;
    }
    NODE cur=root;
    NODE prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        if(cur->info>ele)
           cur=cur->Llink;
        else
            cur=cur->Rlink;
    }
    if(prev->info>ele)
       prev->Llink=temp;
    else
       prev->Rlink=temp;
    return root;
}
void Inorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->Llink);
    printf("%d\t",root->info);
    Inorder(root->Rlink);
}
void Preorder(NODE root)
{
    if(root==NULL)
      return;
    printf("%d\t",root->info);
    Preorder(root->Llink);
    Preorder(root->Rlink);
}
void Postoder(NODE root)
{
    if(root==NULL)
      return;
    Postoder(root->Llink);
    Postoder(root->Rlink);
    printf("%d\t",root->info);
}
int main()
{
    NODE root=NULL;
    int ele;
    root=BST(root,5);
    root=BST(root,11);
    root=BST(root,26);
    root=BST(root,21);
    root=BST(root,22);
    root=BST(root,66);
    Inorder(root);
    printf("\n");
    Preorder(root);
     printf("\n");
    Postoder(root);
    return 0;
}