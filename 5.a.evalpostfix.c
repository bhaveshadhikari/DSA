/*
if operand push it on the stack

if operator:
pop two out of stack, perform operation,push the result on stack;

at last, pop the stack
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 20
char postfix[] = "753*5/+32-+"; //result : 11
int result[size];
int result_top;

int isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    return 0;
}

void pushResult(int data)
{
    if (result_top != size - 1)
        result[++result_top] = data;
}

int popResult()
{
    if (result_top != size - 1)
        return result[result_top--];
    return '\0';
}

int operation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    default:
        return 0;
    }
}

int main()
{
    puts(postfix);
    for (int i = 0; i < strlen(postfix); i++)
    {
        char symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9')
        {
            int digit = symbol - '0';
            pushResult(digit);
        }
        else if (isOperator(symbol))
        {
            int b = popResult();
            int a = popResult();
            pushResult(operation(a, b, symbol));
        }
    }
    printf("result : %d ", result[result_top]);
    return 0;
}

/*
753*5/+32-+
result : 11
*/