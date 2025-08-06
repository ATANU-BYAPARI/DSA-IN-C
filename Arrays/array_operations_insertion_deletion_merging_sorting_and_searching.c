// write a c program to perform all basic operations on an array such as insertion, deletion, merging, searching, and sorting
#include <stdio.h>
#include <stdlib.h>
void sorting(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] >= arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int k = 0; k < size; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("<---- sorted array\n");
}
void searching(int *arr, int find, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == find)
        {
            printf("%d found at index %d!\n", find, i);
            return;
        }
    }
    printf("%d is not found!\n", find);
    return;
}
void merging()
{
    int x;
    int size_of_array_1;
    int size_of_array_2;
    printf("Enter size of array 1: ");
    scanf("%d", &size_of_array_1);
    printf("Enter size of array 2: ");
    scanf("%d", &size_of_array_2);
    int arr[size_of_array_1];
    int brr[size_of_array_2];
    printf("Enter the elements of array 1: \n");
    for (int i = 0; i < size_of_array_1; i++)
    {
        printf("Element %d :", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the elements of array 2: \n");
    for (int j = 0; j < size_of_array_2; j++)
    {
        printf("Element %d :", j + 1);
        scanf("%d", &brr[j]);
    }

    int crr[size_of_array_1 + size_of_array_2];
    for (x = 0; x < size_of_array_1; x++)
    {
        crr[x] = arr[x];
    }
    for (int y = x; y < size_of_array_1 + size_of_array_2; y++)
    {
        crr[y] = brr[y - size_of_array_1];
    }
    for (int l = 0; l < size_of_array_1 + size_of_array_2; l++)
    {
        printf("%d ", crr[l]);
    }
    printf("<-----Merged array\n");
}
void deletion(int *arr, int idx, int size)
{
    int l;
    int *brr = (int *)malloc((size - 1) * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("<----array before deletion\n");
    for (l = 0; l < idx; l++)
    {
        brr[l] = arr[l];
    }
    l++;
    for (int k = l; k < (size); k++)
    {
        brr[k - 1] = arr[k];
    }
    for (int x = 0; x < size - 1; x++)
    {
        printf("%d ", brr[x]);
    }
    printf("<----array after deletion\n");
    free(brr);
}
void insertion(int *arr, int key, int pos, int size)
{
    int i;
    for (int j = 0; j < size; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("<----Array before insertion\n");
    int *brr = (int *)malloc((size + 1) * sizeof(int));
    for (i = 0; i < pos; i++)
    {
        brr[i] = arr[i];
    }
    brr[i] = key;
    i++;
    for (int k = i; k < size + 1; k++)
    {
        brr[k] = arr[k - 1];
    }
    for (int l = 0; l < size + 1; l++)
    {
        printf("%d ", brr[l]);
    }
    printf("<----Array after insertion\n");
    free(brr);
}
int main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Element %d :", i + 1);
        scanf("%d", &arr[i]);
    }
    int choice;
    fflush(stdin);
    printf("For insertion: 1\nFor deletion: 2\nFor Merging: 3\nFor Searching: 4\nFor Sorting: 5\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        // insertion
        printf("Enter the number to be inserted: ");
        int key;
        scanf("%d", &key);
        printf("Enter the index where the number will be inserted: ");
        int pos;
        scanf("%d", &pos);
        if (pos < 0 || pos > n + 1)
        {
            printf("Invalid location!");
            exit(1);
        }
        else
        {
            insertion(arr, key, pos, n);
        }
    }
    break;
    case 2:
    {
        // deletion
        printf("Enter the index to be deleted: ");
        int idx;
        scanf("%d", &idx);
        if (idx < 0 || idx >= n)
        {
            printf("Invalid location!");
            exit(2);
        }
        else
        {
            deletion(arr, idx, n);
        }
    }
    break;
    case 3:
    {
        // merging
        merging();
    }
    break;
    case 4:
    {
        // searching
        int find;
        printf("Enter the number to be searched: ");
        scanf("%d", &find);

        searching(arr, find, n);
    }
    break;
    case 5:
    {
        // sorting
        sorting(arr, n);
    }
    break;
    }
}