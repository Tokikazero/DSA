#pragma one

#include <stdio.h>

#define MAX_SIZE 100

// STRUCT Stack:
//     INTEGER ARRAY data[MAX_SIZE]     
//     INTEGER top                      
// END STRUCT
typedef struct Stack
{
    int data[MAX_SIZE];
    int top;
} Stack;

// void init(Stack *s);
// int isEmpty(const Stack *s);
// int isFull(const Stack *s);
// void push(Stack *s, int value);
// int pop(Stack *s);
// int peek(const Stack *s);
// void display(Stack *s);
void Init(Stack *s);
int IsEmpty(const Stack *s);
int IsFull(const Stack *s);
void Push(Stack *s, int value);
int Pop(Stack *s);
int Peek(const Stack *s);
void Display(Stack *s);

