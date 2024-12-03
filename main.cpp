#include <future>
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
    if (pHead == NULL) {
        Insert(pHead, input);
        return;
    }
    NODEPTR current = pHead;
    while (current->pNext != NULL) {
        current = current->pNext;
    }
    current->pNext = createNode(input);
}

NODEPTR GetNode(NODEPTR pHead, int k) {
    NODEPTR current = pHead;
    int i = 1;
    while (current != NULL&&i<=k) {
        current = current->pNext;
        i++;
    }
    if (i<k) {
        return NULL;
    }
    return current;
}
void InsertPositionK(NODEPTR &pHead, int input, int k) {
    NODEPTR current = GetNode(pHead, k);
    if(current==NULL) {
        return;
    }

    NODEPTR newNode = createNode(input);
    newNode->pNext = current->pNext;
    current->pNext = newNode;
}
void RemoveHead(NODEPTR &pHead) {
    if (pHead==NULL||pHead->pNext == NULL) {
        pHead==NULL;
        return;
    }
    NODEPTR temp = pHead;
    pHead = pHead->pNext;
    delete temp;
}
void RemoveTail(NODEPTR &pHead) {
    if (pHead==NULL||pHead->pNext == NULL) {
        pHead==NULL;
        return;
    }
    NODEPTR current = pHead;
    while (current->pNext->pNext != NULL) {
        current = current->pNext;
    }
    current->pNext = NULL;
}

void Print(NODEPTR pHead) {
    NODEPTR curret = pHead;
    for (; curret!=NULL; curret=curret->pNext) {
        printf("%d ", curret->info);
    }
}
void RemovePositionK(NODEPTR &pHead, int k) {
    if (k==0) {
        RemoveHead(pHead);
        return;
    }
    NODEPTR current = GetNode(pHead, k-1);
    if (current==NULL) {
        return;
    }
    current->pNext = current->pNext->pNext;
}
void Sort(NODEPTR &pHead) {
    for (NODEPTR i = pHead; i ->pNext!=NULL; i=i->pNext) {
        for (NODEPTR j = i->pNext; j!=NULL; j=j->pNext) {
            if(i->info<j->info) {
                int temp = j->info;
                j->info = i->info;
                i->info = temp;
            }
        }
    }
}
int main() {
    NODEPTR pHead = NULL;
    for (int i = 0; i < 10; i++) {
        InsertTail(pHead, i);
    }
    Print(pHead);
    printf("\n");
    InsertPositionK(pHead, 10, 4);
    Print(pHead);
    printf("\n");
    RemoveHead(pHead);
    Print(pHead);
    printf("\n");
    RemoveTail(pHead);
    Print(pHead);
    printf("\n");
    RemovePositionK(pHead,4);
    Print(pHead);
    printf("\n");
    Sort(pHead);
    Print(pHead);
    return 0;
}
