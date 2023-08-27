#include<stdio.h>
void bubbleSort(int arr[],int size){
    for (int i = 0; i < size; i++){ 
        int altered = 0 ; 
        for (int j = 0; j < size-i-1; j++)
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                altered = 1;
            }
        if (altered==0)
            break;
    }
}
int main(){
    int n;
    printf("enter # of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter %d elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubbleSort(arr,n);
    printf("sorted elements : ");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    return 0;
}

/*
enter # of elements: 6
enter 6 elements : 12 7 97 64 11 56
sorted elements : 7  11  12  56  64  97
*/