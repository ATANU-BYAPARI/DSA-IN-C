#include <stdio.h>
int main()
{
    int arr[] = {3,0, 1, 0, 5,-1, 7, 4, 8};
    int size = 9;

    // array before sorting...
    for (int idx = 0; idx < size; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf(" <--- Array before sorting\n");

    // performing selection sort
    for (int i = 0; i < size - 1; i++)
    {
        int idx_chk=i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[idx_chk])
            {
                idx_chk=j; // tracing the minumum index
            }
        }
        //swapping, if minimum index changes
        if(idx_chk!=i){
            int temp=arr[idx_chk];
            arr[idx_chk]=arr[i];
            arr[i]=temp;
        }
    }
    // array after sorting...
    for (int jdx = 0; jdx < size; jdx++)
    {
        printf("%d ", arr[jdx]);
    }
    printf(" <--- Array after sorting\n");
}