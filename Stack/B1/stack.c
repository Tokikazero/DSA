#include <stdio.h>
#include "Stack.h"

void Init(Stack *s)
{
    s->top1 = -1;
    s->top2 = MAX_SIZE;
}

int IsEmpty1(const Stack *s)
{
    return s->top1 == -1;
}
int IsEmpty2(const Stack *s)
{
    return s->top2 == MAX_SIZE; 
}

int IsFull1(const Stack *s)
{
    return s->top1 == s->top2 - 1;
}
int IsFull2(const Stack *s)
{
    return s->top2 == s->top1 + 1;
}

void Push1(Stack *s, int value)
{
    if (IsFull1(s))
    {
        printf("Stack 1 Overflow\n");
        return;
    }

    s->data[++s->top1] = value;
}
void Push2(Stack *s, int value)
{
    if (IsFull2(s))
    {
        printf("Stack 2 Overflow\n");
        return;
    }

    s->data[--s->top2] = value;
}

int Pop1(Stack *s)
{
    if (IsEmpty1(s))
    {
        printf("Stack 1 Underflow");
        return -1;
    }

    return s->data[s->top1--];
}
int Pop2(Stack *s)
{
    if (IsEmpty2(s))
    {
        printf("Stack 2 Underflow");
        return -1;
    }

    return s->data[s->top2++];
}

void Display(Stack *s)
{
    if (IsEmpty1(s))
    {
        printf("Stack 1 Empty");
        return;
    }
    
    
    printf("Stack 1 (bottom -> top) [");
    
    for (size_t i = 0;;)
    {
        if (i > s->top1) break;
        printf(" %d", s->data[i]);
        i++;
    }

    printf(" ]\n");

    if (IsEmpty2(s))
    {
        printf("Stack 2 Empty");
        return;
    }

    printf("Stack 2 (bottom -> top) [");
    
    for (size_t i = MAX_SIZE - 1;;)
    {
        if (i < s->top2) break;
        printf(" %d", s->data[i]);
        i--;
    }

    printf(" ]");
}

