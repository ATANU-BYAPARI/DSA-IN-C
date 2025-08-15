// May be inefficient,but it is my own creativity...
#include <stdio.h>
#include <stdlib.h>
void count_sort(int *arr, int size)
{
    int idx = 1;
    int kdx = 1;
    int max = arr[0];
    int min = arr[0];
    while (idx < size)
    {
        if (arr[idx] > max)
        {
            max = arr[idx]; // finding maximum element
        }
        idx++;
    }
    while (kdx < size)
    {
        if (arr[kdx] < min)
        {
            min = arr[kdx]; // finding minimum element
        }
        kdx++;
    }

    if (min < 0)
    {
        int *temp_arr = (int *)malloc((abs(max) - min + 1) * sizeof(int));
        for (int i = 0; i < abs(max) - min + 1; i++)
        {
            temp_arr[i] = 0; // initializing all indeces with zero
        }
        // modification will be done here for handling negative numbers
        for (int j = 0; j < size; j++) // size=array size
        {
            int x = arr[j]; // scanning numbers
            if (x >= 0)
            {
                temp_arr[x] += 1;
            }
            else
            {
                int y = abs(max) - arr[j];
                temp_arr[y] += 1;
            }
        }
        // and modification should be here too...
        int jdx = 0;
        for (int k = abs(max) - min; k > abs(max); k--) // handles -ve part
        {
            while (temp_arr[k] > 0)
            {
                arr[jdx] = abs(max) - k;
                jdx++;
                temp_arr[k] -= 1;
            }
        }

        for (int m = 0; m <= abs(max); m++)
        { // handles +ve part
            while (temp_arr[m] > 0)
            {
                arr[jdx] = m;
                jdx++;
                temp_arr[m] -= 1;
            }
        }

        free(temp_arr);
    }
    else
    {
        int *temp_arr = (int *)malloc((max + 1) * sizeof(int)); // dynamically allocating memory, we can avoid this without any issue
        for (int i = 0; i < max + 1; i++)
        {
            temp_arr[i] = 0; // initializing all indeces with zero
        }
        for (int j = 0; j < size; j++)
        {
            int x = arr[j];
            temp_arr[x] += 1;
        }
        int jdx = 0;
        for (int k = 0; k <= max; k++)
        {
            while (temp_arr[k] > 0)
            {
                arr[jdx] = k;
                jdx++;
                temp_arr[k] -= 1;
            }
        }
        free(temp_arr);
    }
}
int main()
{
    int arr[] = {100, 101, 103}; // modified for negative numbers
    int size = sizeof(arr) / sizeof(arr[0]);
    if (size > 0)
    {
        count_sort(arr, size);
        printf("Sorted array--->\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        printf("Invalid input!");
    }
    return 0;
}