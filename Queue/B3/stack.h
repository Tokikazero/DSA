#pragma one
#include "queue.h"

#define MAX_SIZE 100

// STRUCT Queue
//     INTEGER ARRAY data[MAX_SIZE]     // vùng lưu trữ phần tử
//     INTEGER front                    // head index (chỉ số phần tử đầu)
//     INTEGER rear                     // tail index (chỉ số phần tử cuối)
//     INTEGER size                     // số lượng phần tử hiện tại
// END STRUCT

typedef struct Stack
{
    Queue q1;
    Queue q2;
} Stack;

void InitStack(Stack *s);
int Push(Stack *s, int value);
int Pop(Stack *s);
int PeekStack(Stack *s);
int Size(Stack *s);
int IsEmptyStack(Stack *q);
void DisplayStack(Stack *s);