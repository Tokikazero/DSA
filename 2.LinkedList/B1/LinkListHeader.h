#pragma one

typedef struct Node
{
    int value;
    struct Node *next;
} Node; 

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    int size;
} LinkedList;

Node *CreateNode(int value);
LinkedList *CreateList();

void PrintList(LinkedList *list);

void AddFirst(LinkedList *list, int value);
void AddLast(LinkedList *list, int value);
int RemoveFirst(LinkedList *list,int* outValue);
int RemoveLast(LinkedList* list,int* outValue);
int InsertAt(LinkedList *list, int index, int value);
int RemoveAt(LinkedList *list, int index, int *outValue);

int IsEmpty(LinkedList* list);
int Size(LinkedList *list);
int IndexOf(LinkedList *list, int value);
int Contains(LinkedList *list, int value);

Node *GetNodeAt(LinkedList *list, int index);
Node *GetPrevious(LinkedList *list, Node *target);
int *ToArray(LinkedList* list,int* outSize);

void Reverse(LinkedList *list);

void Clear(LinkedList *list);