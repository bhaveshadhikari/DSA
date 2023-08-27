#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define max 20

char expression[] = "(2+3)*3/(5-2)+7";
char postfix[max];
char operator[max];
int op_top = -1;
int post_top = -1;

int isOperand(char operand)
{
    if (
        (operand >= '0' && operand <= '9') ||
        (operand >= 'A' && operand <= 'Z') ||
        (operand >= 'a' && operand <= 'z'))
        return 1;
    return 0;
}

int isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    return 0;
}

void pushPostfix(char data)
{
    if (post_top != max - 1)
        postfix[++post_top] = data;
}

void pushOperator(char data)
{
    if (op_top != max - 1)
        operator[++op_top] = data;
}

char popOperator()
{
    if (op_top > -1)
        return operator[op_top--];
    return '\0'; // Return a null character if the stack is empty
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

int main()
{  
    puts(expression);
    for (int i = 0; i < strlen(expression); i++)
    {
        char symbol = expression[i];

        if (isOperand(symbol))
            pushPostfix(symbol);

        else if (symbol == '(')
            pushOperator(symbol);

        else if (symbol == ')')
        {
            char popped = popOperator();
            while (popped != '(')
            {
                pushPostfix(popped);
                popped = popOperator();
                // the left parenthesis is freed automatically
                // if this assignment popped = ( happens, the top of stack
                // gets reduced after returning (, and after loop
                // breaks, tos points the element below (
            }
        }

        else if (isOperator(symbol))
        {
            while (op_top > -1 && precedence(operator[op_top]) >= precedence(symbol))
                pushPostfix(popOperator());
            pushOperator(symbol);
        }

        // Print the operator stack and postfix stack side by side
        // for (int i = 0; i <= op_top; i++) {
        //     printf("%c ", operator[i]);
        // }
        // printf("\t|\t");
        // for (int i = 0; i <= post_top; i++) {
        //     printf("%c", postfix[i]);
        // }
        // printf("\n");
    }

    // Pop any remaining operators and add them to the postfix expression
    while (op_top > -1)
        pushPostfix(popOperator());
    printf("\npostfix : ");
    for (int i = 0; i <= post_top; i++)
        printf("%c", postfix[i]);

    return 0;
}

/*
(2+3)*3/(5-2)+7

postfix : 23+3*52-/7+
*/