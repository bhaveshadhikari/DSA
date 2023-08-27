#include<stdio.h>
void selectionSort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < size; j++)
            if (arr[j]<arr[min_index])
                min_index = j;

        if (min_index != i){
            int temp = arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }    
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

    selectionSort(arr,n);
    printf("sorted elements : ");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    return 0;
}
/*
enter # of elements: 6
enter 6 elements : 93 47 12 56 63 71
sorted elements : 12  47  56  63  71  93
*/