
typedef struct ListElement {
    int value;
    struct ListElement *nextElement;
} ListElement;

typedef struct List {
    struct ListElement *firstElement;
} List;

