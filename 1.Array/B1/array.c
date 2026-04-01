#include <stdio.h>
#include "Library/ArrayUtils.h"

int main(int argc, char const *argv[])
{
    Array arr1;
    int n = 0;
    printf("Max Capacity of Array: ");
    scanf("%d", &n);
    InitArray(&arr1, n);

    AddElement(&arr1, 3);
    AddElement(&arr1, 7);
    AddElement(&arr1, 2);
    AddElement(&arr1, 9);
    AddElement(&arr1, 5);

    printf("\n");

    ArrayDisplay(arr1);

    printf("\n");

    printf("Max = %d", ArrayMax(arr1));

    free(arr1.items);
    return 0;
}

