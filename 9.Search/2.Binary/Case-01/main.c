#include <stdio.h>

int binary_search(int a[], int n, int target)
{
    /*
        1   start in the middle of the array
        2   look at the middle element
        3   if the middle element is the target
        4       return its position
        5   else if the target is smaller than the middle element
        6       search the left half
        7   else if the target is greater than the middle element
        8       search the right half
        9   repeat until the target is found or no elements remain
        10  if no elements remain
        11      return not found
    */
}

int binary_search(int a[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // tránh tràn số

        if (a[mid] == target)
            return mid;                   // tìm thấy, trả về vị trí

        else if (a[mid] > target)
            high = mid - 1;               // target nhỏ hơn, tìm bên trái

        else
            low = mid + 1;                // target lớn hơn, tìm bên phải
    }

    return -1; // không tìm thấy
}

int main()
{
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 9;

    int result = binary_search(a, n, target);

    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}