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

int create(List **newList) {
    *newList = (List *) calloc(1, sizeof(List));
    if (newList == NULL) {
        return -2;
    }
    return 0;
}

void freeList(List *list) {
    if (list == NULL) {
        return;
    }
    ListElement *currElement = list->firstElement;
    ListElement *nextCurrElement = list->firstElement;
    while (currElement != NULL) {
        nextCurrElement = currElement->nextElement;
        free(currElement);
        currElement = nextCurrElement;
    }
    list->firstElement = NULL;
}

bool testCreate() {
    List *list = NULL;
    int error = create(&list);
    if (list != NULL) {
        free(list);
        return true;
    }
    free(list);
    return false;
}


int testFree() {
    List *list = NULL;
    int error = create(&list);
    if (error == -2) {
        return -2;
    }
    list->firstElement = malloc(sizeof(ListElement));
    list->firstElement->value = 1;
    ListElement *secondElement = malloc(sizeof(ListElement));
    secondElement->value = 2;
    list->firstElement->nextElement = secondElement;
    secondElement->nextElement = NULL;
    freeList(list);
    if (list->firstElement == NULL) {
        free(list);
        return 0;
    }
    free(list);
    return -1;
}

int main() {
    if (testCreate() && !testFree()) {
        printf("Successful creating and freeing the list\n");
    } else {//-return for merge team's code
        printf("Unsuccessful creating and freeing the list\n");
    }
}
