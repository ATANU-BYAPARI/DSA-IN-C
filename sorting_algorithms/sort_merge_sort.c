//recursively breaking into pieces and merging
#include <stdio.h>

void print_sorted_array(int* arr, int high){
    for(int i = 0; i <= high; i++){
        printf("%d ", arr[i]);
    }
    printf("<---- Sorted array\n");
}

void merge_it(int *arr, int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int brr[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            brr[k++] = arr[i++];
        }
        else
        {
            brr[k++] = arr[j++];
        }
    }

    while (i <= mid) //left elements, are passing into brr array
    {
        brr[k++] = arr[i++];
    }

    while (j <= high) // left elements, are passing into brr array
    {
        brr[k++] = arr[j++];
    }

    for (int x = 0; x < k; x++) //copying elements to original array
    {
        arr[low + x] = brr[x];
    }
}
// breaking array and calling merge_it function
void pieces(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    pieces(arr, low, mid);
    pieces(arr, mid + 1, high);
    merge_it(arr, mid, low, high);
}

int main()
{
    int arr[] = {7, 9, 3, 5, 4, 0, 8, -1, 5, 6, 3, -5};
    int size = sizeof(arr) / sizeof(arr[0]); //number of element present in the array
    int low = 0;
    int high = size - 1;

    pieces(arr, low, high);
    print_sorted_array(arr, high);
    return 0;
}
