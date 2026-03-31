## **Bài 1: arrayMax()**

### **Hàm: arrayMax()**

**Mục đích:**
Tìm và trả về giá trị lớn nhất trong mảng `arr`.

### **Pseudocode:**

```
Function arrayMax(arr: Array) -> integer
    // Nếu mảng rỗng thì báo lỗi hoặc trả giá trị mặc định
    If arr.size == 0 Then
        Print "Error: Array is empty"
        Return giá trị đặc biệt báo lỗi
    EndIf

    // Giả sử phần tử đầu tiên là lớn nhất ban đầu
    maxValue <= arr.items[0]

    // Duyệt qua toàn bộ các phần tử còn lại trong mảng
    For i <= 1 To arr.size - 1 Do
        If arr.items[i] > maxValue Then
            maxValue <= arr.items[i]
        EndIf
    EndFor

    // Trả về giá trị lớn nhất
    Return maxValue
EndFunction
```

### **Ví dụ minh họa:**

```
Input:
    arr = [3, 7, 2, 9, 5]

Tiến trình:
    maxValue = 3
    So sánh 7 > 3 => maxValue = 7
    So sánh 2 < 7 => không đổi
    So sánh 9 > 7 => maxValue = 9
    So sánh 5 < 9 => không đổi

Output:
    9
```

### **Phân tích độ phức tạp:**

- **Thời gian:** `O(n)` – duyệt qua toàn bộ n phần tử.
- **Không gian:** `O(1)` – chỉ dùng một biến tạm `maxValue`.
