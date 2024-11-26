#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node *pNext;
}NODE;
typedef NODE* NODEPTR;

NODEPTR createNode(int input) {
    NODEPTR newNode = new NODE;
    newNode->info = input;
    newNode->pNext = NULL;
    return newNode;
}
void Insert(NODEPTR &pHead, int input) {
    if (pHead == NULL) {
        pHead = createNode(input);
        return;
    }
    NODEPTR newNode = createNode(input);
    newNode->pNext = pHead;
    pHead = newNode;
}
void Print(NODEPTR pHead) {
    NODEPTR curret = pHead;
    for (; curret!=NULL; curret=curret->pNext) {
        printf("%d\t", curret->info);
    }
}
int main() {
    NODEPTR pHead = NULL;
    Insert(pHead, 1);
    Insert(pHead, 2);
    Insert(pHead, 3);
    Insert(pHead, 4);
    Insert(pHead, 5);
    Print(pHead);
    return 0;
}