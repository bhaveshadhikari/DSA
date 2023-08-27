
#include <stdio.h>

int biSearch(int array[], int key, int low, int high){

    while (low <= high){
        int mid = (low+high) / 2;

        if (array[mid] == key)
            return mid;

        if (array[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
int main(){
    int n;
    printf("enter # of elements: ");
    scanf("%d", &n);
    int arr[n], key;
    printf("enter %d sorted elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("enter key to search : ");
    scanf("%d", &key);
    int result = biSearch(arr,key,0,n-1);

    (result == -1) ? printf("Element not found") : printf("element found at index: %d", result);
    return 0;
}

/*
enter # of elements: 6
enter 6 sorted elements : 1 -6 32 37 43 78
enter key to search : 43
element found at index : 4
*/