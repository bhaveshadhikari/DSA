#include<stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {
    int x = l;
    int y = r;
    int p = arr[l], temp;
    while (x < y) {
        while (arr[x] <= p)  // Modified this line to handle equal elements
            x++;
        while (arr[y] > p)
            y--;
        if (x < y)
            swap(&arr[x], &arr[y]);
    }
    arr[l] = arr[y];
    arr[y] = p;
    return y;
}

void quickSort(int arr[], int l, int r){
    int p;
    if(l<r){
        p = partition(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

void traverse(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {2, 3, 14, 15, 9, 16, 37, 27};
    int size = sizeof(arr) / sizeof(int);
    quickSort(arr,0,size-1);
    traverse(arr,size);
}