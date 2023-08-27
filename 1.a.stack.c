#include<stdio.h>
#include<stdbool.h>
#define MAX 4
int arr[MAX],top=-1;

bool isEmpty(){
    if (top == -1)
        return true;
    else
    return false;
}
bool isFull(){
    if (top == MAX-1)
        return true;
    else
    return false;
}

void push(int data){
    if(isFull())
        printf("\nstack overflow!!");
    else
        arr[++top]=data;
    return;
}
int pop(){
    if(isEmpty())
        printf("\nstack underflow!!");
    else
        return arr[top--];
    return 0;
}
void traverse(){
    printf("\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n",arr[i]);
    return;
}
int main(){
    printf("popped: %d\n",pop());
    printf("%d\n",isEmpty());
    printf("%d\n",isFull());
    push(7);
    traverse();
    push(9);
    push(17);
    push(23);
    printf("\n push 9 , 17, 23\n");
    push(54);
    traverse();
    // printf("popped: %d\n",pop());
    printf("\n is full %d\n",isFull());
    push(74);
    traverse();
    return 0;
}