#include <stdio.h>
#include<stdbool.h>
#define MAX 3
int stack_arr[MAX];
int top = -1;
 
bool isFull(){
    if(top==MAX-1)
        return true;
    else
        return false;
}
 
bool isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}
 
int peek(){
    return stack_arr[top];
}
 
void push(int data){
    if(isFull())
        printf("stack overflow\n");
    else
        stack_arr[++top]=data;
}
 

int pop(){
    if(isEmpty())
       printf("stack underflow\n");
    else
      return stack_arr[top--];
}
 
void traverse(){
    printf("the elements are : \n");
    for(int i=top ; i >=0 ; i--)
        printf("%d\n",stack_arr[i]);
}

int main() {
    printf("\n**************\nstack as ADT\n");
    printf("1. isFull() \n");
    printf("2. isEmpty() \n");
    printf("3. push(data)\n");
    printf("4. pop()\n");
    printf("5. peek()\n");
    printf("6. traverse()\n");
    printf("7. quit\n");
    top:
    printf("enter choice: ");
    int choice;
    scanf("%d",&choice);
 
    switch (choice)
    {
    case 1:
      printf("isFull? : %d \n",isFull());
      goto top;
 
    case 2:
      printf("isEmpty? : %d \n",isEmpty());
      goto top;
 
    case 3:
    printf("enter data to push: ");
    int data;
    scanf("%d",&data);
    push(data);
    goto top;
 
    case 4:
    printf("popped : %d\n",pop());
    goto top;
 
    case 5:
    printf("peek-top : %d \n",peek());
    goto top;
 
    case 6:
    traverse();
    goto top;
     
    case 7:
    return 0;
 
    default:
     printf("!!invalid choice!!\n");
     goto top;
    }
    return 0;
}


/* OUTPUT SCREEN
**************
stack as ADT
1. isFull() 
2. isEmpty() 
3. push(data)
4. pop()
5. peek()
6. traverse()
7. quit
enter choice: 2
isEmpty? : 1 
enter choice: 3
enter data to push: 9
enter choice: 3
enter data to push: 7
enter choice: 3
enter data to push: 6
enter choice: 3
enter data to push: 8
stack overflow
enter choice: 1
isFull? : 1 
enter choice: 4
popped : 6
enter choice: 5
peek-top : 7 
enter choice: 6
the elements are : 
7
9
enter choice: 7
*/
