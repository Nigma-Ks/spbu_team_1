#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct ListElement {
    int value;
    struct ListElement *nextElement;
} ListElement;

typedef struct List {
    struct ListElement *firstElement;
} List;


int ListLength( List *list, size_t *len)
{
    if (list == NULL || len == NULL)
    {
        return -1;
    }
    *len = 0;
    ListElement *currentElement = list->firstElement;
    while (currentElement != NULL)
    {
        ++(*len);
        currentElement = currentElement->nextElement;
    }
    return 0;
}

