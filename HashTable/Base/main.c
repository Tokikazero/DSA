#include <stdio.h>
#include "hashtable.h"

int main(void)
{
    HashTable *ht = ht_create(10);

    ht_put(ht, 1, "Marsh");
    ht_put(ht, 2, "John");
    ht_put(ht, 3, "Mary");

    // Overwrite key 3
    ht_put(ht, 3, "MaryAnne");

    printf("Value of key 1: %s\n", ht_get(ht, 1));
    printf("Value of key 2: %s\n", ht_get(ht, 2));
    printf("Value of key 3: %s\n", ht_get(ht, 3));

    printf("Contains key 2? %d\n", ht_containsKey(ht, 2));
    printf("Contains value \"Mary\"? %d\n", ht_containsValue(ht, "Mary"));
    printf("Contains value \"MaryAnne\"? %d\n", ht_containsValue(ht, "MaryAnne"));

    ht_remove(ht, 2);
    printf("After remove key 2, contains key 2? %d\n", ht_containsKey(ht, 2));

    ht_printEntries(ht);
    ht_printKeys(ht);

    ht_destroy(ht);
    return 0;
}
