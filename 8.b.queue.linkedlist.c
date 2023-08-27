#include<stdio.h>
#include<stdlib.h>

typedef struct node NODE;

struct node {
    int data;
    struct node* next;
};

NODE* front = NULL;
NODE* rear = NULL;

int isEmpty() {
    return (front == NULL);
}

void enqueue(int data) {
    NODE* newNode = malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Queue is full.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if (isEmpty()){
        printf("Empty Queue!\n");
    }
    NODE *temp = front;
    printf("dequeued: %d\n",temp->data);
    front = front->next;
    free(temp);
}

void traverse() {
    if (isEmpty()) {
        printf("Empty queue!!\n");
        return;
    }
    NODE* ptr = front;
    printf("elements: ");
    while (ptr != NULL) {
       printf("%d ", ptr->data);
       ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    enqueue(4);
    enqueue(3);
    traverse();
    dequeue();
    traverse();
    dequeue();
    traverse();
    return 0;
}

