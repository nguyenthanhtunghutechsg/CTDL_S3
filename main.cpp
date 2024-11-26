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

void InsertTail(NODEPTR &pHead, int input) {
    if(pHead == NULL) {
        Insert(pHead, input);
    }
    NODEPTR current = pHead;
    while (current->pNext != NULL) {
        current = current->pNext;
    }
    current->pNext = createNode(input);
}

void InsertPositionK(NODEPTR &pHead, int input,
    int position) {
    if (pHead == NULL) {
        Insert(pHead, input);
        return;
    }
    NODEPTR current = pHead;
    int i = 0;
    while (i < position && current->pNext != NULL) {
        current = current->pNext;
    }
    if(i<position) {
        InsertTail(pHead, input);
        return;
    }
    NODEPTR newNode = createNode(input);
    newNode->pNext = current->pNext;
    current->pNext = newNode;
}
void RemoveHead(NODEPTR &pHead) {
    if (pHead == NULL||pHead->pNext == NULL) {
        pHead = NULL;
        return;
    }
    NODEPTR current = pHead;
    pHead = pHead->pNext;
    delete current;
}
void RemoveTail(NODEPTR &pHead) {
    if (pHead == NULL||pHead->pNext == NULL) {
        pHead = NULL;
        return;
    }
    NODEPTR current = pHead;
    while (current->pNext->pNext != NULL) {
        current = current->pNext;
    }
    current->pNext = NULL;
}
//
void Sort(NODEPTR &pHead) {
    for (NODEPTR i = pHead; i->pNext!=NULL; i=i->pNext) {
        for (NODEPTR j = i->pNext; j!=NULL; j=j->pNext) {
            if(i->info > j->info) {
                int temp = j->info;
                j->info = i->info;
                i->info = temp;
            }
        }
    }
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