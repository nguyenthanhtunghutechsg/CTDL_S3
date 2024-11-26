#include <stdio.h>
#include <stdlib.h>

typedef struct DonThuc {
    int CoSo;
    int SoMu;
}DonThuc;
typedef struct Node {
    DonThuc info;
    struct Node *pNext;
}NODE;
typedef NODE* NODEPTR;
void Input(DonThuc &dt) {
    scanf("%d%d", &dt.CoSo, &dt.SoMu);
}
void Output(DonThuc dt) {
    printf("(%d)x^%d+", dt.CoSo,dt.SoMu);
}

NODEPTR createNode(DonThuc input) {
    NODEPTR newNode = new NODE;
    newNode->info = input;
    newNode->pNext = NULL;
    return newNode;
}
void Insert(NODEPTR &pHead, DonThuc input) {
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
        Output(curret->info);
    }
}
int main() {
    NODEPTR pHead = NULL;
    for (int i = 0; i < 5; ++i) {
        DonThuc dt;
        if(i%2==0) {
            dt.SoMu = i;
            dt.CoSo = i;
        }else {
            dt.SoMu = i;
            dt.CoSo = i*-1;
        }
        Insert(pHead, dt);
    }
    Print(pHead);
    return 0;
}