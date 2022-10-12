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


bool testInsertById1()
{
    int errorCode = insertByIndex(NULL, 2, 1);
    return errorCode == -1;
}

bool testInsertById2()
{
    List *list = calloc(1, sizeof(List));
    int errorCode = insertByIndex(list, 2, 1);

    ListElement *a = list->firstElement,
                *b = NULL;
    while (a != NULL)
    {
        b = a->nextElement;
        free(a);
        a = b;
    }
    free(list);

    return errorCode == -3;
}

bool testInsertById3()
{
    bool testResult = true;

    List *list = calloc(1, sizeof(List));
    int errorCode1 = insertByIndex(list, 0, 4);
    int errorCode2 = insertByIndex(list, 1, 7);
    int errorCode3 = insertByIndex(list, 0, 12);
    if (errorCode1 != 0 || errorCode2 != 0 || errorCode3 != 0)
    {
        ListElement *a = list->firstElement,
                    *b = NULL;
        while (a != NULL)
        {
            b = a->nextElement;
            free(a);
            a = b;
        }
        free(list);

        return false;
    }

    ListElement *currentElement = list->firstElement;
    if (currentElement->value != 12)
    {
        testResult = false;
    }

    currentElement = currentElement->nextElement;
    if (currentElement->value != 4)
    {
        testResult = false;
    }

    currentElement = currentElement->nextElement;
    if (currentElement->value != 7)
    {
        testResult = false;
    }

    ListElement *a = list->firstElement,
                *b = NULL;
    while (a->nextElement != NULL)
    {
        b = a->nextElement;
        free(a);
        a = b;
    }
    free(list);

    return testResult;
}

int main() {
    printf("Results of tests insertion func: 1: %d, 2: %d, 3: %d", testInsertById1(), testInsertById2(), testInsertById3());
}