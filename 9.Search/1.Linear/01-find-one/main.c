#include <stdio.h>

int linear_search(int a[], int n, int target)
{
    /*
        1   start at the first element of the array
        2   look at the current element
        3   if the current element equals the target
        4       return its position
        5   move to the next element
        6   repeat steps 2–5 until the end of the array
        7   if the target is not found
        8       return not found
     */
}

int linear_search(int a[], int n, int target)
{
    for (int i = 0; i < n; i++)   // duyệt từ đầu đến cuối mảng
    {
        if (a[i] == target)       // nếu phần tử bằng target
        {
            return i;             // trả về vị trí tìm thấy
        }
    }
    return -1; // nếu không tìm thấy, trả về -1
}

int main()
{
    int a[] = {4, 2, 7, 1, 9, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 7;

    int result = linear_search(a, n, target);

    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}