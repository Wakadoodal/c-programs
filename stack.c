#include<stdio.h>
#include<stdlib.h>
#define max 10
void push(int s[max],int *top,int ele)
{
    printf("inside");
    if(*top==max-1)
    {
        printf("overflow condition");
        return;
    }
    (*top)++;
    s[*top]=ele;
}
void pop(int s[max],int *top)
{
    int ele;
    if(*top==-1)
    {
        printf("underflow condition");
        return;
    }
    (*top)--;
    ele=s[*top];
}
int check_palindrome(int s[max],int top)
{
    int i,j,count=0,temp[max];
    for(j=0;top>=0;j++)
    {
        temp[j]=s[top--];
        count++;
    }
    for(i=0;i<count/2;i++)
    {
        if(temp[i]!=temp[count-i-1])
          return -1;
    }
    return 1;
}
void display(int s[max],int top)
{
    if(top==-1)
    {
        printf("empty");
        return;
    }
    for(int i=top;i>=0;i--)
       printf("%d",s[i]);
}
int main()
{
    int s[max],top=-1,ch,ele,res;
    while(1)
    {
        printf("1.push 2.pop 3.pallindrome 4.display");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter ele");
                   scanf("%d",&ele);
                   push(s,&top,ele);
                   break;
            case 2:pop(s,&top);
                   break;
            case 3:res=check_palindrome(s,top);
                    if(res==-1)
                       printf("not");
                    else 
                        printf("yes");
                   break;
            case 4:display(s,top);
                   break;
            default:exit(0);
        }
    }
}