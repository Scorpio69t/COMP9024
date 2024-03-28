#include "IntStack.h"
#include <assert.h>

typedef struct {
    char ITEM[MAXITEM];
    int top;
} stackrep;

static stackrep StackObject;

void StackInit() {
    StackObject.top = -1;
}

int StackIsEmpty() {
    return (StackObject.top < 0);
}

void StackPush(char ch) {
    assert(StackObject.top < MAXITEM-1);
    StackObject.top++;
    int i = StackObject.top;
    StackObject.ITEM[i] = ch;
}

char StackPop() {
    assert(StackObject.top > -1);
    int i = StackObject.top;
    char ch = StackObject.ITEM[i];
    StackObject.top--;
    return ch;
}
