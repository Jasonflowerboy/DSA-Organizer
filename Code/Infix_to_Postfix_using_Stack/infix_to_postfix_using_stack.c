#include<stdio.h>
#include<ctype.h>

#define MAXSIZE 100

char stack[MAXSIZE];
int top = -1;


void push(char ch)     //push infix character into the stack -> TOP ++ , stack[TOP] = x;
{    
    stack[++top] = ch;
}

char pop ()  //pop the top character from the stack to postfix expression -> return stack[top]; top --; we usually make postfix[k++] = pop();
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^' || ch == '$')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else // for parenthesis
    {
        return 0;
    }
}

int main(void)
{
    char infix[MAXSIZE];
    char postfix[MAXSIZE];
    int i = 0; // indexing for the infix
    int k = 0; //indexing for the postfix.
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    char ch;
    while((ch=infix[i++]) != '\0') // ch is infix[i] so current infix character which is then i++, we check it until we meet the NULL character.
    {   //my ch is operand, we directly pop into postfix
        if(isalnum(ch))  //if current character is alphabet or number so an operabd.
        {
            postfix[k++] = ch; //postfix[k] = current character, then k++
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while(stack[top] != '(') //until we meet the '(', we keep popping the top into the posfix, 
            {
                postfix[k++] = pop();
                //pop fn will do the top --
            }
            pop(); //popping the '(', pop function won't to return to anyone but will do top -- 
        }
        else //opertator is found
        {
            while( top != -1 && precedence(stack[top]) >= precedence(ch)) //if the stack isn't empty and the top operator has higher or equal precedence
            {                                                       //as the incoming operator, then we need to pop these operators first and then push the new operator
                postfix[k++] = pop();                     //pop function will automatically update the top.
            }
            push(ch);
        }
    }
    while(top!=-1) //after we go through the infix expression some character still maybe left in the stack, we pop them from the top one by one until top is -1.
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0' ; //after everything is set we end a NULL character in the postfix character array to mark the end of the string.

    printf("The postfix expression is %s",postfix);
    return 0;
}