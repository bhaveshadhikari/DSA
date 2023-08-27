//Implementation of hash table with external chaining for solving collision 

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5
typedef struct node NODE;

struct node
{
    int value;
    struct node *next;
};
NODE *tableHead[TABLE_SIZE] = {NULL};


void insertTable(int data)
{
    int keyIndex = data % TABLE_SIZE;
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = data;
    newNode->next = NULL;
    if (tableHead[keyIndex] == NULL)
    {   
        tableHead[keyIndex]=newNode;
        // printf("inserted %d\n",->value);
        return;
    }
    else
    {   
        NODE* indexHead = tableHead[keyIndex];
        while (indexHead->next != NULL)
        {
            indexHead = indexHead->next;
        }

        indexHead->next = newNode;
    }
}

void searchTable(int data){
    int keyIndex = data % TABLE_SIZE;
    // if (tableHead[keyIndex]==NULL)
    // {   printf("\nfound %d\n",data);
    //     return 0;
    // }
    NODE* indexHead = tableHead[keyIndex];
    
    while(indexHead !=NULL){
        if (indexHead->value == data)
        {
            printf("\n%d found\n",data);
            return;
        }
        indexHead= indexHead->next;
    }
    printf("\n%d not found\n",data);
    return;
    

}
void displayTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d\t", i);
        if (tableHead[i] == NULL)
            printf("---\t");
        else
        {
            NODE *temp = tableHead[i];
            while (temp != NULL)
            {
                printf("->%d\t",temp->value);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

void deleteTable(int data){
    int keyIndex = data % TABLE_SIZE;

    NODE *indexHead = tableHead[keyIndex];
    while (indexHead!=NULL)
    {
        if (indexHead ->next != NULL && indexHead->next->value == data)
        {
            NODE* temp = indexHead->next;
            indexHead->next = indexHead->next->next;
            free(temp);
            temp = NULL;
            printf("\n%d deleted\n",data);
            return;
        }
        indexHead=indexHead->next;
    }
    printf("\n%d doesnt exist\n",data);
    return;
}

int main()
{
    insertTable(55);
    insertTable(13);
    insertTable(76);
    insertTable(16);
    insertTable(33);
    displayTable();
    searchTable(36);
    searchTable(16);
    deleteTable(12);
    deleteTable(76);
    searchTable(76);
    displayTable();
    return 0;
}

/*
0       ->55
1       ->76    ->16
2       ---
3       ->13    ->33
4       ---

36 not found

16 found

12 doesnt exist

16 deleted

16 not found
0       ->55
1       ->76
2       ---
3       ->13    ->33
4       ---
*/