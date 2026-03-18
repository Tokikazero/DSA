#pragma one

#include <stdio.h>

#define MAX_SIZE 6

typedef struct Stack
{
    int data[MAX_SIZE];
    int top1;
    int top2;
} Stack;

void Init(Stack *s);
int IsEmpty1(const Stack *s);
int IsEmpty2(const Stack *s);
int IsFull1(const Stack *s);
int IsFull2(const Stack *s);
void Push1(Stack *s, int value);
void Push2(Stack *s, int value);
int Pop1(Stack *s);
int Pop2(Stack *s);
int Peek(const Stack *s);
void Display(Stack *s);

