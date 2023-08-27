#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} NODE;

NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

NODE* insert(NODE* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    return root;
}

NODE* search(NODE* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data) 
        return search(root->left, key);
    else 
        return search(root->right, key);
}

int main() {
    int elements[] = {7, 3, 9, 1, 5};
    int numElements = sizeof(elements) / sizeof(elements[0]);

    NODE* root = NULL;
    for (int i = 0; i < numElements; i++) {
        root = insert(root, elements[i]);
    }

    start:;
    int searchKey;
    printf("Enter the element to search for (or -1 to exit): ");
    scanf("%d", &searchKey);
    if (searchKey == -1)
        return 0;

    NODE* result = search(root, searchKey);
    if (result)
        printf("%d found in the BST.\n", searchKey);
    else
        printf("%d not found in the BST.\n", searchKey);
    goto start;
}
/*
Enter the element to search for (or -1 to exit): 3
3 found in the BST.
Enter the element to search for (or -1 to exit): 1
1 found in the BST.
Enter the element to search for (or -1 to exit): 6
6 not found in the BST.
Enter the element to search for (or -1 to exit): -1
*/
