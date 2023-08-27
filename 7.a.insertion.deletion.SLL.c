#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE *createNode(int data)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAt(NODE **head, int position, int data)
{
    NODE *ptr = *head;
    
    if (position == 0)
    {
        NODE *newNode = createNode(data);
        newNode->next = ptr;
        *head = newNode;
        return;
    }
    
    for (int i = 1; i < position; i++)
    {
        if (ptr == NULL || ptr->next == NULL)
        {
            printf("invalid position!\n");
            return;
        }
        ptr = ptr->next;
    }
    
    NODE *insNode = createNode(data);
    insNode->next = ptr->next;
    ptr->next = insNode;
}


void deleteAt(NODE **head , int position){
    
    if (*head == NULL)
    {
        printf("empty list!!");
        return;
    }
    
    if (position == 0)
    {
        NODE* temp = *head;
        (*head)= (*head)->next;
        free (temp);
        return ;
    }
    NODE* temp = *head;
    for (int i = 1; i < position; i++)
    {
        
        if (temp == NULL || temp->next == NULL)
        {
            printf("invalid position!!\n");
            return;
        }
        temp = temp->next;
        
    }
    NODE* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

void traverse(NODE *ptr)
{
    while(ptr!=NULL){
        printf("%d , ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main()
{
    NODE *head=NULL;
    insertAt(&head, 0, 5);
    traverse(head);
    insertAt(&head, 1, 6);
    traverse(head);
    insertAt(&head, 2, 7);
    traverse(head);
    insertAt(&head, 0, 9);
    traverse(head);
    deleteAt(&head, 2);
    traverse(head);
    deleteAt(&head, 0);
    traverse(head);
    deleteAt(&head, 1);
    traverse(head);
    deleteAt(&head, 10);
    traverse(head);
    return 0;
}


/*
5 ,
5 , 6 ,
5 , 6 , 7 ,
9 , 5 , 6 , 7 ,
9 , 5 , 7 ,
5 , 7 ,
5 ,
invalid position!!
5 ,
*/