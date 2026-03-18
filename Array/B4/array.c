#include <stdio.h>
#include "Library/ArrayUtils.h"

int main(int argc, char const *argv[])
{
    Array arr1;
    InitArray(&arr1, 4); 

    AddElement(&arr1, 10);
    AddElement(&arr1, 20);
    AddElement(&arr1, 30);
    AddElement(&arr1, 40);
    AddElement(&arr1, 50);
    AddElement(&arr1, 60);

    printf("\n");
    
    ArrayInsertAt(&arr1, 25, 2);
    ArrayDisplay(arr1);

    free(arr1.items);
    return 0;
}

