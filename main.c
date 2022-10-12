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

bool testForLength()
{
    bool testResult = false;
    ListElement* lastPointer = NULL;
    ListElement a = {10, lastPointer};
    ListElement b = {9, &a};
    List list = {&b};
    size_t len = 0;
    int errorCode = ListLength(&list, &len);
    if (errorCode == 0)
    {  
        if (len != 2)
        {
            return testResult;
        }
        testResult = true;
    }
    return testResult;
}

int main()
{
    printf("%d", testForLength());
    return 0;
}
