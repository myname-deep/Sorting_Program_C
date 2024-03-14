#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define max 50

// Infix to Postfix

char* inToPost(char []);
int pre(char);
int isoperator(char );
// Postfix postfixEval
int postfixEval(char []);
// Stack Programs

void push(char [],int *,char);
char pop(char [],int *);

int main()
{
    char s[50],*c;
    int ans;
    printf("\nPlease Enter your string:- ");
    gets(s);
    c=inToPost(s);
    printf("This is the infix expression:- %s",c);
    strcpy(s,c);
    puts(s);
    ans = postfixEval(c);
    return 0;
}

char* inToPost(char s[])
{
    char *c,a[max],temp;
    c=(char *)malloc(50*sizeof(char));
    int top=-1;
    push(a,&top,'(');
    int i=0;
    strcat(s, ")");
    int j=0;
    while(top!=-1)
    {
        if(s[i]=='(')
        {
            push(a,&top,s[i]);
        }
        else if(isalnum(s[i]))
        {
            c[j++]=s[i];
        }
        else if(s[i]==')')
        {
            while((temp=pop(a,&top))!='(')
            {
                
                    c[j++]=temp;
                
            }
        }
        else
        {
            
            while(isoperator(a[top]) && pre(a[top])>=pre(s[i]))
            {
                temp=pop(a,&top);
                c[j++]=temp;
            }
            push(a,&top,s[i]);
        }
        i++;
        
    }
    return c;
}

void push(char a[],int *top,char data)
{
    if(*top==max-1)
    {
        printf("\nStack Overflow!!");
        return;
    }
    *top=*top+1;
    a[*top]=data;
}
char pop(char a[],int *top)
{
    char data;
    if(*top==-1)
    {
        printf("\nStack Underflow");
        return 'c';
    }
    data = a[*top];
    a[*top]=0;
    *top=*top-1;
    return data;
}
int pre(char c)
{
    switch(c)
    {
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
int isoperator(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            return 1;
        default:
            return 0;
    }
}
