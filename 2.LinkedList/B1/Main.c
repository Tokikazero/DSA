#include "LinkListHeader.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // 1.Tạo list
    printf("\n1.Tạo list\n");
    LinkedList *list = CreateList();

    // 2.Thêm node
    printf("\n2.Thêm node\n");
    AddLast(list,10);
    AddLast(list,20);
    AddLast(list,30);
    AddLast(list,40);
    AddLast(list,50);
    
    // 3.In list
    printf("\n3.In list\n");
    printf("Link List: ");
    PrintList(list);

    // 4.Kiểm tra rỗng
    printf("\n4.Kiểm tra rỗng\n");
    printf("Mảng rỗng: %s", IsEmpty(list) ? "True" : "False");

    // 5.Số lượng phần tử
    printf("\n5.Số lượng phần tử\n");
    Size(list);
    printf("\nNumbers of node in list : %d\n",list->size);

    // 6.Thêm vào đầu danh sách
    printf("\n6.Thêm vào đầu danh sách\n");
    AddFirst(list, 20);
    printf("Link List: ");
    PrintList(list);

    // 7.Đảo ngược list
    printf("\n7.Đảo ngược list\n");
    printf("Before reverse: ");
    PrintList(list);
    Reverse(list);
    printf("After reverse: ");
    PrintList(list);

    // 8.Index của "value"
    printf("\n8.Index của 40\n");
    printf("index: %d\n",IndexOf(list, 40));

    // 9.List có tồn tại "value" hay không ?
    printf("\n9.List có tồn tại 30 hay không ?\n");
    printf("Contain 30: %s\n",Contains(list, 30) ? "True" : "False");

    // 10.Xóa phần tử đầu
    printf("\n10.Xóa phần tử đầu\n");
    int removedValue;
    if(RemoveFirst(list, &removedValue))
    {
        printf("Removed first node: %d\n", removedValue);
    }
    printf("Link List after remove: ");
    PrintList(list);

    // 11.Thêm phần tử
    printf("\n11.Thêm phần tử 72 vào đầu\n");
    AddFirst(list, 72);
    printf("List after insert: ");
    PrintList(list);
    
    // 12.Tìm Node phía trước
    printf("\n12.Tìm Node phía trước Node(list->tail)\n");
    printf("Size: %d\n", list->size);
    Node *prev = GetPrevious(list, list->tail);

    if(prev != NULL)
    {
        printf("Previous value: %d\n", prev->value);
    }
    else
    {
        printf("No previous node\n");
    }

    // 13.Xóa phần tử cuối
    printf("\n13.Xóa phần tử cuối\n");
    int value;
    if(RemoveLast(list, &value))
    {
        printf("Removed Last: %d\n", value);
    }
    else
    {
        printf("Remove failed\n");
    }
    PrintList(list);

    // 14.Chuyển về Array
    printf("\n14.Chuyển về Array\n");
    int size;
    int *arr = ToArray(list, &size);
    if(arr != NULL)
    {
        printf("Array: ");
        for(int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr); 
    }
    
    // 15.Lấy giá trị của Node ở "Index"
    printf("\n15.Lấy giá trị của Node ở vị trí 2\n");
    Node *node = GetNodeAt(list, 2);
    
    if (node != NULL)
    {
        printf("Value at index 2: %d\n", node->value);
    }
    else
    {
        printf("Index is not valid\n");
    }
     
    // 16.Thêm "Value" tại "Index"
    printf("\n16.Thêm \"Value\" tại vị trí 2\n");
    if(InsertAt(list, 2, 19))
    {
        printf("Insert success\n");
    }
    else
    {
        printf("Insert failed\n");
    }
    PrintList (list);

    // 17.Xóa "Value" tại "Index"
    printf("\n17.Xóa \"Value\" tại vị trí 2\n");
    if(RemoveAt(list, 2, &removedValue))
    {
        printf("Removed value: %d\n", removedValue);
    }
    else
    {
        printf("Remove failed\n");
    }
    PrintList (list);

    // 18.Xóa List
    printf("\n18.Xóa List\n");
    printf("Before clear:\n");
    PrintList(list);

    Clear(list);

    printf("After clear:\n");
    PrintList(list);

    printf("Size: %d\n", list->size);

    return 0;
}