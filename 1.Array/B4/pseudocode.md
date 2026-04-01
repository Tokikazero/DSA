## **Bài 4: arrayInsertAt()**

### **Mục tiêu:**

Chèn một phần tử mới vào vị trí chỉ định `index` trong mảng.
Các phần tử phía sau sẽ phải **dịch sang phải** một vị trí.

### **Pseudocode:**

```
Procedure arrayInsertAt(arr: Array, item: integer, index: integer)
    // Kiểm tra chỉ số hợp lệ
    If index < 0 Or index > arr.size Then
        Print "Error: Invalid index"
        Return
    EndIf

    // Nếu mảng đã đầy, mở rộng dung lượng
    If arr.size == arr.capacity Then
        newCapacity <= arr.capacity * 2
        newItems <= new int[newCapacity]

        For i <= 0 To arr.size - 1 Do
            newItems[i] <= arr.items[i]
        EndFor

        arr.items <= newItems
        arr.capacity <= newCapacity
    EndIf

    // Dịch các phần tử sang phải bắt đầu từ cuối mảng
    For i <= arr.size - 1 DownTo index Do
        arr.items[i + 1] <= arr.items[i]
    EndFor

    // Chèn phần tử mới
    arr.items[index] <= item
    arr.size <= arr.size + 1
EndProcedure
```

### **Ví dụ minh họa:**

```
arr = [10, 20, 30, 40]
insert item = 25, index = 2

Trước khi chèn: [10, 20, 30, 40]
Dịch phải:      [10, 20, 30, 30, 40]
Chèn 25 vào vị trí 2 => [10, 20, 25, 30, 40]
```

### **Phân tích độ phức tạp:**

- **Thời gian:** O(n) (dịch phải các phần tử khi chèn không ở cuối).
- **Không gian:** O(1) (trừ khi cần cấp phát lại mảng, khi đó tạm thời O(n)).
