#include <stdio.h>
#include <stdbool.h>
#define MAX 3
int arr[MAX];
int front = -1, rear = -1;
bool isEmpty(){
    if (front == rear && rear == -1)
        return true;
    else
        return false;
}

bool isFull(){
    if (rear == MAX - 1)
        return true;
    else
        return false;
}

void enqueue(int data){
    if(isEmpty())
        front = 0;
    if (isFull())
        printf("\noverflow!");
    else
        arr[++rear] = data;
}

void dequeue(){
    if (isEmpty())
        printf("\nempty queue!!");
    else
        printf("deque : %d", arr[front++]); //front = (front+1)%size
    
    if (front > rear)
        front = rear = -1;
}
void traverse(){
    printf("\n");
    if (isEmpty())
        printf("empty queue!!");
    else
        for (int i = front; i <= rear; i++)
            printf("|%d| ", arr[i]);
}
int main() {
    int choice, element;
    printf("\nQueue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. traverse\n");
    printf("4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", & choice);

        switch (choice) {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", & element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please select a valid option.\n");
        }
    }
}
/*

Queue Operations:
1. Enqueue
2. Dequeue
3. traverse
4. Exit
Enter your choice: 1
Enter element to enqueue: 5
Enter your choice: 1
Enter element to enqueue: 7
Enter your choice: 3

|5| |7| Enter your choice: 2
deque : 5Enter your choice: 1
Enter element to enqueue: 9
Enter your choice: 1
Enter element to enqueue: 6

overflow!Enter your choice: 4
Exiting...
*/