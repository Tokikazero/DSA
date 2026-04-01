## **Bài 3: arrayReverse()**

### **Mục tiêu:**

Đảo ngược thứ tự các phần tử trong mảng ban đầu.
Ví dụ: `[1, 2, 3, 4] => [4, 3, 2, 1]`.

### **Pseudocode:**

```
Procedure arrayReverse(arr: Array)
    left <- 0
    right <- arr.size - 1

    While left < right Do
        // Hoán đổi hai phần tử
        temp <- arr.items[left]
        arr.items[left] <- arr.items[right]
        arr.items[right] <- temp

        left <- left + 1
        right <- right - 1
    EndWhile
EndProcedure
```

### **Ví dụ minh họa:**

```
arr = [1, 2, 3, 4]

Bước 1: Hoán đổi arr[0] và arr[3] => [4, 2, 3, 1]
Bước 2: Hoán đổi arr[1] và arr[2] => [4, 3, 2, 1]

Kết quả: [4, 3, 2, 1]
```

### **Phân tích độ phức tạp:**

- **Thời gian:** O(n) (mỗi phần tử được hoán đổi một lần).
- **Không gian:** O(1) (hoán đổi tại chỗ, không dùng thêm bộ nhớ phụ).
