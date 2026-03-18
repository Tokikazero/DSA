#include <stdio.h>
#include "Library/ArrayUtils.h"

int main(int argc, char const *argv[])
{
    Array arr1;
    Array arr2;
    InitArray(&arr1, 4); 

    AddElement(&arr1, 1);
    AddElement(&arr1, 2);
    AddElement(&arr1, 3);
    AddElement(&arr1, 5);
    
    InitArray(&arr2, 4);

    AddElement(&arr2, 2);
    AddElement(&arr2, 4);
    AddElement(&arr2, 5);
    AddElement(&arr2, 6);

    printf("\n");

    ArrayDisplay(ArrayIntersect(arr1, arr2));

    free(arr1.items);
    return 0;
}

