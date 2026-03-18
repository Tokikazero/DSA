#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *items;      // con trỏ trỏ tới vùng nhớ chứa các phần tử
    int size;        // số lượng phần tử hiện có trong mảng
    int capacity;    // dung lượng tối đa của mảng (số phần tử có thể chứa)
} Array;

// void ArrayInitialize(Array *arr)
// {
//     printf("Max Capacity of Array: ");
//     scanf("%d", &arr->capacity);
//     arr->size = 0;
//     arr->items = (int*)malloc(arr->capacity * sizeof(int));
//     if (arr->items == NULL)
//     {
//         printf("Memory allocation failed!\n");
//         exit(1);
//     }
// }

// void ArrayInput(Array *arr)
// {
//     if(arr->capacity == 0)
//     {
//         printf("Max Capacity of Array: ");
//         int n = 0;
//         scanf("%d", n);
//         ArrayInitialize(arr, n);  
//     }
//     int n = 0;
//     while (1)
//     {
//         printf("Number of Element to Input: ");
//         scanf("%d", &n);
//         if(n > -1 && n < arr->capacity) break;
//         printf("Invalid Number of Element to Input!\n");
//     }
//     for (size_t i = 0;;)
//     {
//         if(i >= n) break;
//         {
//             printf("Array[%d]= ", i);
//             scanf("%d", &arr->items[i]);
//             //printf("Array[%d]= %d\n", i, arr->items[i]);
//             ++arr->size;
//         }
//         ++i;
//     }
// }

// int ArrayInitialize(Array *arr, int capacity)
// {
//     // printf("Max Capacity of Array: ");
//     // scanf("%d", &arr->capacity);
//     arr->size = 0;
//     arr->items = (int*)malloc(arr->capacity * sizeof(int));
//     if (arr->items == NULL)
//     {
//         printf("Memory allocation failed!\n");
//         return -1;
//     }
//     return 0;
// }

// int ArrayInput(Array *arr, int inputValue)
// {
//     if (arr->capacity == 0)
//     {
//         printf("Array Capacity is Zero!\n");
//         return -1;
//     }
//     else if (arr->size >= arr->capacity)
//     {
//         printf("Array is Full!\n");
//         return -2;
//     }
//     arr->items[arr->size] = inputValue;
//     return 0;
// }

void InitArray(Array *arr, int capacity)
{
    arr->size = 0;
    arr->capacity = capacity;
    arr->items = (int*)malloc(capacity * sizeof(int));

    if (arr->items == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void AddElement(Array *arr, int inputValue)
{
    if (arr->size >= arr->capacity)
    {
        if (arr->capacity == 0)
            arr->capacity = 1;  
        arr->capacity *= 2;

        int *temp = (int*)realloc(arr->items, arr->capacity * sizeof(int));

        if (temp == NULL)
        {
            printf("Memory Reallocation failed!\n");
            exit(EXIT_FAILURE);
        }

        arr->items = temp;
    }
    arr->items[arr->size] = inputValue;
    arr->size++;
}

void ArrayDisplay(Array arr)
{
    if (arr.size <= 0)
    {
        printf("Array is Empty!");
    }
    for (size_t i = 0;;)
    {
        if(i >= arr.size) break;
        {
            printf("Array[%d]= %d\n", i, arr.items[i]);
        }
        i++;
    }
    return;
}

int ArrayMax(Array arr)
{
    // Time: O(1)
    if (arr.size <= 0)
    {
        printf("Array is empty!");
    }
    // Space: O(1)
    int maxValue = arr.items[0];
    // Time: O(n)
    for (size_t i = 0;;)
    {
        if (i >= arr.size) break;
        {
            if (arr.items[i] > maxValue)
                maxValue = arr.items[i];
        }
        i++;
    }
    return maxValue;
}

Array ArrayIntersect(Array arr1, Array arr2)
{
    // Space: O(min(arr1, arr2))
    Array result;
    (arr1.size > arr2.size) ? InitArray(&result, arr2.size) : InitArray(&result, arr1.size);

    // Time: O(n^2)
    for (size_t i = 0;;)
    {
        if (i >= arr1.size) break;
        {
            for (size_t j = 0;;)
            {
                if (j >= arr1.size) break;
                {
                    if (arr1.items[i] == arr2.items[j])
                    {
                        AddElement(&result, arr1.items[i]);
                        break;
                    }
                }
                j++;
            }                
        }
        i++;
    }
    
    return result;
}

Array ArrayReverse(Array *arr)
{
    // Space: O(1)
    size_t left = 0;
    size_t right = arr->size -1;
    // Time: O(n)
    while (left < right)
    {
        // printf("A %d", left);
        int temp = arr->items[left];
        arr->items[left] = arr->items[right];
        arr->items[right] = temp;
        left++;
        right--;
    }
}

Array ArrayInsertAt(Array *arr, int value, size_t index)
{
    // Space: O(1)
    AddElement(arr, arr->items[arr->size - 1]);
    // for (size_t i = arr->size - 2;;)
    // {
    //     arr->items[i] = arr->items[i-1];
    //     i--;
    //     if(i <= index)
    //     {
    //         arr->items[i] = value;
    //         break;
    //     }
    // }
    size_t i = arr->size - 2;
    // Time: O(n)
    while (i > index)
    {
        arr->items[i] = arr->items[i-1];
        i--;
    }
    arr->items[i] = value;
}