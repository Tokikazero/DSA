#include "Stack.h"

// Hàm khởi tạo Empty Stack 

// FUNCTION init(s: Stack*):
//     s.top <- -1
// END FUNCTION
void Init(Stack *s)
{
    s->top = -1;
}

// Kiểm tra có rỗng không ?

// FUNCTION isEmpty(s: Stack*):
//     RETURN (s.top = -1)
// END FUNCTION
int IsEmpty(const Stack *s)
{
    return s->top == -1;
}

// Kiểm tra stack đã full hay chưa

// FUNCTION isFull(s: Stack*):
//     RETURN (s.top = MAX_SIZE - 1)
// END FUNCTION
int IsFull(const Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// Đẩy phần tử vào stack (push)

// FUNCTION push(s: Stack*, value: INTEGER):
//     IF isFull(s) THEN
//         OUTPUT "Stack overflow"
//         RETURN
//     END IF

//     s.top ← s.top + 1
//     s.data[s.top] ← value
// END FUNCTION
void Push(Stack *s, int value)
{
    if (IsFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }

    s->data[++s->top] = value;
}

// Lấy phần tử khỏi stack (pop)

// FUNCTION pop(s: Stack*):
//     IF isEmpty(s) THEN
//         OUTPUT "Stack underflow"
//         RETURN -1
//     END IF

//     temp ← s.data[s.top]
//     s.top ← s.top - 1

//     RETURN temp
// END FUNCTION
int Pop(Stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack Underflow");
        return -1;
    }

    return s->data[s->top--];
}

// Xem phần tử đỉnh stack (peek)

// FUNCTION peek(s: Stack*):
//     IF isEmpty(s) THEN
//         OUTPUT "Stack empty"
//         RETURN -1
//     END IF

//     RETURN s.data[s.top]
// END FUNCTION
int Peek(const Stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack Empty");
        return -1;
    }

    return s->data[s->top];
}

// Hiển thị stack từ đáy đến đỉnh

// FUNCTION display(s: Stack*):
//     IF isEmpty(s) THEN
//         OUTPUT "Stack is empty."
//         RETURN
//     END IF

//     OUTPUT "Stack (bottom -> top): [ "

//     FOR i ← 0 TO s.top DO
//         OUTPUT s.data[i]
//     END FOR

//     OUTPUT "]"
// END FUNCTION
void Display(Stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack Empty");
        return;
    }
    
    printf("Stack (bottom -> top) [");
    
    for (size_t i = 0;;)
    {
        if (i <= s->top) break;
        printf("%d", s->data[i]);
        i++;
    }

    printf("]");
}

