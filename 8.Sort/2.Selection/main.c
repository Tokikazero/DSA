#include <stdio.h>

void selection_sort(int a[], int n)
{
    /*
        1   start at the first element of the array
        2   assume this element is the smallest
        3   compare it with the next element
        4   if the next element is smaller
        5       update the smallest element
        6   move to the next element
        7   repeat steps 3–6 until the end of the array
        8   swap the first element with the smallest element found
        9   move to the next position in the array
        10  repeat steps 2–9 for the remaining unsorted elements
        11  stop when all elements are sorted
    */
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // giả sử phần tử hiện tại là nhỏ nhất

        // tìm phần tử nhỏ nhất trong đoạn còn lại
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j; // cập nhật chỉ số nhỏ nhất
            }
        }

        // hoán đổi phần tử nhỏ nhất với phần tử đầu của đoạn
        if (minIndex != i)
        {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);
    print_array(a, n);

    return 0;
}