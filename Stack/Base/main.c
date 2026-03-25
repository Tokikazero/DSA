#include <stdio.h>
#include "stack.h"
int main()
{
    Stack s;
    Init(&s);

    printf("Push 10\n");
    Push(&s, 10);

    printf("Push 20\n");
    Push(&s, 20);

    printf("Push 30\n");
    Push(&s, 30);

    Display(&s);

    printf("Peek: %d\n", Peek(&s));
    Display(&s);

    printf("Pop: %d\n", Pop(&s));
    Display(&s);

    printf("Peek: %d\n", Peek(&s));
    Display(&s);

    printf("Pop: %d\n", Pop(&s));
    printf("Pop: %d\n", Pop(&s));

    printf("Pop (empty): %d\n", Pop(&s));

    Display(&s);

    return 0;
}
