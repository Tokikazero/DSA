#pragma one

#define MAX_SIZE 100

// STRUCT Queue
//     INTEGER ARRAY data[MAX_SIZE]     // vùng lưu trữ phần tử
//     INTEGER front                    // head index (chỉ số phần tử đầu)
//     INTEGER rear                     // tail index (chỉ số phần tử cuối)
//     INTEGER size                     // số lượng phần tử hiện tại
// END STRUCT

typedef struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void InitQueue(Queue *q);
int IsEmpty(Queue *q);
int IsFull(Queue *q);
int Enqueue(Queue *q, int value);
int Dequeue(Queue *q, int *removedValue);
int Peek(Queue *q, int *frontValue);
void DisplayQueue(Queue *q);
int Reverd(Queue *q, int k);