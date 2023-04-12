#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[20];
    int id;
    struct node *Rlink,*Llink;
};
typedef struct node *NODE;
NODE getnode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}
NODE insert_front(NODE first,char name[20],int id)
{
    NODE temp=getnode();
    temp->id=id;
    strcpy(temp->name,name);
    temp->Rlink=NULL;
    temp->Llink=NULL;
    if(first==NULL)
    {
        return temp;
    }
    temp->Rlink=first;
    first->Llink=temp;
    return temp;
}
NODE delete_rear(NODE first)
{
    if(first==NULL)
    {
        printf("empty");
        return NULL;
    }
    if(first->Llink==NULL)
    {
        printf("the deleted name and is %s %d",first->name,first->id);
        free(first);
        return NULL;
    }
    NODE cur=first;
    NODE prev=NULL;
    while(cur->Rlink!=NULL)
    {
        prev=cur;
        cur=cur->Rlink;
    }
    printf("the deleted name and id is %s %d",cur->name,cur->id);
    free(cur);
    prev->Rlink=NULL;
    return first;
}
void display(NODE first)
{
    if(first==NULL)
    {
        printf("empty");
        return;
    }
    NODE cur=first;
    while(cur!=NULL)
    {
        printf("%s %d",cur->name,cur->id);
        cur=cur->Rlink;
    }
}
void count(NODE first)
{
    int count=0;
    if(first==NULL)
        printf(0);
    NODE cur=first;
    while(cur!=NULL)
    {
        count++;
        cur=cur->Rlink;
    }
    printf("%d",count);
}
int main()
{
    NODE first;
    first=NULL;
    int id,ch;
    char name[20];
    while(1)
    {
        printf("1.insert front 2.delete rear 3.display 4.count");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the name and id");
                   scanf("%s %d",name,&id);
                   first=insert_front(first,name,id);
                   break;
            case 2:first=delete_rear(first);
                    break;
            case 3:display(first);
                    break;
            case 4:count(first);
            default:exit(0);
        }
    }
}