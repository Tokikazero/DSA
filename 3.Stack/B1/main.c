#include <stdio.h>
#include "stack.h"
int main()
{
    Stack s;
    Init(&s);

    printf(" %s ", IsEmpty1(&s) ? "Is Empty" : "Not Empty");
    printf(" %s ", IsEmpty2(&s) ? "Is Empty" : "Not Empty");
    printf(" %s ", IsFull1(&s) ? "Is Full" : "Not Empty");
    printf(" %s ", IsFull2(&s) ? "Is Full" : "Not Empty");

    printf("Push 1 10\n");
    Push1(&s, 10);
    printf("Push 2 10\n");
    Push2(&s, 10);
    
    printf("Push 1 20\n");
    Push1(&s, 20);
    printf("Push 2 20\n");
    Push2(&s, 20);

    printf("Push 1 30\n");
    Push1(&s, 30);  
    printf("Push 2 30\n");
    Push2(&s, 30);
    
    printf("Push 1 30\n");
    Push1(&s, 30);  
    printf("Push 2 30\n");
    
    Display(&s);
    
    printf("Pop 1: %d\n", Pop1(&s));
    printf("Pop 2: %d\n", Pop2(&s));

    Display(&s);

    return 0;
}
