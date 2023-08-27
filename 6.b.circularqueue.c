#include <stdio.h>
#include <stdbool.h>
#define MAX 3
int arr[MAX];
int front = -1, rear = -1;
bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

int isFull()
{
    if ((front == rear + 1) || (rear == MAX - 1 && front == 0))
        return 1;
    return 0;
}

void enqueue(int element)
{
    if (isFull())
        printf("\nqueue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = element;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        int element = arr[front];

        if (front == rear)
            front = rear = -1;

        else
            front = (front + 1) % MAX;

        printf("\nDeleted : %d \n", element);
        return element;
    }
}

void traverse()
{
    printf("\n");
    if (isEmpty())
        printf("empty queue!!");
    else
        for (int i = front; i != rear; i=(i+1)%MAX)
            printf("|%d| ", arr[i]);
        printf("|%d| ",arr[rear]);
}
int main()
{
    enqueue(10);
    traverse();
    enqueue(11);
    enqueue(12);
    traverse();
    enqueue(13);
    dequeue();
    enqueue(27);
    traverse();
    return 0;
}
/*
|10| 
|10| |11| |12| 
queue is full!! 

Deleted : 10 

|11| |12| |27| 
*/