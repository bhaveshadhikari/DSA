#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node
{
    int data;
    struct node *next;
};

NODE *top = NULL;

void push(int data){
    NODE *newNode = malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("stack is full\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty, cannot delete.\n");
        return ;
    }
    NODE* temp = top;
    printf("popped : %d\n",temp->data);
    top = top->next;
    free(temp);
}

void traverse(){
    NODE *ptr = top;
    while (ptr){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    push(2);
    traverse();
    push(7);
    traverse();
    push(9);
    traverse();
    pop();
    pop();
    pop();
    pop();
    return 0;
}
/*
2 
7 2 
9 7 2 
popped : 9
popped : 7
popped : 2
Stack is empty, cannot delete.
*/