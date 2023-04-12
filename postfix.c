#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define max 10
void push(int s[max],int *top,int ele)
{
    if(*top==max-1)
    {
        printf("overflow");
        return;
    }
    (*top)++;
    s[*top]=ele;
}
int pop(int s[max],int *top)
{
    int ele;
    ele=s[*top];
    (*top)--;
    return ele;
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
int compute(int op1,char operator,int op2)
{
    switch(operator)
    {
        case '+':return(op1+op2);
        case '-':return(op1-op2);
        case '*':return(op1*op2);
        case '/':return(op1/op2);
        case '%':return(op1%op2);
        case '^':return(pow(op1,op2));
        default:printf("invalid");
                break;
    }
}
int evaluate(char postfix[max])
{
    int top=-1,s[max],i=0,res,op1,op2;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
            push(s,&top,postfix[i]-'0');
        else
        {
            op2=pop(s,&top);
            op1=pop(s,&top);
            res=compute(op1,postfix[i],op2);
            push(s,&top,res);
        }
        i++; 
    }
   return(pop(s,&top));
}
int main()
{
    char postfix[max];
    int res;
    printf("enter postfix expression");
    scanf("%s",postfix);
    res=evaluate(postfix);
    printf("%d",res);
}