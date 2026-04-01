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

int IsFull1(const Stack *s)
{
    return s->top1 == s->top2 - 1;
}

void Push1(Stack *s, int value)
{
    if (IsFull1(s))
    {
        printf("Stack 1 Overflow\n");
        return;
    }
    if (IsEmpty1(s) || value < s->data[s->top1])
    {
        Push2(s, value);
    }
    s->data[++s->top1] = value;
}
void Push2(Stack *s, int value)
{
    s->data[--s->top2] = value;
}

int Pop1(Stack *s)
{
    if (IsEmpty1(s))
    {
        printf("Stack 1 Underflow");
        return -1;
    }
    if (s->data[s->top1] == s->data[s->top2])
    {
        Pop2(s);
    }
    return s->data[s->top1--];
}
int Pop2(Stack *s)
{
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
}

int Min(const Stack*s)
{
    if (IsEmpty1(s))
    {
        printf("Stack 1 Empty");
        return -1;
    }

    return s->data[s->top2];
}