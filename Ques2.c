#include<stdio.h>
#include<string.h>
#define MAX 1000
char stack[MAX];
int top=-1;
void push(char x)
{
if(top>=MAX-1)
printf("Stack is full");
else
{
top++;
stack[top]=x;
}
}
char pop()
{
char x;
x=stack[top];
top--;
return x;
}
int operator(char sign)
{
if(sign=='^' || sign=='*' || sign=='/' || sign=='+' || sign=='-')
return 1;
else
return 0;
}
int precedence(char sign)
{
if(sign=='^')
return 3;
else if(sign=='*' || sign=='/')
return 2;
else if(sign=='+' || sign=='-')
return 1;
else
return 0;

}
int main()
{
char infix[MAX],postfix[MAX],x,y;
int i=0,j=0;
printf("\n Enter arthmetic expression");
scanf("%s",infix);
while(infix[i]!=0)
{
x=infix[i];
if(x=='(')
{
push(x);
}
else if(x>='A' && x<='Z' || x>='x' && x<='z')
{
postfix[j]=x;
j++;
}
else if(operator(x)==1)
{
y=pop();
while(operator(x)==1 && precedence(y)>precedence(x))
{
postfix[j]=y;
j++;
y=pop();
}
push(y);
push(x);
}
else if(x==')')
{
y=pop();
while(y!='(')
{
postfix[j]=y;
j++;
y=pop();
}
}
else
{
printf("\n Invalid syntax");
}
i++;
}
while(top>-1)
{
postfix[j]=pop();
j++;
}

printf("Postfix expression is %s",postfix);
return 0;
}
