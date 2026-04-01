#include <stdio.h>
#include "stack.h"
int main()
{
    Stack s;
    Init(&s);

    printf("Push 1 40\n");
    Push1(&s, 40);

    printf("Push 1 50\n");
    Push1(&s, 50);  
    
    printf("Push 1 -10\n");
    Push1(&s, -10);
    
    printf("Push 1 20\n");
    Push1(&s, 20);  
    
    printf("Push 1 30\n");
    Push1(&s, 30);  
    
    printf("Push 1 -20\n");
    Push1(&s, -20);  

    printf("%d\n", Min(&s));
    Pop1(&s);
    printf("%d\n", Min(&s));
    Pop1(&s);
    printf("%d\n", Min(&s));
    Pop1(&s);
    printf("%d\n", Min(&s));
    Pop1(&s);
    printf("%d\n", Min(&s));
    Pop1(&s);
    printf("%d\n", Min(&s));
    Pop1(&s);
    printf("%d\n", Min(&s));
    Pop1(&s);

    Display(&s);

    return 0;
}
