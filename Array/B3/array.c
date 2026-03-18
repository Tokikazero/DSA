#include <stdio.h>
#include "Library/ArrayUtils.h"

int main(int argc, char const *argv[])
{
    Array arr1;
    InitArray(&arr1, 4); 

    AddElement(&arr1, 1);
    AddElement(&arr1, 2);
    AddElement(&arr1, 3);
    AddElement(&arr1, 4);

    printf("\n");
    
    ArrayReverse(&arr1);
    ArrayDisplay(arr1);

    free(arr1.items);
    return 0;
}

