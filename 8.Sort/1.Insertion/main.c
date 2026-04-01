#include <stdio.h>

void insertionSort(int arr[], int n)
{
    /*
        1   start at the second element
        2   pick up the current element as key
        3   compare it with the previous element
        4   if previous element is greater than key
        5       shift it to the right
        6       move to the previous element
        7       go back to step 3
        8   else
        9       insert key in current position
        10  move to the next element
        11  repeat from step 2 until done
        12  stop
    */
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
