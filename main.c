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

// Inserts <value> into <list> at <index> position
// Error codes: 
// 0 = successfully inserted elements
// -1 = list is NULL 
// -2 = error allocating memory 
// -3 = given index more than length of list
int insertByIndex(List *list, size_t index, int value)
{
    if (list == NULL)
    {
        return -1;
    }

    if (index == 0)
    {
        ListElement *newElement = calloc(1, sizeof(ListElement));
        if (newElement == NULL)
        {
            return -2;
        }

        newElement->value = value;
        newElement->nextElement = list->firstElement;
        list->firstElement = newElement;

        return 0;
    }

    index--;
    ListElement *currentElement = list->firstElement;
    while (index-- && currentElement != NULL)
    {
        currentElement = currentElement->nextElement;
    }

    if (currentElement == NULL)
    {
        return -3;
    }

    ListElement *newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return -2;
    }

    newElement->value = value;
    newElement->nextElement = currentElement->nextElement;
    currentElement->nextElement = newElement;
    return 0;
}


