// Own version of merge_sort
#include <stdio.h>
void merge_sort(int *arr, int low, int high)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2; // Braking into half
    int size = high - low + 1;  // Size of temporary array
    int cp_arr[size];           // Temporary array
    // Making partition
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            cp_arr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            cp_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        cp_arr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        cp_arr[k] = arr[j];
        k++;
        j++;
    }
    // copying all elements back to original array... to fix original position we used (low+initial)* remember this, it's important
    for (int initial = 0; initial < size; initial++)
    {
        arr[low + initial] = cp_arr[initial];
    }
}
int main()
{
    int arr[] = {7, 9, 3, 5, 4, 0, 0, -1, 5, 6, 3, -5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}