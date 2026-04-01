#include "LinkListHeader.h"
#include <stdio.h>
#include <malloc.h>

Node *CreateNode(int value)
{
    Node *node = malloc(sizeof(Node));
    
    node->value = value;
    node->next = NULL;
    
    return node;
}

LinkedList *CreateList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
  
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
  
    return list;
}

void PrintList(LinkedList *list)
{
    Node *current = list->head;
    
    while (current != NULL)
    {                   
        printf("%d -> ", current->value);
        current = current->next; 
    }
    printf("NULL\n"); 
}

void AddFirst(LinkedList *list, int value)
{
    Node *node = CreateNode(value);
    
    if (IsEmpty(list) == 1)
    {
        list->head = node;
        list->tail = node;
        list->size = list->size + 1;
        return;
    }
    node->next = list->head;
    list->head = node;
    list->size = list->size + 1;
}

void AddLast(LinkedList *list, int value)
{
    Node *node = CreateNode(value);
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
        list->size++;
        return;
    }
    
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

int RemoveFirst(LinkedList *list, int* outValue)
{
    if (IsEmpty(list) == 1)
    {
        return 0;
    }
    if (list->head == list->tail)
    {
        Node *only = list->head;
        if (outValue != NULL)
        {
            *outValue = only->value;
        }

        list->head = NULL;
        list->tail = NULL;
        free(only);
        list->size = list->size - 1;
        return 1;
    }
    Node *first = list->head;
    Node *second = first->next;

    if (outValue != NULL)
    {
        *outValue = first->value;
    }
    first->next = NULL;
    list->head = second;
    free(first);
    list->size = list->size -1;
    
    return 1;
}

int RemoveLast(LinkedList *list, int *outValue)
{
    if (IsEmpty(list) == 1)
    {
        return 0;
    }
    if (list->head == list->tail)
    {
        Node*only = list->head;
        if (outValue != NULL)
        {
            *outValue = only->value;
        }
        list->head = NULL;
        list->tail = NULL;
        free(only);
        list->size = list->size - 1;
        
        return 1;
    }
    Node *prev = GetPrevious(list, list->tail);
    Node *last = list->tail;

    if (prev == NULL)
    {
        return 0;
    }
    if (outValue != NULL)
    {
        *outValue = last->value;
    }
    prev->next = NULL;
    list->tail = prev;
    
    free(last);
    list->size = list->size - 1;
    return 1;
}

int InsertAt(LinkedList *list, int index, int value)
{
    if (list == NULL)
    {
        return 0;
    }
    if (index < 0 || index > list->size)
    {
        return 0;
    }
    if (index == 0)
    {
        AddFirst(list, value);
        return 1;
    }
    if (index == list->size)
    {
        AddLast(list, value);
        return 1;
    }
    Node *prev = GetNodeAt(list, index - 1);

    if (prev == NULL)
    {
        return 0;
    }
    Node *newNode = CreateNode(value);

    newNode->next = prev->next;
    prev->next = newNode;

    if (newNode->next == NULL)
    {
        list->tail = newNode;
    }
    list->size++;

    return 1;
}

int RemoveAt(LinkedList *list, int index, int *outValue)
{
    if (list == NULL)
    {
        return 0;
    }
    if (list->size == 0)
    {
        return 0;
    }
    if (index < 0 || index >= list->size)
    {
        return 0;
    }
    if (index == 0)
    {
        return RemoveFirst(list, outValue);
    }
    if (index == list->size - 1)
    {
        return RemoveLast(list, outValue);
    }
    Node *prev = GetNodeAt(list, index - 1);

    if (prev == NULL || prev->next == NULL)
    {
        return 0;
    }
    Node *target = prev->next;

    if (outValue != NULL)
    {
        *outValue = target->value;
    }
    prev->next = target->next;

    if (target == list->tail)
    {
        list->tail = prev;
    }
    target->next = NULL;
    free(target);
    list->size--;

    return 1;
}



int IsEmpty(LinkedList *list)
{
    if (list->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Size(LinkedList *list)
{
    return list->size;
}

int IndexOf(LinkedList *list, int value)
{
    Node *current = list->head;
    int index = 0;

    while (current != NULL)
    {
        if (current->value == value)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

int Contains(LinkedList *list, int value)
{
    if (IndexOf(list, value) != -1)
    {
        return 1;
    }
    else    
    {
        return 0;
    }
}



Node *GetNodeAt(LinkedList *list, int index)
{
    if (list == NULL || list->size == 0)
    {
        return NULL;
    }
    if (index < 0 || index >= list->size)
    {
        return NULL;
    }
    Node *current = list->head;
    int i = 0;

    while (i < index)
    {
        current = current->next;
        i++;
    }
    return current;
}

Node *GetPrevious(LinkedList *list, Node *target)
{
    if (IsEmpty(list) == 1 || list->head == target)
    {
        return NULL;
    }
    Node* current = list->head;

    while (current != NULL && current->next != target)
    {
        current = current->next;
    }
    return current;
}

int *ToArray(LinkedList *list, int *outSize)
{
    if (outSize != NULL)
    {
        *outSize = 0;
    }
    if (list == NULL || list->size == 0)
    {
        return NULL;
    }

    int n = list->size;
    int *a = (int*) malloc(n * sizeof(int));
    if (a == NULL)
    {
        return NULL;
    }
    
    Node* cur = list->head;
    for (int i = 0; i < n ; i++)
    {
        a[i] = cur->value;
        cur = cur->next;
    }
    if (outSize != NULL)
    {
        *outSize = n;
    }
    return a;
}



void Reverse(LinkedList *list)
{
    if (list->head == NULL || list->head->next == NULL)
        return;

    Node *prev = NULL;
    Node *current = list->head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->tail = list->head;
    list->head = prev;
}



void Clear(LinkedList *list)
{
    if (list == NULL)
    {
        return;
    }
    Node *current = list->head;

    while (current != NULL)
    {
        Node *nextNode = current->next;

        current->next = NULL;
        free(current);

        current = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}