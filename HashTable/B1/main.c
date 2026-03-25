#include <stdio.h>
#include "hashtable.h"

int main(void)
{
    int arr[] = {1,2,2,3,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Most frequent = %d\n", mostFrequent(arr, n));

    return 0;
}
