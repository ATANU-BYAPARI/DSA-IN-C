#include <stdio.h>
void quick_sort(int *arr, int low, int high)
{
    if(low>=high) return;
    int x=high;
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (arr[i] <= pivot)
    {
        if (arr[i] > pivot)
        {
            break;
        }
        else
        {
            i++;
        }
    }
    while (j >= i)
    {
        if (arr[j] >= pivot)
        {
            int temp = arr[j];
            arr[j] = arr[x];
            arr[x] = temp;
            x--;
            j--;
        }
        else
        {
            j--;
        }
    }

    int store = arr[low];
    arr[low] = arr[x];
    arr[x] = store;
    //x--;
    quick_sort(arr,low,x-1);
    quick_sort(arr,x+1,high);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]); // sizeof(arr) will show sizeof array in bits

    quick_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}