#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX_SIZE 100

// STRUCT Stack:
//     INTEGER ARRAY data[MAX_SIZE]     
//     INTEGER top                      
// END STRUCT
typedef struct Stack
{
    int data[MAX_SIZE];
    int top1;
    int top2;
} Stack;

void Init(Stack *s);
int IsEmpty1(const Stack *s);
int IsFull1(const Stack *s);
void Push1(Stack *s, int value);
void Push2(Stack *s, int value);
int Pop1(Stack *s);
int Pop2(Stack *s);
int Peek(const Stack *s);
void Display(Stack *s);

int Min(const Stack *s);

#endif
