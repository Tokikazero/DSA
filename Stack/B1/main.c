#include <stdio.h>
#include "stack.h"
int main()
{
    Stack s;
    Init(&s);

    printf(" %s ", IsEmpty1(&s) ? "Empty" : "Not Empty");
    printf(" %s ", IsEmpty2(&s) ? "Empty" : "Not Empty");

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
    Push2(&s, 30);
    // Display(&s);

    // printf("Peek: %d\n", Peek(&s));
    // Display(&s);

    
    // printf("Peek: %d\n", Peek(&s));
    // Display(&s);
    
    // printf("Pop: %d\n", Pop(&s));
    // printf("Pop: %d\n", Pop(&s));
    
    // printf("Pop (empty): %d\n", Pop(&s));
    
    Display(&s);
    
    printf("Pop 1: %d\n", Pop1(&s));
    printf("Pop 2: %d\n", Pop2(&s));

    Display(&s);

    return 0;
}
