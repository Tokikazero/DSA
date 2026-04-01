## **Bài 2: arrayIntersect()**

### **Mục tiêu:**

Tìm các phần tử **chung** giữa hai mảng `a1` và `a2` và trả về một mảng mới chứa các phần tử này.

### **Pseudocode:**

```
Function arrayIntersect(a1: Array, a2: Array) -> Array
    // Tạo mảng rỗng kết quả
    result <= new Array
    result.size <= 0
    result.capacity <= min(a1.size, a2.size)
    result.items <= new int[result.capacity]

    // Duyệt qua từng phần tử của mảng a1
    For i <= 0 To a1.size - 1 Do
        x <= a1.items[i]

        // Kiểm tra xem x có tồn tại trong a2 hay không
        For j <= 0 To a2.size - 1 Do
            If x == a2.items[j] Then
                // Kiểm tra tránh thêm trùng lặp vào result
                isDuplicate <= False
                For k <= 0 To result.size - 1 Do
                    If result.items[k] == x Then
                        isDuplicate <= True
                        Break
                    EndIf
                EndFor

                If isDuplicate == False Then
                    result.items[result.size] <= x
                    result.size <= result.size + 1
                EndIf

                Break   // ra khỏi vòng lặp j vì đã tìm thấy
            EndIf
        EndFor
    EndFor

    Return result
EndFunction
```

### **Ví dụ minh họa:**

```
a1 = [1, 2, 3, 5]
a2 = [2, 4, 5, 6]

Kết quả: [2, 5]
```

### **Phân tích độ phức tạp:**

- **Thời gian:** O(n × m) (duyệt lồng nhau qua cả hai mảng).
- **Không gian:** O(min(n, m)) cho mảng kết quả.
