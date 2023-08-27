#include <stdio.h>
int liSearch(int array[], int size, int key){

    for (int i = 0; i < size; i++)
        if (array[i] == key)
            return i;

    return -1;
}
int main(){
    int n;
    printf("enter # of elements: ");
    scanf("%d", &n);
    int arr[n], key;
    printf("enter %d elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("enter key to search : ");
    scanf("%d", &key);
    int result = liSearch(arr,n,key);

    (result == -1) ? printf("Element not found") : printf("element found at index: %d", result);

    return 0; 
}

/*
enter # of elements: 6
enter 6 elements : 1 -6 32 37 43 78
enter key to search : 37
element found at index : 3
*/