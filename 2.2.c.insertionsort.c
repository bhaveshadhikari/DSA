#include <stdio.h>
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int n;
    printf("enter # of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter %d elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    insertionSort(arr, n);
    printf("sorted elements : ");
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    return 0;
}
/*
enter # of elements: 6
enter 6 elements : 78 23 98 10 17 25
sorted elements : 10  17  23  25  78  98
*/