//insertion sort in ascending order...
#include <stdio.h>
int main()
{
    int arr[] = {3, -1, 9, 1, 0, 5, 4, 7, 4, 8};
    int size = 10;

    // array before sorting...
    for (int idx = 0; idx < size; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf(" <--- Array before sorting\n");
    // sorting...
    for (int i = 1; i < size; i++)
    {
        int store = arr[i];
        int idx = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (store < arr[j]) // for descending order put store> arr[j]
            {
                arr[j + 1] = arr[j];
                idx = j;
            }
            else 
            {
                break; // break when correct position is found
            }
        }
        arr[idx] = store;
    }

    // array after sorting...
    for (int jdx = 0; jdx < size; jdx++)
    {
        printf("%d ", arr[jdx]);
    }
    printf(" <--- Array after sorting\n");
}