// Copyright (c) 2025 ATANU BYAPARI
// Date: 29-09-2025
// All rights reserved.

#include <stdio.h>
void newSort(int arr[], int low, int high)
{
    while (low <= high)
    {
        int x = high, i = high;

        while (x >= low)
        {
            if (arr[x] > arr[high])
            {
                i--;
            }
            x--;
        }
        if (i != high)
        {
            int temp = arr[i];
            arr[i] = arr[high];
            arr[high] = temp;
        }
        else
        {
            high--;
        }
    }
}
int main()
{
    printf("Enter size: ");
    int size;
    scanf("%d", &size);

    if (size <= 0)
        return 0;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    newSort(arr, 0, size - 1);
    printf("After sorting: \n");
    for (int j = 0; j < size; j++)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}