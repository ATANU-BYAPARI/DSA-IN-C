// Adaptive bubble sorting algorithm for ascending order...
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;
    bool check;  // checkpoint
    // array before sorting...
    for (int idx = 0; idx < size; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf(" <--- Array before sorting\n");

    for (int i = 0; i < size - 1; i++)
    {
        printf("Performing %d iteration...\n",i+1);
        check=true; // initialization the checkpoint
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                check=false; //updating check point if there is any swapping
            }
        }
        if(check==true){ // checking the checkpoint if matched, break and get out of the loop
            break;
        }
    }

    // array after sorting...
    for (int jdx = 0; jdx < size; jdx++)
    {
        printf("%d ", arr[jdx]);
    }
    printf(" <--- Array after sorting\n");
}