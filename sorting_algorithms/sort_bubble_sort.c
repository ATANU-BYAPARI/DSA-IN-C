// Bubble sort in ascending order:
// To make the programm adaptive, we can add a checkpoint after each iteration, wheather there is any swaping or not, if not means array is already sorted, in this case we can stop the loop using brake statement.
#include <stdio.h>
int main()
{
    int arr[] = {3, 1, 0, 5, 7, 4, 8};
    int size = 7;

    // array before sorting...
    for (int idx = 0; idx < size; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf(" <--- Array before sorting\n");
    // sorting here...
    for (int i = 0; i < size - 1; i++)
    { // loop will run upto size-1, as when only one element is left there is no one to compare
        printf("Performing %d iteration...\n", i + 1);
        for (int j = 0; j < size - 1 - i; j++)
        { // loop will run upto size-1-i, bcz after each iteration the highest number will be at the last index
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // array after sorting...
    for (int jdx = 0; jdx < size; jdx++)
    {
        printf("%d ", arr[jdx]);
    }
    printf(" <--- Array after sorting\n");
}